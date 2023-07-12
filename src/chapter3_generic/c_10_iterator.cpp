/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-18 15:25:06
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-04-07 16:31:02
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_10_iterator.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <vector>
#include <list>
#include <iostream>

template <typename IteratorType, typename ElemType>
IteratorType my_find(IteratorType first, IteratorType last, const ElemType &value);

int main(int argc, char const *argv[])
{
    int intarray[] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> int_vector(intarray, intarray + 8);
    std::string string_array[] = {"1", "22", "33", "444", "this is a string"};
    std::vector<std::string> string_vector(string_array, string_array + 5);
    std::list<std::string> string_list(string_array, string_array + 5);
    const std::string match_string = "444";
    std::cout << *my_find(string_vector.begin(), string_vector.end(), match_string) << std::endl;
    std::cout << *my_find(intarray, intarray + 8, 8) << std::endl;
    std::cout << *my_find(string_list.begin(), string_list.end(), "this is a string") << std::endl;
    return 0;
}

template <typename IteratorType, typename ElemType>
IteratorType my_find(IteratorType first, IteratorType last, const ElemType &value)
{
    for (; first != last; ++first)
        if (value == *first)
            return first;
    return last;
}
