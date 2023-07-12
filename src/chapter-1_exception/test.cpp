/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-03-30 15:14:19
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-04-16 22:46:04
 * @FilePath: /Essentialcpp/src/chapter-1_exception/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        map<int, int> hashmap;
        for (auto &&i : nums)
        {
            int w = target - i;
            if (hashmap.find(w) != hashmap.end())
            {
                auto item = *hashmap.find(w);
                auto a = item.second;
                auto b = i;
                res.push_back(a);
                res.push_back(b);
                break;
            }

            hashmap[w] = i;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    auto solu = Solution();
    vector<int> a;
    for (int i = 0; i < 4; i++)
    {
        a.push_back(i);
    }

    auto ans = solu.twoSum(a, 51);
    std::cout << ans[0] << ans[1] << std::endl;
    return 0;
}
