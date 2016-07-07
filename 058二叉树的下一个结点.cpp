/*
����������һ�����
��Ŀ����
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/
using namespace std;
using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    { //���򣬼���������
/*    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11    */
        //����ͼ�������Ϊ5,6,7,8,9,10,11
        //1�������Һ��ӣ���Ϊ�Һ��ӵ�����ڵ�
        //2���������Һ��ӣ���Ϊ���ӵ����Ƚڵ�ĸ��ڵ㡣
        if(pNode == NULL)
            return NULL;
        if(pNode->right != NULL){
            pNode = pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
        TreeLinkNode* pa=pNode->next;
        TreeLinkNode* child = pNode;
        while(pa!=NULL){
            if(pa->left == child)
                return pa;
            child = pa;
            pa = pa->next;
        }
        return NULL;
    }
};
