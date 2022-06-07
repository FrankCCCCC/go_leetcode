// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
typedef map<char, string> MAP;

void solve(vector<string> &st, string digits, MAP mp){
    int n = digits.size();
    if(n <= 0) return;
    
    if(n == 1){
        for(char c: mp[digits.at(0)]){
            st.push_back(string(1, c));
        }
    }else{
        solve(st, digits.substr(1, n - 1), mp);
        int st_n = st.size();
        string str = mp[digits.at(0)];
        for(int i = 1; i < str.size(); i++){
            for(int j = 0; j < st_n; j++){
                st.push_back(str.at(i) + st.at(j));
            }
        }
        
        for(int j = 0; j < st_n; j++){
            st.at(j) = str.at(0) + st.at(j);
        }
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        MAP mp;
        mp['2'] = string("abc");
        mp['3'] = string("def");
        mp['4'] = string("ghi");
        mp['5'] = string("jkl");
        mp['6'] = string("mno");
        mp['7'] = string("pqrs");
        mp['8'] = string("tuv");
        mp['9'] = string("wxyz");
        
        vector<string> st;
        solve(st, digits, mp);
        return st;
    }
};

/**
Testcases

"23"
"32"
"234"
"432"
""
"2"
"789"
**/
// @lc code=end

