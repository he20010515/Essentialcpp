/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-16 05:41:10
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-16 05:55:18
 * @FilePath: /Essentialcpp/src/chapter2_functional/c_06_Bubble_sort.cpp
 * @Description: c++实现冒泡排序;
 */

#include <vector>
#include <iostream>
void print_vector(const std::vector<int> &vector);
void swap(int &a, int &b);
void bubble_sort(std::vector<int> &vector);

int main(int argc, char const *argv[])
{
    int v_values[8] = {1, 23, 3, 2, 5, 10, 22, 15};
    std::vector<int> vector(v_values, v_values + 8);
    print_vector(vector);
    bubble_sort(vector);
    print_vector(vector);

    return 0;
}

void print_vector(const std::vector<int> &vector)
{
    std::cout << "[";
    for (auto &&x : vector)
        std::cout << x << ", ";
    std::cout << "\b\b]" << std::endl;
    return;
}
void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
    return;
}

void bubble_sort(std::vector<int> &vector)
{
    for (size_t j = 0; j < vector.size(); j++)
        for (size_t i = 0; i < vector.size() - 1 - j; i++)
            if (vector[i] > vector[i + 1])
                swap(vector[i], vector[i + 1]);
    return;
}