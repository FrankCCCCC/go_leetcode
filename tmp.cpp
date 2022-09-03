#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG 1
#define debug_cpp(s)\
if(DEBUG){\
    cout << s;\
}\

class Solution {
public:
    inline bool is_match(const string &s, int st, const string &p, int &e){
        for(int i = 0; i < p.size(); i++){
            if(st + i >= s.size() || s.at(st + i) != p.at(i)){
                e = -1;
                return false;
            }
        }
        e = st + p.size();
        return true;
    }
    
    inline bool solve(string &s, int st, vector<string>& wordDict){
        if(st >= s.size()){return true;}
        for(string p: wordDict){
            int end = 0;
            if(is_match(s, st, p, end)){
                // debug_cpp("Matched: " << end << endl);
                if(solve(s, end, wordDict)){
                    return true;
                }
            }
        }
        return false;
    }
    
    inline bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, 0, wordDict);
    }
};

int main(){
    Solution sln;
    vector<string> wordDict = {"leet", "code"};
    printf("%d\n", sln.wordBreak("leetcode", wordDict)? 1 : 0);
}