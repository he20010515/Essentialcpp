/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-20 18:03:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-23 20:22:01
 * @FilePath: /Essentialcpp/src/chapter0_other/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <filesystem>
#include <math.h>
#include <unistd.h>

inline void chdir_to_src_path()
{
    std::__fs::filesystem::path src_path(__FILE__);
    chdir(src_path.parent_path().c_str());
}

namespace my_namespace
{
    class vector
    {
    private:
        double x, y, z;

    public:
        vector(double _x, double _y, double _z);
        vector(my_namespace::vector &v);
        vector normalize() const;
        ~vector();
        vector operator+(const vector &other) const;
    };

    vector::vector(double _x, double _y, double _z)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }
    vector::vector(vector &v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }
    vector::~vector()
    {
    }
    vector vector::normalize() const
    {
        auto l = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        vector v(this->x / l, this->y / l, this->z / l);
        return v;
    }
} // namespace my_namespace

int main(int argc, char const *argv[])
{
    chdir_to_src_path();
    return 0;
}
