// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tA = headA, *tB = headB;
        for(tA = headA; tA != nullptr; lenA++, tA = tA->next){}
        for(tB = headB; tB != nullptr; lenB++, tB = tB->next){}
        
        int len_min = lenA < lenB? lenA : lenB;
        tA = headA;
        if(len_min < lenA){
            for(int i = 0; i < lenA - len_min; i++, tA = tA->next){}
        }
        
        tB = headB;
        if(len_min < lenB){
            for(int i = 0; i < lenB - len_min; i++, tB = tB->next){}
        }
        
        for(int i = 0; i < len_min; i++, tA = tA->next, tB = tB->next){
            if(tA == tB) return tA;
        }
        return nullptr;
    }
};

/**
Testcases

8
[4,1,8,4,5]
[5,6,1,8,4,5]
2
3
2
[1,9,1,2,4]
[3,2,4]
3
1
0
[2,6,4]
[1,5]
3
2
2
[1,9,1,2,4]
[2,4]
3
0
**/
// @lc code=end

