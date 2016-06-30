/*
��������ĸ���
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩,���Ƹ��������ء�
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		//����һ����������map������Ͻڵ�Ķ�Ӧ��ϵ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)
		/*
		if(pHead == NULL)
			return NULL;
		unordered_map<RandomListNode*,RandomListNode*> node2newNode;
		RandomListNode* node = pHead->next;
		RandomListNode* newHead = new RandomListNode(pHead->label);
		newHead->random = pHead->random;
		node2newNode[pHead] = newHead;
		RandomListNode* node2 = newHead;
		while(node!=NULL){
            RandomListNode* tmp = new RandomListNode(node->label);
            tmp->random=node->random;
            node2->next = tmp;
            node2newNode[node] = tmp;
            node = node->next;
            node2=node2->next;
		}
		node=pHead;
		while(node!=NULL){
            node->random = node2newNode[node->random];
            node = node->next;
		}
		return newHead;
		*/
		//����������clone�ĵ����ԭʼ��ĺ��棺A->A'->B->B'
        
		if (pHead == NULL)
			return NULL;
		RandomListNode *node = pHead;
		//��һ�������ƽڵ�nΪn'���ҽ�n'����n�ĺ���
		while (node != NULL){
			RandomListNode* cloneNode = new RandomListNode(node->label);
			cloneNode->next = node->next;
			//cloneNode->random = node->random;
			node->next = cloneNode;
			node = cloneNode->next;
		}
         
		//�ڶ������޸�n'��randomָ��
		node = pHead;
		RandomListNode* random;
		while (node != NULL){
			random = node->random;
            node = node->next;
			if(random!=NULL){
				node->random = random->next;
            }
			node = node->next;
		}
		//������:��clone��ԭʼ������룺
		RandomListNode* cHead = pHead->next;
		RandomListNode* cnode = cHead;
		node = pHead;
       
		while (cnode->next != NULL){
			node->next = cnode->next;
			cnode->next = cnode->next->next;
			node = node->next;
			cnode = cnode->next;
		}
        node->next=NULL; //����©��
		return cHead;
	}
};
