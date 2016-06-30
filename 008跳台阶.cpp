/*
跳台阶
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

*/ 
class Solution {
public:
    int jumpFloor(int number) {
        //解题思路：
        //n = 1是为1，n=2是为2
        //n=n时，1、第一步跳一阶，则有f(n-1)种跳法；2、第一步跳两阶，则有f(n-2)种跳法
        //    则有f(n) = f(n-1) + f(n-2),其实就是一个斐波拉契数列
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
