/*
�����л�����ڽ��
��Ŀ����
һ�������а����������ҳ�������Ļ�����ڽ�㡣
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
        //�ⷨһ��ʹ������map��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n);
        /*
		unordered_set<ListNode*> us;
        while(pHead!=NULL){
            auto ret = us.insert(pHead);
            if(!ret.second)
                return pHead;
            pHead = pHead->next;
        }
        return NULL;*/
        //�ⷨ��������һ�������ܳ�Ϊn�����ĳ���Ϊm�����ǻ��Ĳ��ֳ�Ϊn-m��
        //����һ��ָ��fast����m�������仹ʣ����Ҫ��n-m+1���͵��˻������
        //���ڲ��ǻ��Ĳ��ֳ�Ϊn-m������һ��ָ���ͷ�ߵ��������Ҳ����n-m����
        //����������ָ��fast��slow��fast����m����Ȼ������ָ��ͬʱ�ߣ������ĵط���Ϊ�������
        //����ת��Ϊ��m��
        //�ӻ�������һ���㿪ʼ�ߣ���һ�λص�������ߵĲ�����Ϊm��
        //����ת��Ϊ����һ���еĽڵ㣺
        //���һ��������ڻ���һ��ָ��ÿ����һ������һ��ÿ����������������ָ��һ�����ڻ�������
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
