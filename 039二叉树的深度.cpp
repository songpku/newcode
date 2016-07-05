/*
二叉树的深度
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	return childTreeDeep(pRoot);
    }
    int childTreeDeep(TreeNode* node){
        if(node == NULL)
            return 0;
        int dpLeft = childTreeDeep(node->left);
        int dpRight = childTreeDeep(node->right);
        return max(dpLeft,dpRight)+1;
    }
};
