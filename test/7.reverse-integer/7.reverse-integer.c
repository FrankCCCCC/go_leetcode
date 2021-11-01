/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *str){
    int strLen = 0;
    for(; str[strLen] != '\0'; strLen++){}
    for(int l = 0, r = strLen - 1; l < r; l++, r--){
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;
    }
}

int reverse(int x){
    const long long INTEGER32_MAX = 2147483648 - 1;
    const long long INTEGER32_MIN = -2147483648;

    // Convert int to string
    char x_str[70] = {0};
    long long long_x = (long long)x;
    if(x < 0){
        sprintf(x_str, "%lld", -long_x);
    }else{
        sprintf(x_str, "%lld", long_x);
    }

    // Reverse string
    strrev(x_str);

    // Check whether exceed
    int isExceed = 0;
    long long revNum = 0;
    if(long_x < 0){
        revNum = -atoll(x_str);
        if(revNum <= INTEGER32_MIN){
            isExceed = 1;
        }
    }else{
        revNum = atoll(x_str);
        if(revNum >= INTEGER32_MAX){
            isExceed = 1;
        }
    }
    // Return 0 if overflow or underflow
    if(isExceed){
        return 0;
    }else{
        return (int)revNum;
    }
}

int main(){
    int x = 0;
    scanf("%d", &x);
    printf("%d\n", reverse(x));
}