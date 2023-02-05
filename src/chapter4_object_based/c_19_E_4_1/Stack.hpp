/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 14:59:32
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-01-14 00:46:42
 * @FilePath: /Essentialcpp/src/chapter4_object_based/c_19_E_4_1/Stack.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#pragma once
#include <vector>
#include <string>
class Stack
{
private:
    std::vector<std::string> *_stack;
    size_t _max_size;

public:
    Stack();
    Stack(size_t size);
    bool push(const std::string &value);
    bool pop(std::string &value);
    bool full();
    bool find(std::string &value);
    bool find(const char *value)
    {
        std::string temp(value);
        return this->find(temp);
    };
    size_t count(std::string &value);
    size_t count(const char *value)
    {
        std::string temp(value);
        return this->count(temp);
    };
    size_t size() { return _stack->size(); };
    size_t max_size() { return this->_max_size; };

    ~Stack();
};
