/*
쳲���������
��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
*/ 
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
		if(n<=2)
            return 1;
        int a=1,b=1,tmp;
        for(int i=3;i<=n;i++){
            tmp = b;
            b = a + b;
            a=tmp;
        }
        return b;
    }
};
