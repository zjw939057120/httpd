/*
 * sample http server
 * more detail see examples/httpd
 *
 */

#include <Thread.h>
#include "HttpServer.h"
#include "hthread.h"    // import hv_gettid
#include "hasync.h"     // import hv::async
#include "router.h"
#include "EventLoop.h"

using namespace hv;

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

    int port = 0;
    if (argc > 1) {
        port = atoi(argv[1]);
    }
    if (port == 0) port = 8080;

    HttpService router;

    // middleware
    router.AllowCORS();
    router.Use([](HttpRequest *req, HttpResponse *resp) {
        resp->SetHeader("X-Request-tid", hv::to_string(hv_gettid()));
        return HTTP_STATUS_NEXT;
    });

    Router::Register(router);

    HttpServer server;
    server.service = &router;
    server.port = port;
#if TEST_HTTPS
    server.https_port = 8443;
    hssl_ctx_opt_t param;
    memset(&param, 0, sizeof(param));
    param.crt_file = "cert/server.crt";
    param.key_file = "cert/server.key";
    param.endpoint = HSSL_SERVER;
    if (server.newSslCtx(&param) != 0) {
        fprintf(stderr, "new SSL_CTX failed!\n");
        return -20;
    }
#endif

    // uncomment to test multi-processes
    server.setProcessNum(4);
    // uncomment to test multi-threads
    server.setThreadNum(64);

    int ret = server.start();
    if (ret != 0) {
        exit(0);
    }

    //hthread_create(Thread::testThread, NULL);

    // 新建一个事件循环对象
    EventLoopPtr loop(new EventLoop);

    // 设置一个30s定时器
    loop->setInterval(30000, [](TimerID timerID) {
        //printf("time=%lus\n", (unsigned long) time(NULL));
    });

    // 运行事件循环
    loop->run();
    return 0;
}
