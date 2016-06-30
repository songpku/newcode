/*
树的子结构
题目描述
输入两颗二叉树A，B，判断B是不是A的子结构。*/
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool ret = false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1->val == pRoot2->val)
                ret = Tree1HasTree2(pRoot1,pRoot2);
            if(!ret)
                ret = HasSubtree(pRoot1->left,pRoot2);
            if(!ret)
                ret = HasSubtree(pRoot1->right,pRoot2);
        }
        return ret;
    }
    bool Tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return Tree1HasTree2(pRoot1->left,pRoot2->left) && Tree1HasTree2(pRoot1->right,pRoot2->right);
    }
};

