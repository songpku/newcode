/*
数值的整数次方
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/ 
class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent==0)
            return 1;
        double ret=1.0;
        bool flag = false;
        if(exponent<0){
            exponent = 0-exponent;
            flag=true;
        }
        //解法一：直接求
        /*
        for(int i=0;i<exponent;i++){
            ret*=base;
        }*/
        //解法二:效率更高
        ret = PowerWithIntExponent(base,exponent);
        if(flag){
            if(base>-0.0000001&&base<0.0000001){  //考虑除数为0的情况
                return 0;
            }
            return 1/ret;
        }
        return ret;
    }
    double PowerWithIntExponent(double base,int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double ret=PowerWithIntExponent(base,exponent>>1);
        ret *= ret;
        if(exponent & 0x1 == 1){//判断是否是基数
            ret *= base;
        }
        return ret;
    }
};
