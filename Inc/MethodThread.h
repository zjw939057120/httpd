//
// Created by zjw93 on 2025/3/21.
//

#ifndef HTTPD_METHODTHREAD_H
#define HTTPD_METHODTHREAD_H


#include <hthread.h>

class MethodThread {

public:
    static HTHREAD_ROUTINE(testThread);

};


#endif //HTTPD_METHODTHREAD_H
