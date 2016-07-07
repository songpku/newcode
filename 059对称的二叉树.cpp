/*
�ԳƵĶ�����
��Ŀ����
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/ 
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
        /*   8   
    	   /  \
    	  6   6
    	 / \  / \
    	5  7 7  5    
        ����ͼ�����Կ��������ұ���������������Ľ����ͬ��Ϊ�Գƣ����򲻶Գ�*/
        return isSymmetrical(pRoot,pRoot);
	}
    bool isSymmetrical(TreeNode* n1,TreeNode* n2){
        if(n1 == NULL && n2 == NULL)
            return true;
        if(n1 == NULL || n2 == NULL)
            return false;
        if(n1->val != n2->val)
            return false;
        return isSymmetrical(n1->left,n2->right) && 
               isSymmetrical(n1->right,n2->left);
    }

};
