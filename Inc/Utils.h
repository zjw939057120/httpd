//
// Created by zjw93 on 2025/3/31.
//

#ifndef HTTPD_UTILS_H
#define HTTPD_UTILS_H

class Utils
{
public:
    static std::string preprocessToJson(const std::string &input);
    
    static void print(const char *input);

    static void print(const std::string &input);
};

#endif // HTTPD_UTILS_H
