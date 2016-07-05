/*
ƽ�������
��Ŀ����
����һ�ö��������жϸö������Ƿ���ƽ������������ĳ������������ڵ���������������������1����Ϊƽ�����������
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
