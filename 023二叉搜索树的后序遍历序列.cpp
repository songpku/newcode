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
		vector<int> in(sequence.begin(),sequence.end());
        sort(in.begin(),in.end());
        return VerifyTreeOfBST(in,sequence,0,sequence.size()-1,0,sequence.size()-1);
        
    }
    bool VerifyTreeOfBST(vector<int> &in,vector<int> &seq,int il,int ir,int sl,int sr){
        /*if(il == ir){
            if(in[il] == seq[sl]){
                return true;
            }
            return false;
        }*/
        int val = seq[sr];
        int i=il;
        for(;i<=ir;i++){
            if(in[i] == val)
                break;
        }
        if(i>ir)
            return false;
        bool ret=true; //默认是false，要注意。
        if(i != il)
            ret=VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1);
        if(i != ir)
            ret&=VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        return ret;
        //return VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1) && 
         //   VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        
    }
};
