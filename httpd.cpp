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
#include "Method.h"
#include "MethodRouter.h"
#include "Queue.h"
#include "QueueRouter.h"
#include "Sample.h"
#include "SampleRouter.h"
#include "SampleData.h"
#include "SampleDataRouter.h"
#include "Setting.h"
#include "SettingRouter.h"
#include "System.h"
#include "SystemRouter.h"

using namespace hv;

void print_version();

void print_help();

void system_config();

void parse_cmdline(int argc, char **argv);

Calibration g_calibration;
Method g_method;
Queue g_queue;
Sample g_sample;
SampleData g_sampleData;
Setting g_setting;
System g_system;

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
    hlog_set_level(LOG_LEVEL_INFO);
    //Debug模式
    g_system.debug = false;
    //服务端口
    g_system.port = 8080;
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
        g_system.debug = true;
    }

    const char *szPort = get_arg("p");
    if (szPort) g_system.port = atoi(szPort);
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

    Router::Register(httpService);
    CalibrationRouter::Register(httpService);
    MethodRouter::Register(httpService);
    QueueRouter::Register(httpService);
    SampleRouter::Register(httpService);
    SampleDataRouter::Register(httpService);
    SettingRouter::Register(httpService);
    SystemRouter::Register(httpService);

    HttpServer httpServer;
    httpServer.service = &httpService;
    httpServer.port = g_system.port;
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

    if (g_system.debug)
        printf("http server listening on port %d in debug mode\n", g_system.port);
    else
        printf("http server listening on port %d\n", g_system.port);
    //hthread_create(MethodThread::testThread, NULL);

    auto loop = std::make_shared<EventLoop>();

    loop->setInterval(30000, [](TimerID timerID) {
        printf("time=%lus\n", (unsigned long) time(NULL));
    });
    loop->run();

    return 0;
}
