/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-05 17:20:22
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-11 11:41:47
 * @FilePath: /Essentialcpp/src/chapter0_other/branch_predictor.cpp
 * @details: 分支预测对函数性能的影响
 */
#include <vector>
#include <chrono>
#include <iostream>

int main(int argc, char const *argv[])
{
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (size_t i = 0; i < arraySize; i++)
        data[i] = std::rand() % 256;

    std::sort(data, data + arraySize); // 注释此行观察程序运行时间的差异

    auto start = std::chrono::system_clock::now();
    long long sum = 0;
    for (size_t i = 0; i < 100000; i++)
        for (size_t c = 0; c < arraySize; c++)
            if (data[c] >= 128)
                sum += data[c];
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double elapsed = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
    std::cout << "time:" << elapsed << std::endl;

    return 0;
}
