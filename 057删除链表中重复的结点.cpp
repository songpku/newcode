/*
ɾ���������ظ��Ľ��
��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode *ret = new ListNode(0);
		ret->next = pHead;
		ListNode *pre = ret;
		ListNode* node = pHead;
		bool needDel = false;
		while (pre->next !=NULL && node->next != NULL){
			needDel = false;
			while (node->next != NULL && pre->next->val == node->next->val){
				node = node->next;
				needDel = true;
			}
			if (needDel){
                ListNode* pDel = pre->next;
				if (node->next == NULL){
                    while(pDel != NULL){
                        ListNode* tmp = pDel;
                        pDel=pDel->next;
                        delete tmp;
                	}
					pre->next = NULL;
				}
				else{
                    ListNode* pDelEnd = node->next;
                    while(pDel != NULL && pDel->val != pDelEnd->val){
                        ListNode* tmp = pDel;
                        pDel=pDel->next;
                        delete tmp;
                	}
					pre->next = pDelEnd;
					node = pDelEnd;
                    //pre->next = node->next;
					//node = node->next;
				}
                
			}
			else{
				pre = pre->next;
				node = node->next;
			}
		}
		ListNode *del = ret;
		ret = ret->next;
		delete del;
		return ret;
	}
};
