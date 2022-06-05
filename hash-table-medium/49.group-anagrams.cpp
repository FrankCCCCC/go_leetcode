// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
// #include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

typedef unordered_map<string, vector<string>> MAP;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        MAP mp;
        for(string s: strs){
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }

        vector<vector<string>> res;
        for(auto p: mp){
            res.push_back(p.second);
        }
        return res;
    }
};

/**
Testcases

["eat","tea","tan","ate","nat","bat"]
[""]
["a"]
**/
// @lc code=end

