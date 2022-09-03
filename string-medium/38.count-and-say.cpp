// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem38.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return string("1");
        
        string s("1");
        for(int i = 2; i <= n; i++){
            string s_tmp;
            char c_tmp = s.at(0);
            int c_cnt = 1;
            for(int j = 1; j < s.size(); j++){
                if(s.at(j) == c_tmp){
                    c_cnt++;
                }else{
                    s_tmp += (to_string(c_cnt) + string(1, c_tmp));
                    c_tmp = s.at(j);
                    c_cnt = 1;
                }
            }
            s_tmp += (to_string(c_cnt) + string(1, c_tmp));
            s = s_tmp;
        }
        return s;
    }
};

/**
Testcases

1
2
3
4
5
6
7
8
9
10
**/
// @lc code=end

