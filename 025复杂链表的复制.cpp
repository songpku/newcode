/*
复杂链表的复制
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）,复制该链表并返回。
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		//方法一：利用无序map存放新老节点的对应关系。时间复杂度为O(n),空间复杂度为O(n)
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
		//方法二：将clone的点放在原始点的后面：A->A'->B->B'
        
		if (pHead == NULL)
			return NULL;
		RandomListNode *node = pHead;
		//第一步：复制节点n为n'并且将n'接在n的后面
		while (node != NULL){
			RandomListNode* cloneNode = new RandomListNode(node->label);
			cloneNode->next = node->next;
			//cloneNode->random = node->random;
			node->next = cloneNode;
			node = cloneNode->next;
		}
         
		//第二步：修改n'的random指针
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
		//第三步:将clone和原始链表分离：
		RandomListNode* cHead = pHead->next;
		RandomListNode* cnode = cHead;
		node = pHead;
       
		while (cnode->next != NULL){
			node->next = cnode->next;
			cnode->next = cnode->next->next;
			node = node->next;
			cnode = cnode->next;
		}
        node->next=NULL; //容易漏掉
		return cHead;
	}
};
