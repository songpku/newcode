/*
二叉树中和为某一值的路径
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/ 
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        vector<int> path;
        FindPath(ret,path,root,expectNumber,0);
		return ret;
    }
    void FindPath(vector<vector<int> >&ret,vector<int> &path,TreeNode* node,int en,int cn){
        cn += node->val;
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL && cn == en){
            ret.push_back(path);
        }
        if(node->left != NULL && cn < en){
            FindPath(ret,path,node->left,en,cn);
        }
        if(node->right != NULL && cn < en){
            FindPath(ret,path,node->right,en,cn);
        }
        path.pop_back();
        
    }
};
