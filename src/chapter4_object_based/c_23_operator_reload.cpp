/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-06 12:55:08
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-22 00:00:23
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_23_operator_reload.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

class My_Class
{
private:
    char *_name;

public:
    My_Class(char *name)
    {
        this->_name = name;
    };
    ~My_Class(){};
    int operator+(My_Class &other)
    {
        std::cout << "called operator+ method of object:" << this->_name << std::endl;
        return 0;
    }
    friend std::ostream &operator<<(std::ostream &out, const My_Class obj)
    {
        out << "<objname::" << obj._name << ">";
        return out;
    }
};

int main(int argc, char const *argv[])
{
    My_Class a("object A");
    My_Class b("object B");

    std::cout << b + a << std::endl;
    std::cout << a << std::endl;

    return 0;
}
