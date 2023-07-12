/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-03-30 15:51:09
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-04-02 20:25:29
 * @FilePath: /Essentialcpp/src/chapter-2_rationalnumber/rationalnumber.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "vector"
#include "string"
#include "iostream"
#include "algorithm"
#include "exception"
class BigInt
{
private:
    std::vector<unsigned int> nums;
    bool positive;
    void __pop_zero()
    {
        if (this->nums.end() != this->nums.begin())
        {
            auto p = --this->nums.end();
            while (*(p--) == 0)
                this->nums.pop_back();
        }
    }
    BigInt __p_add_p(const BigInt &other) const // 正整数加正整数
    {
        assert(this->positive and other.positive);
        bool left_bigger_than_other = this->nums.size() > other.nums.size();
        BigInt res;
        BigInt shorterint(left_bigger_than_other ? other : *this);
        long long flatten_size = left_bigger_than_other ? this->nums.size() : other.nums.size();
        const BigInt &longerint = (left_bigger_than_other) ? *this : other;
        while (shorterint.nums.size() < flatten_size)
            shorterint.nums.push_back(0);
        assert(longerint.nums.size() == shorterint.nums.size());
        auto end = --longerint.nums.end();
        auto p = shorterint.nums.begin();
        auto q = longerint.nums.begin();
        int r = 0, s = 0;
        while (true)
        {
            s = (*p + *q) % 10; // 剩余
            res.nums.push_back(s + r);
            r = (*p + *q) / 10;      // 进位
            if (q == end and r == 0) // 无进位情况
            {
                break;
            }
            else if (q == end and r != 0) // 有进位情况
            {
                res.nums.push_back(r);
                break;
            }
            p++;
            q++;
        }
        return res;
    }
    BigInt __p_sub_p(const BigInt &other) const
    {
        assert(*this > other);
        assert(this->positive and other.positive);
        BigInt res;
        BigInt other_(other);
        while (other_.nums.size() < this->nums.size())
            other_.nums.push_back(0);

        auto p = this->nums.begin();
        auto q = other_.nums.begin();
        bool flag = false;
        while (true)
        {
            int f = *p - flag;
            int g = *q;
            if (f >= g)
                res.nums.push_back(*p - *q - flag), flag = false;
            else
                res.nums.push_back(*p + 10 - *q - flag), flag = true;
            p++;
            q++;
            if (p == this->nums.end())
                break;
        }
        res.__pop_zero();
        return res;
    }

public:
    BigInt()
    {
        this->positive = true;
    }
    BigInt(std::string &str)
    {
        static char temp[2] = "0";
        if (str[0] == '-')
            this->positive = false;
        else
            this->positive = true;
        for (auto start = str.rbegin(); start != str.rend(); start++)
        {
            if (*start == '\0' or *start == '-')
                continue;
            temp[0] = *start;
            this->nums.push_back(std::atoi(temp));
        }
    };
    BigInt(const char *str)
    {
        std::string string(str);
        new (this) BigInt(string); // 不重新分配内存,而是直接覆盖在原内存上;
    }
    BigInt(long long a)
    {
        this->positive = (a >= 0);
        if (a <= 0)
        {
            a = -a;
        }

        unsigned int c;
        while (a != 0)
        {
            c = a % 10;
            this->nums.push_back(c);
            a /= 10;
        }
    }
    friend std::ostream &operator<<(std::ostream &out, BigInt &value)
    {
        out << "<BigInt:";
        if (not value.positive)
        {
            out << "-";
        }
        if (value.nums.rbegin() == value.nums.rend())
        {
            out << "0";
        }
        else
        {
            for (auto i = value.nums.rbegin(); i != value.nums.rend(); i++)
                out << *i;
        }
        out << ">";
        return out;
    };
    BigInt operator+(const BigInt &other) const
    {
        if (this->positive and other.positive)
        {
            return this->__p_add_p(other);
        }
        else
        {
            throw "not defined";
        }
    }
    bool operator>(const BigInt &other) const
    {
        // 处理异号情况
        if (this->positive and (not other.positive))
        {
            return true;
        }
        else if ((not this->positive) and other.positive)
        {
            return false;
        }
        // 处理同号不同长度情况
        auto _both_positive = this->positive;
        if (this->nums.size() > other.nums.size())
        {
            return _both_positive ? true : false;
        }
        else if (this->nums.size() < other.nums.size())
        {
            return _both_positive ? false : true;
        }
        // 处理同号同长度情况
        auto p = this->nums.rbegin();
        auto q = other.nums.rbegin();
        auto p_end = this->nums.rend();
        while (true)
        {
            if (p == p_end)
            {
                return false;
            }
            if (*p > *q) //! 内存越界
            {
                return _both_positive ? true : false;
            }
            else if (*p < *q)
            {
                return _both_positive ? false : true;
            }
            p++;
            q++;
        }
    }
    bool operator==(const BigInt &other) const
    {
        if (this->positive != other.positive)
        {
            return false;
        };
        if (this->nums.size() != other.nums.size())
        {
            return false;
        };
        if ((this->nums.size() == 0) and (other.nums.size() == 0))
        {
            return true;
        }

        auto p = this->nums.begin();
        auto q = other.nums.begin();
        while (true)
        {
            if (*p != *q)
            {
                return false;
            }
            else
            {
                p++;
                q++;
            }
            if (p == this->nums.end())
                break;
        }
        return true;
    }
    bool operator<(const BigInt &other) const { return other > *this; }
    bool operator<=(const BigInt &other) const { return (*this < other) or (*this == other); }
    bool operator>=(const BigInt &other) const { return (*this > other) or (*this == other); }
    bool operator!=(const BigInt &other) const { return not(*this == other); }
    BigInt operator-(const BigInt &other)
    {
        if (*this == other)
        {
            return BigInt();
        }

        if (this->positive and other.positive and *this > other)
        {
            return this->__p_sub_p(other);
        }
        else if (this->positive and other.positive and *this < other)
        {
            return -((-other) - (-*this));
        }
        else if (this->positive and (not other.positive))
        {
            return *this + (-other);
        }
        else if ((not this->positive) and other.positive)
        {
            return -(-*this + other);
        }
        else if ((not this->positive) and (not other.positive))
        {
            return -(-*this - (-other));
        }
        throw "undefined";
    }
    BigInt operator-() const
    {
        BigInt res(*this);
        res.positive = not this->positive;
        return res;
    }

    ~BigInt(){};
};

class RationalNumber
{
private:
    BigInt a;
    BigInt b;

public:
    RationalNumber(){};
    ~RationalNumber(){};
};

void unit_test()
{
    // 构造方法
    BigInt a = {10}, b = {-10}, c = {999}, d = {"1000"}, e = {"-1000"};
    BigInt f = {"-999"}, g = {"-999"};
    // 友元函数
    std::cout << a << b << c << d << e << f << std::endl;
    // 比较运算
    // std::vector<BigInt> temp;
    // for (int i = 0; i < 10000; i++)
    // {
    //     temp.push_back(BigInt(i - 5000));
    // }
    // for (int i = 0; i < 10000; i++)
    // {
    //     for (int j = 0; j < 10000; j++)
    //     {
    //         BigInt &a = temp[i];
    //         BigInt &b = temp[j];
    //         auto a_int = i - 5000;
    //         auto b_int = j - 5000;

    //         assert((a == b) == (a_int == b_int));
    //         assert((a >= b) == (a_int >= b_int));
    //         assert((a <= b) == (a_int <= b_int));
    //         assert((a != b) == (a_int != b_int));
    //         assert((a < b) == (a_int < b_int));
    //         assert((a > b) == (a_int > b_int));
    //     }
    // }

    for (int i = -100; i < 100; i++)
    {
        for (int j = -100; j < 100; j++)
        {
            // j>=i;
            assert(BigInt(j) - BigInt(i) == BigInt(j - i));
        }
    }
}

int main(int argc, char const *argv[])
{
    auto a = BigInt(-99);
    auto b = BigInt(-100);
    auto c = (a - b);
    std::cout << c << std::endl;
    // unit_test();
    return 0;
}
