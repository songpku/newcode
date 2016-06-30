/*
二叉搜索树与双向链表
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    	搜索二叉树
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //解题思路：list为双向链表，list为尾指针
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
            Tree2List(cur->left,list);  //如上图中，cur为8，处理完左子树后*list就指向了7
        }
        cur->left = *list;  //当前点8的左子树已经求完，所以左子树的最大值已经存入了双向链表，即尾指针指向7
        if(*list!=NULL){ //将当前点存入当尾指针的后面
            (*list)->right = cur;
        }
        *list = cur; //更新尾指针，指向当前点；（这里需要改变指针的内容，所以需要使用双重指针）。
        if(cur->right != NULL){ //处理右子树
            Tree2List(cur->right,list);
        }
    }
};
