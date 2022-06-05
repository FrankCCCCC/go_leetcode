/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix.at(i).at(j), matrix.at(j).at(i));
            }
        }
    }
};

/**
Testcases

[[1,2,3],[4,5,6],[7,8,9]]
[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
**/
// @lc code=end

