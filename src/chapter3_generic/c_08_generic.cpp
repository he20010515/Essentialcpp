/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-17 15:05:35
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-17 17:36:15
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_08_generic.cpp
 * @Description: 泛型编程风格.
 */

#include <vector>
#include <string>
#include <iostream>

/**
 * @description: 寻找一个整数数组中的数,返回指针.
 * @param {vector<int>} vector
 * @param {int} find_value
 * @return {*}
 */
int *find(const std::vector<int> &vector, int find_value)
{
    for (int i = 0; i < vector.size(); i++)
        if (vector[i] == find_value)
            return (int *)&(vector[i]);
    return nullptr;
}

template <typename T>
T *find(const std::vector<T> &vector, T find_value)
{
    for (int i = 0; i < vector.size(); i++)
        if (vector[i] == find_value)
            return (T *)&(vector[i]);
    return nullptr;
}

template <typename T>
T *find(T *first, const T *end, const T &find_value)
{
    if ((!first) || (!end))
        return nullptr;
    for (; first != end; first++)
        if (*first == find_value)
            return first;
    return nullptr;
}

int main(int argc, char const *argv[])
{
    std::string string_array[] = {
        "test",
        "test2",
        "string_3"};
    std::vector<std::string> string_vector(string_array, string_array + 3);
    std::string match_string = "test";
    std::cout << *find<std::string>(string_vector, match_string) << std::endl;
    std::cout << *find<std::string>(string_array, string_array + 3, string_array[2]) << std::endl;
    return 0;
}
