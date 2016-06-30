/*
从上往下打印二叉树
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		queue<TreeNode*> que;
        vector<int> ret;
        TreeNode *node = root;
        if(node==NULL)
            return ret;
        que.push(node);
        while(!que.empty()){
            node = que.front();
            que.pop();
            ret.push_back(node->val);
            if(node->left != NULL)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
        return ret;
    }
};
