/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-05 17:20:22
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-06-02 23:19:20
 * @FilePath: /Essentialcpp/src/chapter0_other/branch_predictor.cpp
 * @details: 分支预测对函数性能的影响
 */
#include <vector>
#include <chrono>
#include <iostream>

void myprint(int &ref)
{
    std::cout << "invoke:"
              << "void myprint(int &ref)" << std::endl;
    std::cout << ref << std::endl;
    ref += 1;
}
void myprint(int ref)
{
    std::cout << "invoke:"
              << "void myprintf(int ref)" << std::endl;
    std::cout << ref << std::endl;
    ref += 1;
}

int main(int argc, char const *argv[])
{
    int a = 1;
    int &ref = a;
    myprint(ref);
    myprint(a);
}
