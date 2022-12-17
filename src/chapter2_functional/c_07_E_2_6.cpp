/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-16 17:02:18
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-16 18:29:11
 * @FilePath: /Essentialcpp/src/chapter2_functional/c_07_E_2_6.cpp
 * @Description: 模板函数
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
template <typename T>
inline T max(T &a, T &b)
{
    if (a > b)
        return a;
    return b;
}
template <typename T>
inline T max(const std::vector<T> v)
{
    return *std::max_element(v.begin(), v.end());
}
inline std::string max(std::string &a, std::string &b)
{
    if (a.length() > b.length())
        return a;
    else
        return b;
}
inline std::string max(std::vector<std::string> &v)
{
    std::string str;
    str = v[0];
    for (int i = 0; i < v.size(); i++)
        if (v[i].length() > str.length())
            str = v[i];
    return str;
}

int main(int argc, char const *argv[])
{
    std::string a_string = "long string       ", b_string = "short string";
    std::string string_array[] = {"a", "b", "cccc"};
    std::vector<std::string> str_vec(string_array, string_array + 3);
    int int_array[5] = {1, 2, 3, 4, 6};
    std::vector<int> int_vec(int_array, int_array + 5);
    int a_int = 10, b_int = 20;
    float a_float = 10., b_float = 20.;
    std::cout << max(a_string, b_string) << std::endl
              << max(a_int, b_int) << std::endl
              << max(a_float, b_float) << std::endl
              << max(str_vec) << std::endl
              << max(int_vec) << std::endl;

    return 0;
}
