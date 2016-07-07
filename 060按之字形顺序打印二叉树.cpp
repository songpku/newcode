/*
��֮����˳���ӡ������
��Ŀ����
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if (pRoot == NULL)
			return ret;
		queue<TreeNode*> que;
		TreeNode* end = NULL;
		//TreeNode* node=pRoot;
		if (pRoot->left != NULL){
			end = pRoot->left;
		}
		else if (pRoot->right != NULL){
			end = pRoot->right;
		}
		que.push(pRoot);
        vector<int> line;
        bool l2r = true;
		while (!que.empty()){
			TreeNode* node = que.front(); que.pop();
			if (end != NULL && node == end){
                if(l2r){
                	ret.push_back(line);
                }else{
                    vector<int> r2l(line.rbegin(),line.rend());
                    ret.push_back(r2l);
                }
                l2r = !l2r;
                line.clear();
                end=NULL;
			}
            line.push_back(node->val);
			if (node->left != NULL){
				que.push(node->left);
				if (end == NULL){
					end = node->left;
				}
			}
			if (node->right != NULL){
				que.push(node->right);
				if (end == NULL){
					end = node->right;
				}
			}
		}
        if(line.size()>0){
            if(l2r){
                ret.push_back(line);
            }else{
                vector<int> r2l(line.rbegin(),line.rend());
                ret.push_back(r2l);
            }
        }
		return ret;
    }
    
};
