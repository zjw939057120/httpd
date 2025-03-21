//
// Created by zjw93 on 2025/3/21.
//

#ifndef HTTPD_THREAD_H
#define HTTPD_THREAD_H


#include <hthread.h>

class Thread {

public:
    static HTHREAD_ROUTINE(testThread);

};


#endif //HTTPD_THREAD_H
