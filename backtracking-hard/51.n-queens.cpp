/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

bool is_valid(const vector<string> &b, const int r, const int c, const int n){
    // Horizontal
    for(int i = 0; i < n; i++){
        if(i != c && b.at(r).at(i) == 'Q'){
            return false;
        }
    }
    // Vertical
    for(int i = 0; i < n; i++){
        if(i != r && b.at(i).at(c) == 'Q'){
            return false;
        }
    }
    // Diagonal
    int min = r < c? r : c;
    for(int i = r - min, j = c - min; i < n && j < n; i++, j++){
        if(i != r && j != c && b.at(i).at(j) == 'Q'){
            return false;
        }
    }
    min = r < n - c - 1? r : n - c - 1;
    for(int i = r - min, j = c + min; i < n && j >= 0; i++, j--){
        if(i != r && j != c && b.at(i).at(j) == 'Q'){
            return false;
        }
    }
    
    return true;
}

class Solution {
public:
    void solve(vector<vector<string>> &res, vector<string> &b, int idx, int n){
        if(idx >= n){
            res.push_back(b);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(is_valid(b, idx, i, n)){
                b.at(idx).at(i) = 'Q';
                solve(res, b, idx + 1, n);
                b.at(idx).at(i) = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n, string(n, '.'));
        solve(res, b, 0, n);
        return res;
    }
};

/**
Testcases

4
3
2
1
**/
// @lc code=end

