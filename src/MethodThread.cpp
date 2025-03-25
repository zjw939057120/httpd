//
// Created by zjw93 on 2025/3/21.
//

#include "MethodThread.h"

HTHREAD_RETTYPE MethodThread::testThread(void *userdata) {
    while (1) {
        printf("testThread time=%lus\n", (unsigned long) time(NULL));
        Sleep(1000);
    }
    return 0;
}
