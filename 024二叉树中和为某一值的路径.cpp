/*
�������к�Ϊĳһֵ��·��
��Ŀ����
����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
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
