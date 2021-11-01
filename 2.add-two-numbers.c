/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *now_digit_l1 = l1, *now_digit_l2 = l2;
    struct ListNode *last_digit = NULL, *head_digit = NULL;
    int carry = 0, digit_count = 0;

    while(now_digit_l1 != NULL || now_digit_l2 != NULL){
        struct ListNode *new_digit = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_digit->next = NULL;
        if(last_digit != NULL){
            last_digit->next = new_digit;
        }
        last_digit = new_digit;

        if(digit_count == 0){
            head_digit = new_digit;
        }

        // Add List1
        if(now_digit_l1 != NULL){
            new_digit->val = now_digit_l1->val;
            now_digit_l1 = now_digit_l1->next;
        }else{
            new_digit->val = 0;
        }

        // Add List2
        if(now_digit_l2 != NULL){
            new_digit->val += now_digit_l2->val;
            now_digit_l2 = now_digit_l2->next;
        }else{
            new_digit->val += 0;
        }

        // Add Carry
        new_digit->val += carry;

        if(new_digit->val > 9){
            carry = 1;
            new_digit->val -= 10;
        }else{
            carry = 0;
        }

        digit_count++;
    }
    if(carry){
        struct ListNode *new_digit = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_digit->val = 1;
        new_digit->next = NULL;
        if(last_digit != NULL){
            last_digit->next = new_digit;
        }
    }

    return head_digit;
}
// @lc code=end