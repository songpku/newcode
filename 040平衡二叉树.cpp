/*
平衡二叉树
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树（如果某二叉树的任意节点的左右子树的深度相差不超过1，则为平衡二叉树）。
*/ 
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(childTreeDeep(pRoot)<INT_MAX)
            return true;
        return false;
    }
    int childTreeDeep(TreeNode* node){
        if(node == NULL)
            return 0;
        int dpLeft = childTreeDeep(node->left);
        int dpRight = childTreeDeep(node->right);
        if(abs(dpLeft-dpRight) > 1)
            return INT_MAX;
        return max(dpLeft,dpRight)+1;
    }
};
