/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    const int max_map_size = 300;
    for(int substr_len = 1; s[substr_len - 1] != ''; substr_len++){
        int map[max_map_size] = {0};

        for(int i = 0; s[i] != ''; i++){
            map[(int)s[i]]++;
        }
    }
}
// @lc code=end

