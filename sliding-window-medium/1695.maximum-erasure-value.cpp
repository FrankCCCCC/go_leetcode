/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool st[10001] = {0};
        
        int l = 0, r = 0, max_sc = 0, sc = 0;
        for(; r < nums.size();){
            int n_r = nums.at(r);
            if(!st[n_r]){
                st[n_r] = true;
                sc += n_r;
                r++;
            }else{
                for(; nums.at(l) != n_r;){
                    st[nums.at(l)] = false;
                    sc -= nums.at(l);
                    l++;
                }
                st[nums.at(l)] = false;
                sc -= nums.at(l);
                l++;
            }
            if(sc > max_sc){
                max_sc = sc;
            }
        }
        return max_sc;
        
    }
};
// @lc code=end

