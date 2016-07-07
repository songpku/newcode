/*
二叉树的下一个结点
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/
using namespace std;
using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    { //中序，即，左中右
/*    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11    */
        //如上图中序遍历为5,6,7,8,9,10,11
        //1、存在右孩子，则为右孩子的最左节点
        //2、不存在右孩子，则为左孩子的祖先节点的父节点。
        if(pNode == NULL)
            return NULL;
        if(pNode->right != NULL){
            pNode = pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
        TreeLinkNode* pa=pNode->next;
        TreeLinkNode* child = pNode;
        while(pa!=NULL){
            if(pa->left == child)
                return pa;
            child = pa;
            pa = pa->next;
        }
        return NULL;
    }
};
