/*
��̨��
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

*/ 
class Solution {
public:
    int jumpFloor(int number) {
        //����˼·��
        //n = 1��Ϊ1��n=2��Ϊ2
        //n=nʱ��1����һ����һ�ף�����f(n-1)��������2����һ�������ף�����f(n-2)������
        //    ����f(n) = f(n-1) + f(n-2),��ʵ����һ��쳲���������
        if(number==0)
            return 0;
        int fn_2=0;
        int fn_1=1;
        int tmp;
        for(int i=1;i<=number;i++){
            tmp=fn_1+fn_2;
            fn_2=fn_1;
            fn_1=tmp;
        }
        return tmp;
    }
};
