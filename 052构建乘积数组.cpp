/*
�����˻�����
��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����(ע��û��A[i]) 
*/ 
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	//�ⷨһ������������������abc��cba
        //abc[i] = A[0]*A[1]*...*A[i-1]
        //cba[i] = A[n-1]*A[n-1]*...*A[i+1]
        //��B[i] = abc[i] * cba[i];
        vector<int> ret(A.size());
        if(A.size() == 1)
            ret[0] = 0;
        if(A.size() < 2)
            return ret;
        /*
        vector<int> abc(A.size());
        vector<int> cba(A.size());
        abc[0]=cba[A.size()-1]=1;
        for(int i=1;i<A.size();i++){
            abc[i]=abc[i-1] * A[i-1];
        }
        for(int i=A.size()-2;i>=0;i--){
            cba[i] = cba[i+1]*A[i+1];
        }
        for(int i=0;i<A.size();i++){
            ret[i] = abc[i]*cba[i];
        }
        return ret;*/
        //ʵ�ַ�ʽ������Լ�ռ�
        ret[0]=1;
        for(int i=1;i<A.size();i++){
            ret[i]=ret[i-1] * A[i-1];
        }
        int tmp=1;
        for(int i=A.size()-2;i>=0;i--){
            tmp*=A[i+1];
            ret[i] *=tmp;
        }
        return ret;
    }
};
