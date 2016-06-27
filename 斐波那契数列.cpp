/*
斐波那契数列
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
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
