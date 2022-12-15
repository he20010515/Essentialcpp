/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-15 20:16:40
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-15 20:39:57
 * @FilePath: /Essentialcpp/src/chapter0_basic/c_01_Array_and_Vector.cpp
 * @Description: Vector 的基本使用,通过Vector实现一个简单的猜数列功能
 */
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    std::cout << "hello world!" << std::endl;
    const int seq_size = 16;

    // 初始化Pell序列
    std::vector<int> pell_seq(seq_size);
    int elem_vals[18] = {
        1, 2, 3, 3, 4, 7, 2, 5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22};
    std::vector<int> elem_seq(elem_vals, elem_vals + 18);
    pell_seq[0] = 1;
    pell_seq[1] = 2;
    for (int ix = 2; ix < seq_size; ix++)
        pell_seq[ix] = pell_seq[ix - 2] + 2 * pell_seq[ix - 1];
    std::cout << "The first " << seq_size << " elements of the Pell Series:\n\t";
    for (int ix = 0; ix < seq_size; ix++)
        std::cout << pell_seq[ix] << '\t';
    std::cout << std::endl;

    return 0;
}
