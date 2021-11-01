/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start


char * longestPalindrome(char * s){
    // int s_len = sizeof(s) / sizeof(char);
    int s_len = 0;
    int max_panlindrom_len = 0, max_panlindrom_l = 0, max_panlindrom_r = 0;
    for(int i = 0; s[i] != '\0'; i++){
        s_len++;
    }
    // printf("S_Len: %d\n", s_len);

    for(int center_idx = 0; center_idx < s_len; center_idx++){
        int panlindrom_len = -1, l = 0, r = 0;
        // Odd Panlidrome
        for(l = center_idx, r = center_idx; l >= 0 && r < s_len; l--, r++){
            if(s[l] == s[r]){
                panlindrom_len += 2;
            }else{
                break;
            }
        }
        // printf("Center[%d]: %c: Panlidrome Len: %d\n", center_idx, s[center_idx], panlindrom_len);
        
        if(max_panlindrom_len < panlindrom_len){
            max_panlindrom_len = panlindrom_len;
            max_panlindrom_l = l + 1;
            max_panlindrom_r = r - 1;
        }
        // printf("Max Panlidrome Len: %d, [%d | %d]: %c | %c\n", panlindrom_len, max_panlindrom_l, max_panlindrom_r, s[max_panlindrom_l], s[max_panlindrom_r]);

        // Even Panlidrome
        panlindrom_len = 0;
        for(l = center_idx, r = center_idx + 1; l >= 0 && r < s_len; l--, r++){
            if(s[l] == s[r]){
                panlindrom_len += 2;
            }else{
                break;
            }
        }
        if(max_panlindrom_len < panlindrom_len){
            max_panlindrom_len = panlindrom_len;
            max_panlindrom_l = l + 1;
            max_panlindrom_r = r - 1;
        }
    }
    int panlidom_size = max_panlindrom_len + 1;
    char *panlindrom = (char*)malloc(sizeof(char) * panlidom_size);
    for(int i = max_panlindrom_l; i <= max_panlindrom_r; i++){
        panlindrom[i - max_panlindrom_l] = s[i];
    }
    panlindrom[max_panlindrom_len] = '\0';
    return panlindrom;
}
// @lc code=end
