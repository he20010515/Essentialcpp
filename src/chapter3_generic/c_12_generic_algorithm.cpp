/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-23 20:28:37
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-23 20:46:53
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_12_generic_algorithm.cpp
 * @Description: 使用泛型算法
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
    int i_array[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> i_vector(i_array, i_array + 12);

    // find方法的返回值类型是iterator类型.
    auto it = std::find(i_vector.begin(), i_vector.end(), 10);
    std::cout << "std::find(i_vector.begin(), i_vector.end(), 10);" << std::endl;
    std::cout << *it << std::endl;

    // 注意binary_search方法的返回值是bool类型
    auto binary_search_result = std::binary_search(i_vector.begin(), i_vector.end(), 3);
    std::cout << "auto binary_search_result = std::binary_search(i_vector.begin(), i_vector.end(), 3);" << std::endl;
    std::cout << binary_search_result << std::endl;

    // count方法的返回值是ptrdiff_t类型,其用来表述两个指针之间的"差" see: https://blog.csdn.net/DqD1001/article/details/115339085
    auto count_result = std::count(i_vector.begin(), i_vector.end(), 2);
    std::cout << "auto count_result = std::count(i_vector.begin(), i_vector.end(), 2);" << std::endl;
    std::cout << count_result << std::endl;

    // search方法用于在序列中寻找子序列,其返回值是it类型,指向子序列的开头,如果没有则指向容器最后一个元素的后面位置.
    auto search_result = std::search(i_vector.begin(), i_vector.end(), i_array + 3, i_array + 6);
    std::cout << "auto search_result = std::search(i_vector.begin(), i_vector.end(), i_array + 3, i_array + 6);" << std::endl;
    std::cout << search_result[0] << search_result[1] << search_result[2] << std::endl;

    return 0;
}
