/*
�����е�����k�����
��Ŀ����
����һ����������������е�����k����㡣
*/
#include<iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* lastK, *node;
		node = lastK = pListHead;
		int i = 0;
		for (; i<k&&lastK != NULL; i++){
			lastK = lastK->next;
		}
		if (i<k) //�ж��Ƿ��ܳ���С��K
			return NULL;
		while (lastK != NULL){
			lastK = lastK->next;
			node = node->next;
		}
		return node;
	}
};
int main(){
	ListNode* head=new ListNode(0);
	ListNode* node=head;
	for(int i=1;i<10;i++){
		ListNode *n = new ListNode(i);
		node->next=n;
		node = node->next;
	}
	Solution s;
	s.FindKthToTail(head,3);
}
//���ɣ����������⣬һ��ָ�벻�ܽ�������⣬���Կ�����������һ��һ���� 
