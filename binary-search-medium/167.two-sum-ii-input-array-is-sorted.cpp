// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem167.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        for(; l < r;){
            int sum = numbers.at(l) + numbers.at(r);
            if(sum > target){
                r--;
            }else if(sum < target){
                l++;
            }else{
                return vector<int>({l + 1, r + 1});
            }
        }
        return vector<int>({0, 0});
    }
};

/**
Testcases

[2,7,11,15]
9
[2,3,4]
6
[-1,0]
-1
[0,0]
0
[0,1,1,2,2,5]
5
**/
// @lc code=end

