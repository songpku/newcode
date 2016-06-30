/*
�������´�ӡ������
��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
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
