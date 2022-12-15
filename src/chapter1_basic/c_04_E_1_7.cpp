/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-16 00:10:21
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-16 00:43:33
 * @FilePath: /Essentialcpp/src/chapter0_basic/c_04_E_1_7.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>

#include <unistd.h>

int main(int argc, char const *argv[])
{
    auto current_path = std::__fs::filesystem::current_path();
    auto project_path = current_path.parent_path().parent_path().parent_path();
    auto chapter1_path = project_path / "src" / "chapter1_basic";
    std::cout << "current_path :" << current_path << std::endl;
    std::cout << "computed_path:" << chapter1_path << std::endl;
    std::cout << "changing_path..." << std::endl;
    chdir(chapter1_path.c_str());
    std::cout << "curren_path :" << std::__fs::filesystem::current_path() << std::endl;

    std::ifstream in_file("./c_04_E_1_7_input_file.txt");
    if (in_file)
    {
        std::string string_buffer((std::istreambuf_iterator<char>(in_file)),
                                  std::istreambuf_iterator<char>());
        in_file.close();
        std::cout
            << "file info:\n"
            << string_buffer << std::endl;
        std::sort(string_buffer.begin(), string_buffer.end());
        std::ofstream out_file("./c_04_E_1_7_output_file.txt");
        out_file << string_buffer;
        out_file.close();
    }
    else
        std::cerr << "Warning file not exist" << std::endl, exit(-1);

    return 0;
}
