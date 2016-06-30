/*从尾到头打印链表

题目描述
输入一个链表，从尾到头打印链表每个节点的值。
输入描述:

输入为链表的表头



输出描述:

输出为需要打印的“新链表”的表头
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        //解法一：FILO使用栈
        /*
        stack<int> stk;
        ListNode* node=head;
        while(node != NULL){
            stk.push(node->val);
            node = node->next;
        }
        vector<int> ret;
        while(!stk.empty()){
            ret.push_back(stk.top());
            stk.pop();
        }
        
        return ret;
        */
        //解法二：能使用栈就必然能使用递归，但是由于可能栈溢出，所以还是第一种解法好一些。
        vector<int> ret;
        ListNode* node = head;
        solve(ret,node);
        return ret;
    }
    void solve(vector<int> &ret,ListNode *head){
        if(head == NULL)
            return;
        solve(ret,head->next);
        ret.push_back(head->val);
    }
};
