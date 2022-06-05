/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

int idx(int n){
    for(int i = 0; i < 32; i++){
        if((n >> i) & 1){
            return i;
        }
    }
    return -1;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        int code = 0, idx_num = 0;
        vector<int> res;

        for(int i = 0; i < pow(2, n); i++){
            res.push_back(code);
            idx_num++;
            code = code ^ ((int)pow(2, idx(idx_num)));
        }

        return res;
    }
};

/**
Testcases

1
2
3
4
**/
// @lc code=end

