/*
两个链表的第一个公共结点
题目描述
输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        //解题思路：
        //如下图所示，若两个链表有公共节点，则其最终必定变为同一条路径，先求出两条链表的长度len1,len2
        //让长的一条先走|len1-len2|步，然后两条一起走,则一定能同时到达公共节点。
        /*2->4->6->5\
                     8->6->10
                3->4/              */
        ListNode *node1=pHead1;
        ListNode *node2=pHead2;
        int len1=0,len2=0;
        while(node1!=NULL){
            ++len1;
            node1=node1->next;
        }
        while(node2!=NULL){
            ++len2;
            node2=node2->next;
        }
        node1=pHead1;
        node2=pHead2;
        if(len1>len2){
            for(int i=0;i<len1-len2;i++){
                node1=node1->next;
            }
        }else{
            for(int i=0;i<len2-len1;i++){
                node2=node2->next;
            }
        }
        while(node1!=NULL && node2!=NULL){
            if(node1 == node2){
                return node1;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        return NULL;
        //方案二:将两个链表分别压栈，然后出栈，遇到最后一个相同的点即为第一个公共节点。
    }
};
