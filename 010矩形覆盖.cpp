/*
���θ���

��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

*/ 
class Solution {
public:
    int rectCover(int number) {
		if(number == 0)
            return 0;
        int fn_2=0;
        int fn_1=1;
        int ret;
        for(int i=1;i<=number;i++){
            ret = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = ret;
        }
        return ret;
    }
};
