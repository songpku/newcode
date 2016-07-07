/*
对称的二叉树
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
        如上图，可以看出左中右遍历和右中左遍历的结果相同则为对称，否则不对称*/
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
