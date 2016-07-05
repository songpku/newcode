/*
��������ĵ�һ���������
��Ŀ����
�������������ҳ����ǵĵ�һ��������㡣
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
        //����˼·��
        //����ͼ��ʾ�������������й����ڵ㣬�������ձض���Ϊͬһ��·�����������������ĳ���len1,len2
        //�ó���һ������|len1-len2|����Ȼ������һ����,��һ����ͬʱ���﹫���ڵ㡣
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
        //������:����������ֱ�ѹջ��Ȼ���ջ���������һ����ͬ�ĵ㼴Ϊ��һ�������ڵ㡣
    }
};
