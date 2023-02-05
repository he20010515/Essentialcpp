/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-01-14 15:03:46
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-05 16:43:54
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_21_constructor_initize_list.cpp
 * @Description: 构造方法,初始化列表,赋值拷贝,赋值运算符这一堆东西..
 */

#include <iostream>

class BaseClass_A
{
private:
    int a;

public:
    BaseClass_A()
    {
        std::cout << "BaseClass_A :: 默认构造方法" << std::endl;
        this->a = 0;
    };
    BaseClass_A(const BaseClass_A &other)
    {
        std::cout << "BaseClass_A :: 拷贝构造方法" << std::endl;
        this->a = other.a;
    };
    BaseClass_A operator=(const BaseClass_A &other)
    {
        std::cout << "BaseClass_A :: 赋值运算符" << std::endl;
        this->a = other.a;
        return *this;
    };
    ~BaseClass_A()
    {
        std::cout << "BaseClass_A :: 析构函数" << std::endl;
    };
};

class BaseClass_B
{
private:
    int a;

public:
    BaseClass_B()
    {
        std::cout << "BaseClass_B :: 默认构造方法" << std::endl;
        this->a = 0;
    };
    BaseClass_B(const BaseClass_B &other)
    {
        std::cout << "BaseClass_B :: 拷贝构造方法" << std::endl;
        this->a = other.a;
    };
    BaseClass_B operator=(const BaseClass_B &other)
    {
        std::cout << "BaseClass_B :: 赋值运算符" << std::endl;
        this->a = other.a;
        return *this;
    };
    ~BaseClass_B()
    {
        std::cout << "BaseClass_B :: 析构函数" << std::endl;
    }
};

class Test
{
public:
    BaseClass_A test1;
    BaseClass_B test2;

    Test(BaseClass_A &t1, BaseClass_B &t2) : test1(t1)
    {
        std::cout << "Test :: Test 默认构造方法" << std::endl;
        this->test2 = t2;
    };
    Test(Test &other) : test1(other.test1), test2(other.test2)
    {
        std::cout << "Test :: Test 拷贝构造方法" << std::endl;
    }
    ~Test()
    {
        std::cout << "Test :: Test 析构函数" << std::endl;
    };
};

int main(int argc, char const *argv[])
{
    std::cout << "main :: 在栈区构造A" << std::endl;
    BaseClass_A base1;
    std::cout << "main :: 在堆区构造B" << std::endl;
    BaseClass_B *base2 = new BaseClass_B;
    std::cout << "main :: 在栈区构造test" << std::endl;
    Test test(base1, *base2);

    std::cout << "main :: 在堆区构造test2" << std::endl;
    auto test2 = new Test(test);

    return 0;
}
