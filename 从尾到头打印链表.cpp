/*��β��ͷ��ӡ����

��Ŀ����
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
��������:

����Ϊ����ı�ͷ



�������:

���Ϊ��Ҫ��ӡ�ġ��������ı�ͷ
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
        //�ⷨһ��FILOʹ��ջ
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
        //�ⷨ������ʹ��ջ�ͱ�Ȼ��ʹ�õݹ飬�������ڿ���ջ��������Ի��ǵ�һ�ֽⷨ��һЩ��
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
