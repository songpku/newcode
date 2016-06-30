/*
������������˫������
��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
/*
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	����������
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //����˼·��listΪ˫������listΪβָ��
        TreeNode* node = pRootOfTree;
        TreeNode* list = NULL;
        Tree2List(node,&list);
        while(list != NULL && list->left != NULL){
            list = list->left;
        }
        return list;
    }
    void Tree2List(TreeNode* node,TreeNode **list){
        if(node == NULL)
            return;
        TreeNode* cur=node;
        if(cur->left != NULL){
            Tree2List(cur->left,list);  //����ͼ�У�curΪ8����������������*list��ָ����7
        }
        cur->left = *list;  //��ǰ��8���������Ѿ����꣬���������������ֵ�Ѿ�������˫��������βָ��ָ��7
        if(*list!=NULL){ //����ǰ����뵱βָ��ĺ���
            (*list)->right = cur;
        }
        *list = cur; //����βָ�룬ָ��ǰ�㣻��������Ҫ�ı�ָ������ݣ�������Ҫʹ��˫��ָ�룩��
        if(cur->right != NULL){ //����������
            Tree2List(cur->right,list);
        }
    }
};
