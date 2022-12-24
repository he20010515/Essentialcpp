/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 14:08:02
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-24 14:19:56
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_18_define_a_class.cpp
 * @Description: 定义一个类
 */
#include <string>
#include <iostream>
#include <vector>

class Stack
{
private:
    std::vector<std::string> _stack;

public:
    bool push(const std::string &elem)
    {
        _stack.push_back(elem);
        return true;
    }
    std::string pop()
    {
        std::string temp = *(_stack.end() - 1);
        _stack.pop_back();
        return temp;
    }
    bool peep(std::string elem) { return true; }
    bool empty() { return _stack.empty(); }
    int size() { return _stack.size(); }
    Stack() {}
    ~Stack() {}
};

void fill_stack(Stack &stack, std::istream &is = std::cin)
{
    std::string str;
    while (is >> str)
        stack.push(str);
    std::cout << "Read in " << stack.size() << " elements." << std::endl;
}

int main(int argc, char const *argv[])
{
    Stack s;
    using namespace std;
    cout << "Please input elements:" << endl
         << ">>";
    fill_stack(s);
    return 0;
}
