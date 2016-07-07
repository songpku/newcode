/*
链表中环的入口结点
题目描述
一个链表中包含环，请找出该链表的环的入口结点。
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //解法一：使用无序map，时间复杂度为O(n),空间复杂度为O(n);
        /*
		unordered_set<ListNode*> us;
        while(pHead!=NULL){
            auto ret = us.insert(pHead);
            if(!ret.second)
                return pHead;
            pHead = pHead->next;
        }
        return NULL;*/
        //解法二：加上一个链表总长为n，环的长度为m，则不是环的部分长为n-m；
        //假设一个指针fast走了m步，则其还剩还需要走n-m+1不就到了环的入口
        //由于不是环的部分长为n-m，所以一个指针从头走到环的入口也是走n-m步；
        //故利用两个指针fast和slow，fast先走m步，然后两个指针同时走，相遇的地方即为环的入口
        //问题转化为求m：
        //从环中任意一个点开始走，下一次回到起点所走的步数即为m；
        //问题转化为求任一环中的节点：
        //如果一个链表存在环，一个指针每次走一步，另一个每次走两步，则两个指针一定会在环中相遇
        ListNode* pNodeInLoop = nodeInLoop(pHead);
        int m = loopLength(pNodeInLoop);
        if(m == 0)
            return NULL;
        ListNode* fast=pHead;
        ListNode* slow=pHead;
        for(int i=0;i<m;i++){
        	fast = fast->next;    
        }
        while(fast != NULL && slow != NULL){
            if(fast == slow)
                return fast;
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
    ListNode* nodeInLoop(ListNode* node){
        if(node == NULL)
            return NULL;
        ListNode* slow=node->next;
        if(slow == NULL)
            return NULL;
        ListNode* fast = slow->next;
        while(fast!=NULL && slow!=NULL){
            if(slow == fast){
                return fast;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL){
                return NULL;
            }
            fast = fast->next;
        }
        return NULL;
    }
    int loopLength(ListNode* pHead){
        if(pHead == NULL)
            return 0;
        ListNode* node=pHead->next;
        int len=1;
        while(node != NULL){
            if(node == pHead)
                break;
            ++len;
            node=node->next;
        }
        return len;
    }
};
