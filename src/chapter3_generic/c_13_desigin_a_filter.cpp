/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-23 20:50:48
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-23 23:53:45
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_13_desigin_a_filter.cpp
 * @Description:
 */

#include <vector>
#include <iostream>
#include <functional>

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

bool less_than_10(int a) { return a < 10; }

int count_occurs(const std::vector<int> &vec, int val)
{
    auto iter = vec.begin();
    int occurs_count = 0;
    while ((iter = std::find(iter, vec.end(), val)) != vec.end())
    {
        ++occurs_count;
        ++iter;
    }
    return occurs_count;
}

template <typename Iterator, typename Filter>
Iterator my_filter(Iterator begin,
                   Iterator end,
                   Iterator it,
                   Filter _filter)
{
    for (; begin != end; begin++)
        if (_filter(*begin))
        {
            *it = *begin;
            it++;
        }
    return it;
}

int main(int argc, char const *argv[])
{
    int i_array[16] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 3, 8, 9, 10, 11, 12, 13};
    std::vector<int> i_vector(i_array, i_array + 16);
    auto v1 = version_1_bigger_than_10(i_vector.begin(), i_vector.end());
    display(v1);
    auto v2 = version_2_filter(i_vector.begin(), i_vector.end(), equal, 3);
    display(v2);
    auto v2_1 = version_2_filter(i_vector.begin(), i_vector.end(), less_than, 3);
    display(v2_1);
    std::cout << count_occurs(i_vector, 3) << std::endl;

    // function object ,defined in <functional>

    auto c = std::plus<int>();
    std::cout << "auto c = std::plus<int>(); \nstd::cout << c(1, 2) << std::endl;" << std::endl;
    std::cout << c(1, 2) << std::endl;

    std::cout << std::plus<std::string>()("hello", " world") << std::endl;
    std::cout << std::minus<int>()(5, 3) << std::endl;
    std::cout << std::multiplies<int>()(3, 3) << std::endl;
    std::cout << std::divides<float>()(4.2, 8.4) << std::endl;
    std::cout << std::negate<int>()(42) << std::endl;

    std::vector<int> result(10);
    std::vector<int>::iterator ans = my_filter(i_vector.begin(),
                                               i_vector.end(),
                                               result.begin(),
                                               std::binder2nd<std::less<int>>(std::less<int>(), 5));
    display(result);
    return 0;
}
