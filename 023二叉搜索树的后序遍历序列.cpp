/*
`
��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ
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
        bool ret=true; //Ĭ����false��Ҫע�⡣
        if(i != il)
            ret=VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1);
        if(i != ir)
            ret&=VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        return ret;
        //return VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1) && 
         //   VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        
    }
};
