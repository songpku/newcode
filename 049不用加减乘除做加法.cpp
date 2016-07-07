/*
不用加减乘除做加法
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/ 
class Solution {
public:
	int Add(int num1, int num2)
	{	//解题思路：
		int s,c;
        do{
            s = num1^num2;
            c = (num1&num2)<<1;
            num1 = s;
            num2 = c;
        }while(num2 != 0);
        return num1;
	}
};
