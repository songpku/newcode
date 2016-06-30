/*
变态跳台阶

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

*/
class Solution {
public:
    int jumpFloorII(int number) {
        //解题思路：
        //f(1)=1
        //f(2)=1+f(1)
        //f(3)=1+f(1)+f(2)=f(2)+(f(1)+1)=f(2)+f(2)  //直接跳3，先跳1，再跳2
        //f(4)=1+f(1)+f(2)+f(3)=...=f(3)+f(3)  //...
        //...
        //f(n)=f(n-1)+f(n-1) //先跳1，先跳2...直接跳n
		if(number == 0)
            return 0;
        int ret = 1;
        for(int i=2;i<=number;i++){
            ret = 2*ret;
        }
        return ret;
    }
};
