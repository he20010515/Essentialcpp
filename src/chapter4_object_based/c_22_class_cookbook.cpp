/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-05 17:04:09
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-05 17:11:20
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_22_class_cookbook.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

class Base
{
private:
public:
    virtual void f() const { std::cout << "Base::f" << std::endl; };
    virtual void g() { std::cout << "Base::g" << std::endl; };
    virtual void h() { std::cout << "Base::h" << std::endl; };
};

class Chiled : public Base
{
private:
public:
    virtual void f() { std::cout << "Chiled::f" << std::endl; };
    virtual void g1() { std::cout << "Chiled::g1" << std::endl; };
    virtual void h1() { std::cout << "Chiled::h1" << std::endl; };
};

void call_f(Base &base)
{
    base.f();
}

int main(int argc, char const *argv[])
{
    Chiled chiled;
    Base base;

    call_f(base);
    call_f(chiled);

    return 0;
}
