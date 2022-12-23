/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-23 20:50:48
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-23 21:25:47
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_13_desigin_a_filter.cpp
 * @Description:
 */

#include <vector>
#include <iostream>

template <typename IterType>
void display(IterType begin, IterType end)
{
    std::cout << "[";
    for (; begin != end; begin++)
        std::cout << *begin << ", ";
    std::cout << "\b\b]" << std::endl;
}

template <typename ContainerType>
void display(ContainerType &con)
{
    display(con.begin(), con.end());
}

std::vector<int> version_1_bigger_than_10(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int> temp;
    for (; begin != end; begin++)
        if (*begin >= 10)
            temp.push_back(*begin);
    return temp;
}

std::vector<int> version_2_filter(std::vector<int>::iterator begin,
                                  std::vector<int>::iterator end,
                                  bool (*filter)(int, int),
                                  int filter_value)
{
    std::vector<int> temp;
    for (; begin != end; begin++)
        if (filter(*begin, filter_value))
            temp.push_back(*begin);
    return temp;
}
bool greater_than(int a, int b) { return a > b; }
bool less_than(int a, int b) { return a < b; }
bool equal(int a, int b) { return a == b; }

int main(int argc, char const *argv[])
{
    int i_array[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> i_vector(i_array, i_array + 13);
    auto v1 = version_1_bigger_than_10(i_vector.begin(), i_vector.end());
    display(v1);
    auto v2 = version_2_filter(i_vector.begin(), i_vector.end(), equal, 3);
    display(v2);
    auto v2_1 = version_2_filter(i_vector.begin(), i_vector.end(), less_than, 3);
    display(v2_1);

    return 0;
}
