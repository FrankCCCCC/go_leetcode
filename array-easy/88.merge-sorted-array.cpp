// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n <= 0) return;
        for(int i = m - 1; i >= 0; i--){
            nums1.at(i + n) = nums1.at(i);
        }
        
        for(int i = 0, j = n, k = 0; i < m + n && k < n; i++){
            if((j < n + m && k < n && nums1.at(j) < nums2.at(k))){
                int x = nums1.at(j);
                nums1.at(i) = x;
                j++;
            }else if(k < n){
                int x = nums2.at(k);
                nums1.at(i) = x;
                k++;
            }
        }
    }
};

/**
Testcases

[1,2,4,5,6,0]
5
[3]
1
[4,5,6,0,0,0]
3
[1,2,3]
3
[1,2,3,0,0,0]
3
[2,5,6]
3
[1]
1
[]
0
[0]
0
[1]
1
**/
// @lc code=end

