//
// Created by zjw93 on 2025/3/21.
//

#include "Thread.h"

HTHREAD_RETTYPE Thread::testThread(void *userdata) {
    while (1) {
        printf("testThread time=%lus\n", (unsigned long) time(NULL));
        Sleep(1000);
    }
    return 0;
}
