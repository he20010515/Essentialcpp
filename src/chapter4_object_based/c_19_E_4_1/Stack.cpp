/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 14:59:49
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-26 00:13:11
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_19_E_4_1/Stack.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Stack.hpp"

Stack::Stack()
{
    this->_max_size = 10;
    this->_stack = new std::vector<std::string>;
}

Stack::Stack(size_t size)
{
    this->_max_size = size;
    this->_stack = new std::vector<std::string>;
}

Stack::~Stack()
{
    delete this->_stack;
}

bool Stack::push(const std::string &value)
{
    if (!this->full())
    {
        this->_stack->push_back(value);
        return true;
    }
    else
        return false;
}

bool Stack::pop(std::string &value)
{
    if (!this->_stack->empty())
    {
        value = *(this->_stack->end() - 1);
        _stack->pop_back();
        return true;
    }
    else
        return false;
}

bool Stack::full()
{
    if (this->_stack->size() >= this->_max_size)
        return true;
    else
        return false;
}

bool Stack::find(std::string &value)
{
    auto c = std::find(this->_stack->begin(), this->_stack->end(), value);
    return (c != this->_stack->end());
}


size_t Stack::count(std::string &value)
{
    auto c = std::count(this->_stack->begin(), this->_stack->end(), value);
    return (size_t)c;
}
