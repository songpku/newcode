/*
重建二叉树

题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

*/

#include<cstdio>
#include<vector>
using namespace std;
 //Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    void solve(TreeNode* node, vector<int> &pre, vector<int> &in, int preL, int preR, int inL, int inR){
		//printf("root = %d,left=%d,right=%d\n", pre[preL], preL, preR);
		int rootVal = pre[preL];
		int rootIndex;
		for (rootIndex = inL; rootIndex <= inR; rootIndex++){
			if (rootVal == in[rootIndex])
				break;
		}
		int sizeL = rootIndex - inL;
		int sizeR = inR - rootIndex;
		//node = new TreeNode(rootVal);
		if (sizeL>0){
			TreeNode* nodeTmp = new TreeNode(pre[preL + 1]);
			node->left = nodeTmp;
			solve(node->left, pre, in, preL + 1, preL + sizeL, inL, rootIndex - 1);
		}
		if (sizeR>0){
			TreeNode* nodeTmp = new TreeNode(pre[preL + sizeL + 1]);
			node->right = nodeTmp;
			solve(node->right, pre, in, preL + sizeL + 1, preR, rootIndex + 1, inR);
		}
	}
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        if(pre.size()==0)
            return NULL;
		TreeNode* ret = new TreeNode(pre[0]);
		solve(ret, pre, in, 0, pre.size() - 1, 0, pre.size() - 1);
		return ret;
	}
};
int main(){
	TreeNode *ret;
	vector<int> pre = {1,2,4,7,3,5,6,8}; 
	vector<int> in = {4,7,2,1,5,3,8,6};
	int index =0;
	Solution s; 
    s.reConstructBinaryTree(pre,in);
    return 0;
}
//{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6} 
