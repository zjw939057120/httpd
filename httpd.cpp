/*
 * sample http server
 * more detail see examples/httpd
 *
 */

#include "hv.h"
#include <hmain.h>
#include "HttpServer.h"
#include "hthread.h"    // import hv_gettid
#include "hasync.h"     // import hv::async
#include "router.h"
#include "EventLoop.h"

#include "Calibration.h"
#include "CalibrationRouter.h"
#include "MethodList.h"
#include "MethodListRouter.h"
#include "QueueList.h"
#include "QueueListRouter.h"
#include "SampleList.h"
#include "SampleListRouter.h"
#include "SampleData.h"
#include "SampleDataRouter.h"
#include "Configuration.h"
#include "ConfigurationRouter.h"
#include "System.h"
#include "SystemRouter.h"

using namespace hv;

void print_version();

void print_help();

void system_config();

void parse_cmdline(int argc, char **argv);

Calibration m_calibration;
MethodList m_methodList;
QueueList m_queueList;
SampleList m_sampleList;
SampleData m_sampleData;
Configuration m_configuration;
System m_system;

// long options
static const option_t long_options[] = {
        {'h', "help",    NO_ARGUMENT,       "Print this information"},
        {'v', "version", NO_ARGUMENT,       "Print version"},
        {'c', "confile", REQUIRED_ARGUMENT, "Set configure file, default etc/{program}.conf"},
        {'d', "debug",   NO_ARGUMENT,       "Debug mode"},
        {'p', "port",    REQUIRED_ARGUMENT, "Set listen port"}
};

void print_version() {
    printf("%s version %s\n", g_main_ctx.program_name, hv_compile_version());
}

void print_help() {
    char detail_options[1024] = {0};
    dump_opt_long(long_options, ARRAY_SIZE(long_options), detail_options, sizeof(detail_options));
    printf("%s\n", detail_options);
}

void system_config() {
    //设置日志级别
    hlog_set_level(LOG_LEVEL_WARN);
    hlog_set_file("");
    hlog_set_format(DEFAULT_LOG_FORMAT);
    //Debug模式
    m_system.debug = false;
    //服务端口
    m_system.port = 8080;
}

void parse_cmdline(int argc, char **argv) {
    // g_main_ctx
    main_ctx_init(argc, argv);
    int ret = parse_opt_long(argc, argv, long_options, ARRAY_SIZE(long_options));
    if (ret != 0) {
        print_help();
        exit(ret);
    }
    // help
    if (get_arg("h")) {
        print_help();
        exit(0);
    }

    // version
    if (get_arg("v")) {
        print_version();
        exit(0);
    }

    // debug
    if (get_arg("d")) {
        m_system.debug = true;
    }

    const char *szPort = get_arg("p");
    if (szPort) m_system.port = atoi(szPort);
}

/*
 * #define TEST_HTTPS 1
 *
 * @build   ./configure --with-openssl && make clean && make
 *
 * @server  bin/http_server_test 8080
 *
 * @client  curl -v http://127.0.0.1:8080/ping
 *          curl -v https://127.0.0.1:8443/ping --insecure
 *          bin/curl -v http://127.0.0.1:8080/ping
 *          bin/curl -v https://127.0.0.1:8443/ping
 *
 */
#define TEST_HTTPS 0

int main(int argc, char **argv) {
    HV_MEMCHECK;
    //系统配置
    system_config();
    //解析命令行参数
    parse_cmdline(argc, argv);

    HttpService httpService;

    // middleware
    httpService.AllowCORS();
    httpService.Use([](HttpRequest *req, HttpResponse *resp) {
        resp->SetHeader("X-Request-tid", hv::to_string(hv_gettid()));
        return HTTP_STATUS_NEXT;
    });

    // Router::Register(httpService);
    CalibrationRouter::Register(httpService);
    MethodListRouter::Register(httpService);
    QueueListRouter::Register(httpService);
    SampleListRouter::Register(httpService);
    SampleDataRouter::Register(httpService);
    ConfigurationRouter::Register(httpService);
    SystemRouter::Register(httpService);

    HttpServer httpServer;
    httpServer.service = &httpService;
    httpServer.port = m_system.port;
#if TEST_HTTPS
    httpServer.https_port = 8443;
    hssl_ctx_opt_t param;
    memset(&param, 0, sizeof(param));
    param.crt_file = "cert/server.crt";
    param.key_file = "cert/server.key";
    param.endpoint = HSSL_SERVER;
    if (httpServer.newSslCtx(&param) != 0) {
        fprintf(stderr, "new SSL_CTX failed!\n");
        return -20;
    }
#endif

    // uncomment to test multi-processes
    httpServer.setProcessNum(4);
    // uncomment to test multi-threads
    httpServer.setThreadNum(64);

    int ret = httpServer.start();
    if (ret != 0) {
        exit(0);
    }

#ifdef DEBUG_MODE
        printf("http server url is http://127.0.0.1:%d in debug mode \n", m_system.port);
#else
        printf("http server url is http://127.0.0.1:%d \n", m_system.port);
#endif
    //hthread_create(MethodListThread::testThread, NULL);

    auto loop = std::make_shared<EventLoop>();

    loop->setInterval(30000, [](TimerID timerID) {
        printf("time=%lus\n", (unsigned long) time(NULL));
    });
    loop->run();

    return 0;
}
