/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-16 05:30:18
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-16 05:39:26
 * @FilePath: /Essentialcpp/src/chapter2_functional/c_05_Functional_fib.cpp
 * @Description: **引用传递**
 */
#include <iostream>
bool fib(int index, int &fib);

int main(int argc, char const *argv[])
{
    int y = 1;

    for (int i = 0; i < 20; i++)
    {
        if (fib(i, y))
            std::cout << "fib(" << i << ")=" << y << std::endl;
        else
            std::cout << "error" << std::endl;
    }
}

bool fib(int index, int &fib)
{
    if (index <= 0)
        return false;
    int a = 1, b = 1, c = 0;
    switch (index)
    {
    case 1:
    case 2:
        return 1;
    default:
        for (int i = 0; i < index - 2; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        fib = c;
        break;
    }
    return true;
}