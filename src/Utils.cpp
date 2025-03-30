//
// Created by zjw93 on 2025/3/31.
//

#include <string>
#include <regex>
#include "Utils.h"

std::string Utils::preprocessToJson(const std::string &input) {
    // 替换 key 使其符合 JSON 标准（添加双引号）
    std::regex key_pattern(R"((\w+)\s*:)"); // 匹配键（如 id:）
    std::string result = std::regex_replace(input, key_pattern, R"("$1":)");

    // 替换单引号包裹的值为双引号
    std::regex value_pattern(R"('([^']*)')"); // 匹配单引号包裹的内容
    result = std::regex_replace(result, value_pattern, R"("$1")");

    return result;
}
