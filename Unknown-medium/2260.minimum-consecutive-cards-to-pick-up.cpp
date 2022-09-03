/*
 * @lc app=leetcode id=2260 lang=cpp
 *
 * [2260] Minimum Consecutive Cards to Pick Up
 */

// @lc code=start
typedef unordered_set<int> SET;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), r = 0, l = 0, res = INT_MAX;
        SET st;
        for(r = 0; r < n; r++){
            int n_r = cards.at(r);
            pair<SET::iterator, bool> f_it = st.insert(n_r);
            if(!f_it.second){
                for(; l < r && cards.at(l) != n_r; l++){
                    st.erase(cards.at(l));
                }
                res = r - l + 1 < res? r - l + 1 : res;
                l++;
            }
        }
        return res == INT_MAX? -1 : res;
    }
};

/**
Testcases

[3,4,2,3,4,7]
[1,0,5,3]
[1]
[1,0]
[1,1]
**/
// @lc code=end

