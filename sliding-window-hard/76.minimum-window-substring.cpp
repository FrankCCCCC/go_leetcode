// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#define FREQ_SIZE 58

typedef struct{
    int i;
    char c;
}Occur;

inline bool match(int *s_freq, int *t_freq){
    for(int i = 0; i < FREQ_SIZE; i++){
        if(s_freq[i] < t_freq[i]){return false;}
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        int s_sz = s.size(), t_sz = t.size();
        if(s_sz < t_sz){return string();}
        
        int t_freq[FREQ_SIZE] = {0}, s_freq[FREQ_SIZE] = {0}, l_res = 0, res = INT_MAX, l = 0, r = 0;
        for(char c: t){
            t_freq[c - 'A']++;
        }
        
        vector<Occur> ls;
        for(int i = 0; i < s_sz; i++){
            if(t_freq[s[i] - 'A'] > 0){ls.push_back(Occur({i, s[i]}));}
        }
        
        for(l = 0, r = 0; r < ls.size(); r++){
            s_freq[ls[r].c - 'A']++;
            
            if(s_freq[ls[r].c - 'A'] < t_freq[ls[r].c - 'A'] || !match(s_freq, t_freq)){continue;}
            
            for(; l <= r; l++){
                s_freq[ls[l].c - 'A']--;
                if(s_freq[ls[l].c - 'A'] < t_freq[ls[l].c - 'A']){
                    break;
                }
            }
            
            int cur_len = ls[r].i - ls[l].i + 1;
            if(cur_len < res){
                res = cur_len;
                l_res = ls[l].i;
            }
            l++;
        }
        if(res == INT_MAX){return string();}
        return s.substr(l_res, res);
    }
};

/**
Testcases

"a"
"b"
"a"
"aa"
"ACBA"
"AB"
"BECODEBA"
"ABC"
"ADOBECODEBANC"
"ABC"
**/
// @lc code=end

