/*
`
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
            return false;
        //方案一：先将seq排序，排序后的数组in就是中序遍历，然后根据中序遍历和后序遍历递归判断
        /*
		vector<int> in(sequence.begin(),sequence.end());
        sort(in.begin(),in.end());
        return VerifyTreeOfBST(in,sequence,0,sequence.size()-1,0,sequence.size()-1);
        */
        //方案二(更加简单直接)：利用后序最后一个是根节点的特点，在[0，r)中查找第一个大于a[r]的元素下标i,
        //a[l,i)则为左子树，a[i,r)则为右子树。遍历a(i,r)若存在元素小于a[r]则返回false。
        return VerifyTreeOfBST2(sequence,0,sequence.size()-1);
    }
    bool VerifyTreeOfBST(vector<int> &in,vector<int> &seq,int il,int ir,int sl,int sr){
        int val = seq[sr];
        int i=il;
        for(;i<=ir;i++){
            if(in[i] == val)
                break;
        }
        if(i>ir)//对于根节点val在中序in中，il~ir段找不到对应的val则说明不满足条件。
            return false;
        bool ret=true; //默认是false，要注意。
        if(i != il)
            ret=VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1);
        if(i != ir)
            ret&=VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        return ret;
    }
    bool VerifyTreeOfBST2(vector<int> &seq,int l,int r){
        int val = seq[r];
        int i=l;
        for(;i<r;i++){ //[l,i)为左子树，[i,r)为右子树
            if(seq[i] > val)
                break;
        }
        for(int j=i+1;j<r;j++){//如果右侧的子序列有小于val的元素，则不满足
            if(seq[j] < val)
                return false;
        }
        bool ret = true;
        if(l<i)
        	ret = ret && VerifyTreeOfBST2(seq,l,i-1);
        if(r>i)
            ret = ret && VerifyTreeOfBST2(seq,i,r-1);
        return ret;
    }
};
