/*
�����������
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�*/
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
