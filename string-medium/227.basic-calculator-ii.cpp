// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <list>
// #include "commoncppproblem227.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start

// class Node{
//     public:
//     enum Type {ADD, SUB, MUL, DIV, CONST, NONE};
//     int val;
//     Type type;
//     Node *right, *left;
    
//     Node(int val, Type type){
//         this->val = val;
//         this->type = type;
//         this->right = this->left = nullptr;
//     }
// };

// class Token{
//     public:
//     enum Type {ADD, SUB, MUL, DIV, CONST, NONE};
//     int val;
//     Type type;
    
//     Token(int val, Type type){
//         this->val = val;
//         this->type = type;
//     }
// };

// Node* factor(list<Token> &s){
//     string::size_type sz;
//     Node *root = new Node(s.front().val, Node::CONST);
//     s.pop_front();
//     return root;
// }

// Node* mul_div_expr(list<Token> &s){
//     Node *root = factor(s);
//     if(s.size() > 0){
//         if(s.front().type == Token::MUL){
//             s.pop_front();
//             Node *right = root;
//             root = new Node(0, Node::MUL);
//             root->right = right;
//             root->left = mul_div_expr(s);
//         }else if(s.front().type == Token::DIV){
//             s.pop_front();
//             Node *right = root;
//             root = new Node(0, Node::DIV);
//             root->right = right;
//             root->left = mul_div_expr(s);
//         }
//     }
//     return root;
// }

// Node* expr(list<Token> &s){
//     Node *root = mul_div_expr(s);
    
//     if(s.size() > 0){
//         if(s.front().type == Token::ADD){
//             s.pop_front();
//             Node *right = root;
//             root = new Node(0, Node::ADD);
//             root->right = right;
//             root->left = expr(s);
//         }else if(s.front().type == Token::SUB){
//             s.pop_front();
//             Node *right = root;
//             root = new Node(0, Node::SUB);
//             root->right = right;
//             root->left = expr(s);
//         }
//     }
//     return root;
// }

// int eval(Node *root){
//     if(root == nullptr) return 0;

//     switch(root->type){
//         case Node::ADD:
//         case Node::SUB:
//         case Node::MUL:
//         case Node::DIV: {
//             int lhs = eval(root->left);
//             int rhs = eval(root->right);
//             if(root->type == Node::ADD) return lhs + rhs;
//             if(root->type == Node::SUB) return lhs - rhs;
//             if(root->type == Node::MUL) return lhs * rhs;
//             if(root->type == Node::DIV) return lhs / rhs;
//         }
//         case Node::CONST:{
//             return root->val;
//         }
//     }
//     return 0;
// }

// class Solution {
// public:
//     int calculate(string s) {
//         for(int i = 0; i < s.size();){
//             if(s.at(i) == ' '){
//                 s.erase(i, 1);
//             }else i++;
//         }

//         list<Token> ls;
//         for(; s.size() > 0;){
//             Token tkn(0, Token::NONE);
//             if(isdigit(s.at(0))){
//                 string::size_type sz;
//                 tkn = Token(stoi(s, &sz), Token::CONST);
//                 s = s.substr(sz);
//             }else{
//                 switch(s.at(0)){
//                     case '+': 
//                         tkn = Token(0, Token::ADD);
//                         break;
//                     case '-': 
//                         tkn = Token(0, Token::SUB);
//                         break;
//                     case '*': 
//                         tkn = Token(0, Token::MUL);
//                         break;
//                     case '/': 
//                         tkn = Token(0, Token::DIV);
//                         break;
//                 }
//                 s.erase(0, 1);
//             }
//             ls.push_back(tkn);
//         }
//         ls.reverse();

//         // string::iterator r_it = remove(s.begin(), s.end(), ' ');
//         // s.erase(r_it, s.end());

//         Node *root = expr(ls);
//         return eval(root);
//     }
// };

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int num = 0, n = s.size();
        char op = '+';
        for(int i = 0; i < n; i++){
            if(isdigit(s.at(i))){
                num = num * 10 + (s.at(i) - '0');
            }
            
            if(s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/' || i == n - 1){
                switch(op){
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    case '/':
                        stk.back() /= num;
                        break;
                }
                num = 0;
                op = s.at(i);
            }
        }
        
        int res = 0;
        for(auto x: stk){
            res += x;
        }
        
        return res;
    }
};

/**
Testcases

"3"
"3+2"
"3*2"
"4/2"
"3+2*2"
"3+2*2"
" 3+2 *2 + 3"
" 1- 3*3-4 /2 + 3"
"1- 2- 1 * 3 /2 * 8 - 2 +1 *3 -2 +2 *2 -1 *3"
"3"
" 3 -2"
**/
// @lc code=end

