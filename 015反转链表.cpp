/*
��ת����
��Ŀ����
����һ��������ת�����������������Ԫ�ء�
*/ 
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
   ListNode* ReverseList(ListNode* pHead) {
       	//����һ��ʹ��ջ
       /*
		if (pHead == NULL)
			return NULL;
		stack<ListNode*> stk;
		ListNode* node = pHead;
		while (node->next != NULL){
			stk.push(node);
			node = node->next;
		}
		ListNode* ret = node;
		ListNode* tmp;
		node = ret;
		while (!stk.empty()){
			tmp = stk.top();
			tmp->next = NULL;
			stk.pop();
			node->next = tmp;
			node = node->next;
		}
		return ret;*/
       //������������ǰ���У�������ָ��ֱ�ӷ�ת�����Ӽ��ֱ��
       ListNode* pPre=NULL;
       ListNode* pNode=pHead;
       ListNode* pNext=NULL;
       ListNode* pRet=NULL;
       while(pNode!=NULL){
           if(pNode->next == NULL){
               pRet=pNode;
           }
           pNext = pNode->next;
           pNode->next = pPre;
           pPre = pNode;
           pNode = pNext;
       }
       return pRet;
	}
};
