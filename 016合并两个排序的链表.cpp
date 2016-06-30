/*
�ϲ��������������
��Ŀ����
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //����һ���鲢����
        /*
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode* pRet=NULL;
        ListNode* pNode1=pHead1;
        ListNode* pNode2=pHead2;
        if(pHead1->val <= pHead2->val){
            pRet = pHead1;
            pNode1=pHead1->next;
        }else{
            pRet=pHead2;
            pNode2=pHead2->next;
        }
        ListNode* pNode=pRet;
        while(pNode1!=NULL && pNode2!=NULL){
            if(pNode1->val<=pNode2->val){
                pNode->next = pNode1;
                pNode1=pNode1->next;
            }else{
                pNode->next = pNode2;
                pNode2=pNode2->next;
            }
            pNode=pNode->next;
        }
        if(pNode1 != NULL){
            pNode->next=pNode1;
        }else{
            pNode->next=pNode2;
        }
        return pRet;
        */
        //���������ݹ�,��ֱ��
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode* pRet=NULL;
        if(pHead1->val <= pHead2->val){
            pRet = pHead1;
            pRet->next = Merge(pHead1->next,pHead2);
        }else{
            pRet=pHead2;
            pRet->next = Merge(pHead1,pHead2->next);
        }
        return pRet;
    }
};
