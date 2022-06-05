// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
// #include "commoncppproblem43.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start

void rm_leading0(string &s){
    int i = 0;
    for(i = 0; i < s.size() - 1 && s.at(i) == '0'; i++){}
    s.erase(0, i);
}

string mul_1d(string s, char mul){
    string res;
    int carry = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        int m = (s.at(i) - '0') * (mul - '0') + carry;
        carry = m / 10;
        res = string(1, (m % 10 + '0')) + res;
    }
    res = string(1, (carry + '0')) + res;
    rm_leading0(res);
    return res;
}

string add(string a, string b){
    string res;
    int carry = 0, min_d_num = a.size() < b.size()? a.size() : b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < min_d_num; i++){
        int m = (a.at(i) - '0') + (b.at(i) - '0') + carry;
        carry = m / 10;
        res += string(1, (m % 10 + '0'));
    }
    res += string(1, (carry + '0'));
    reverse(res.begin(), res.end());
    rm_leading0(res);
    return res;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        for(int i = 0; i < num2.size(); i++){
            string d_res = mul_1d(num1, num2.at(i));
            d_res += string(i, '0');
        }
    }
};
// @lc code=end

