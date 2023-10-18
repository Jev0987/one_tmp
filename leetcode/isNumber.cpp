//
// Created by Jev on 2022/11/5.
//
//剑指 Offer 20. 表示数值的字符串
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。


#include "string"
using namespace std;
class Solution
{
    // 暴力模拟：读取并判断最后一位是否是结尾
    //     ① 只有 e 前后需要有数字
    //     ② 小数点需要增加一个 flag 控制，因为它可能出现在任何地方
    //     ③ 其他情况用 if 和 while 读取即可
public:
    bool isNumber(string s)
    {
        int st = 0;             // 起点下标
        bool dot_flag = false;  // ② 记录小数点是否出现

        while (s[st] == ' ')                        // 读 前缀空格
            st++;

        if (s[st] == '+' || s[st] == '-')           // 读 符号
            st++;

        // 整数 和 小数

        if (s[st] == '.')                           // 读 小数点
        {
            dot_flag = true;
            st++;
        }

        if (s[st] > '9' || s[st] < '0')             // ① E 前面需要有数字
            return false;

        while (s[st] <= '9' && s[st] >= '0')        // 读 数字
            st++;

        if (s[st] == '.')                           // 读 小数点
        {
            if (dot_flag)
                return false;                       // ② 若已存在直接返回 false
            else
            {
                st++;
                while (s[st] <= '9' && s[st] >= '0')
                    st++;
            }
        }

        // E 及其整数尾缀

        if (s[st] == 'e' || s[st] == 'E')
        {
            st++;
            if (s[st] == '+' || s[st] == '-')       // 读 符号
                st++;

            if (s[st] > '9' || s[st] < '0')         // ① E 后面需要有数字
                return false;

            while (s[st] <= '9' && s[st] >= '0')
                st++;
        }


        while (s[st] == ' ')                        // 读 后缀空格
            st++;

        if (s[st] == '\0')
            return true;
        else
            return false;
    }
};