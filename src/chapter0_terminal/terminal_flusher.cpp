/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-06 14:16:57
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-06 14:28:57
 * @FilePath: /Essentialcpp/src/chapter0_terminal/terminal_flusher.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

static std::string upblock = "▀";

class Terminal_Screen
{
private:
    bool _status_bar;

public:
    Terminal_Screen(bool statusbar)
    {
        this->_status_bar = statusbar;
    };
    ~Terminal_Screen(){

    };
    void clear_screen() { std::cout << "\33[2J"; };
};

int main(int argc, char const *argv[])
{
    auto screen = new Terminal_Screen(true);
    std::cout << "message" << std::endl;
    screen->clear_screen();
    std::cout << "\033[33m黄色字体\033[0m" << std::endl;
    return 0;
}
