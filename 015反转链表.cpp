/*
反转链表
题目描述
输入一个链表，反转链表后，输出链表的所有元素。
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
       	//方法一：使用栈
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
       //方法二：利用前，中，后三个指针直接反转，更加简洁直接
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
