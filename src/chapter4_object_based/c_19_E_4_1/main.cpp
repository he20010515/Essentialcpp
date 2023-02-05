/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 15:09:56
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-01-14 00:49:59
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_19_E_4_1/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Stack.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Stack s(20);
    std::cout << "stack size:" << s.max_size() << std::endl;
    std::string temp;
    s.push("string1");
    s.push("string2");
    s.push("string3");
    s.push("string4");
    s.push("string5");
    s.push("test");
    s.push("test");
    s.push("test");

    s.pop(temp);
    std::cout << temp << std::endl;
    std::cout << s.find("test") << std::endl;
    std::cout << s.count("test") << std::endl;

    return 0;
}
