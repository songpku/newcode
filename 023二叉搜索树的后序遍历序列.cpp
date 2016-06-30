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
        //����һ���Ƚ�seq��������������in�������������Ȼ�������������ͺ�������ݹ��ж�
        /*
		vector<int> in(sequence.begin(),sequence.end());
        sort(in.begin(),in.end());
        return VerifyTreeOfBST(in,sequence,0,sequence.size()-1,0,sequence.size()-1);
        */
        //������(���Ӽ�ֱ��)�����ú������һ���Ǹ��ڵ���ص㣬��[0��r)�в��ҵ�һ������a[r]��Ԫ���±�i,
        //a[l,i)��Ϊ��������a[i,r)��Ϊ������������a(i,r)������Ԫ��С��a[r]�򷵻�false��
        return VerifyTreeOfBST2(sequence,0,sequence.size()-1);
    }
    bool VerifyTreeOfBST(vector<int> &in,vector<int> &seq,int il,int ir,int sl,int sr){
        int val = seq[sr];
        int i=il;
        for(;i<=ir;i++){
            if(in[i] == val)
                break;
        }
        if(i>ir)//���ڸ��ڵ�val������in�У�il~ir���Ҳ�����Ӧ��val��˵��������������
            return false;
        bool ret=true; //Ĭ����false��Ҫע�⡣
        if(i != il)
            ret=VerifyTreeOfBST(in,seq,il,i-1,sl,sl+i-il-1);
        if(i != ir)
            ret&=VerifyTreeOfBST(in,seq,i+1,ir,sl+i-il,sr-1);
        return ret;
    }
    bool VerifyTreeOfBST2(vector<int> &seq,int l,int r){
        int val = seq[r];
        int i=l;
        for(;i<r;i++){ //[l,i)Ϊ��������[i,r)Ϊ������
            if(seq[i] > val)
                break;
        }
        for(int j=i+1;j<r;j++){//����Ҳ����������С��val��Ԫ�أ�������
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
