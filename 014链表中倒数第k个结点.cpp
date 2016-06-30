/*
链表中倒数第k个结点
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
		if (i<k) //判断是否总长度小于K
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
//技巧：对于链表题，一个指针不能解决的问题，可以考虑用两个，一快一慢。 
