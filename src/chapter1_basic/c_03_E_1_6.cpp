/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-15 23:28:44
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-16 00:01:54
 * @FilePath: /Essentialcpp/src/chapter0_basic/c_03_E_1_6.cpp
 * @Description: 变长数组的输入
 */
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char const *argv[])
{
    std::string input_string;
    std::cout << "Please input an array,split by ' ':";
    std::getline(std::cin, input_string);
    std::vector<int> blank_index(0);
    std::vector<int> int_buffer(0);
    for (int i = 0; i <= input_string.length(); i++)
        if (input_string[i] == ' ')
            blank_index.push_back(i);
    blank_index.push_back(input_string.length() - 1);
    int start = 0, end = 0;
    for (auto &&i : blank_index)
    {
        end = i;
        auto var = atoi(input_string.substr(start, end).c_str());
        std::cout << var << " ";
        int_buffer.push_back(var);
        start = end;
    }
    std::cout << std::endl;
    std::cout << "sum of input array is:" << std::accumulate(int_buffer.begin(), int_buffer.end(), 0) << std::endl;

    return 0;
}
