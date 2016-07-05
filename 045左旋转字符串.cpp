/*
左旋转字符串
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/ 
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //三步反转：
        //1、反转[0,n) cbaXYZdef
        //2、反转和[n,str.size()) cbafedZYX
        //3、反转整个字符串 XYZdefabc
        if(str.size() <= n)
            return str;
        rotate(str,0,n-1);
        rotate(str,n,str.size()-1);
        rotate(str,0,str.size()-1);
        return str;
    }
    void rotate(string &s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            ++l;
            --r;
        }
    }
};
