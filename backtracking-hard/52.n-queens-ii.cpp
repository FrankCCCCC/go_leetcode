/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

bool valid(const vector<string> &b, const int r, const int c, const int n){
    // Horizontal
    for(int i = 0; i < n; i++){
        if(i != c && b.at(r).at(i) == 'Q') return false;
    }
    // Vertical
    for(int i = 0; i < n; i++){
        if(i != r && b.at(i).at(c) == 'Q') return false;
    }
    // Diagonal
    int min = r < c? r : c;
    for(int i = r - min, j = c - min; i < n && j < n; i++, j++){
        if(i != r && j != c && b.at(i).at(j) == 'Q') return false;
    }
    
    min = r < (n - c - 1)? r : (n - c - 1);
    for(int i = r - min, j = c + min; i < n && j >= 0; i++, j--){
        if(i != r && j != c && b.at(i).at(j) == 'Q') return false;
    }
    return true;
}

int solve(vector<string> &b, const int idx, const int n){
    if(idx >= n) return 1;
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        b.at(idx).at(i) = 'Q';
        if(valid(b, idx, i, n)){
            cnt += solve(b, idx + 1, n);
        }
        b.at(idx).at(i) = '.';
    }
    return cnt;
}

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> b(n, string(n, '.'));
        return solve(b, 0, n);
    }
};

/**
Testecases

1
2
3
4
**/
// @lc code=end

