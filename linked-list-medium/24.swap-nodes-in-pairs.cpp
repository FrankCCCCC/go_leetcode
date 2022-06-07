// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmp = head;
        for(int i = 0; tmp != nullptr; tmp = tmp->next, i++){
            if(i % 2 == 0 && tmp->next != nullptr){
                swap(tmp->val, tmp->next->val);
            }
        }
        
        return head;
    }
};

/**
Testcases

[1,2,3,4,5,6]
[1,2,3,4,5]
[1,2,3,4]
[1,2,3]
[1,2]
[1]
[]
**/
// @lc code=end

