/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 1000

char *convert(char * s, int numRows){
    int mod = numRows * 2 - 2, strLen = 0, zigZagIdx = 0;
    for(;s[strLen] != '\0'; strLen++){}
    char *zigZagStr = (char*)malloc(sizeof(char) * (strLen + 1));
    // printf("StrLen: %d\n", strLen);

    // If numRows == 1 or 0 return original string
    if(numRows < 2){
        strncpy(zigZagStr, s, strLen + 1);
        return zigZagStr;
    }
    
    // Head
    for(int i = 0; i < strLen && zigZagIdx < strLen; i += mod, zigZagIdx++){
        zigZagStr[zigZagIdx] = s[i];
        // printf("Head [%d]:%c <- [%d]:%c\n", zigZagIdx, zigZagStr[zigZagIdx], i, s[i]);
    }

    // ZigZag
    for(int gap = mod - 2, base = 1; gap > 0 && base < numRows; gap -= 2, base++){
        for(int i = base; i < strLen && zigZagIdx < strLen;){
            // ZigZag vertical
            if(i < strLen){
                zigZagStr[zigZagIdx] = s[i];
                // printf("ZigZag Vertical [%d]:%c <- [%d]:%c\n", zigZagIdx, zigZagStr[zigZagIdx], i, s[i]);
                zigZagIdx++;
            }
            // ZigZag Slope
            if(i + gap < strLen){
                zigZagStr[zigZagIdx] = s[i + gap];
                // printf("ZigZag Slope [%d]:%c <- [%d]:%c\n", zigZagIdx, zigZagStr[zigZagIdx], i + gap, s[i + gap]);
                zigZagIdx++;
            }
            i += mod;
        }
    }

    // Tail
    for(int i = numRows - 1; i < strLen && zigZagIdx < strLen; i += mod, zigZagIdx++){
        zigZagStr[zigZagIdx] = s[i];
        // printf("Tail [%d]:%c <- [%d]:%c\n", zigZagIdx, zigZagStr[zigZagIdx], i, s[i]);
    }
    zigZagStr[strLen] = '\0';

    return zigZagStr;
}

int main(){
    char str[STR_LEN] = {0};
    int numRows = 0;
    scanf("%s", str);
    scanf("%d", &numRows);
    printf("%s\n", convert(str, numRows));

    return 0;
}