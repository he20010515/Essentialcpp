/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-15 20:43:03
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-15 21:17:26
 * @FilePath: /Essentialcpp/src/chapter0_basic/c_02_E_1_5.cpp
 * @Description: input字符串
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

void method1();
void method2();

int main(int argc, char const *argv[])
{
    method1();
    method2();
    return 0;
}

/**
 * @description: c-style string
 * @return {*}
 */

void method1()
{
    printf("c-style string begin");
    int flag = 0;
    char name[50];
    while (1)
    {
        printf("Please input your name:");
        flag = scanf("%s", name);
        if (strlen(name) >= 2)
        {
            printf("Goodname,your name is:\n%s\n", name);
            break;
        }
        else
        {
            if (flag != 1)
                printf("error in scanf,please check input\n");
            else
                printf("len of name must bigger than 2\nplease retry\n");
        }
    }
    return;
}
/**
 * @description: string object
 * @return {*}
 */
void method2()
{
    std::cout << "c++ string object begin" << std::endl;
    std::string name;
    while (true)
    {
        std::cout << "please inpute your name:";
        std::cin >> name;
        if (name.length() >= 2)
            std::cout << "Good name,length of your name is:" << name.length() << std::endl
                      << "Your name is:" << name << std::endl;
    }

    return;
}
