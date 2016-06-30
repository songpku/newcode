/*
二进制中1的个数
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

*/ 
class Solution {
public:
     int  NumberOf1(int n) {
         //解法一：
		/*
         int ret=0; 
         if(n==-1)//容易溜掉的地方，-1的补码是11111111 11111111 11111111 11111111
             return sizeof(int)*8;
         if(n<0){
             n=0-n;
             ret=1;
         }
         while(n>0){
             if((n&1)==1)
                 ++ret;
             n=n>>1;
         }
         return ret;
         */
         //解法二：利用移动flag而非n，可以减少条件的判断，统一处理。
         /*
         int ret=0;
         int flag=1;
         while(flag){
             if(n&flag)
                 ++ret;
             flag=flag<<1;
         }
         return ret;
         */
         //解法三：1100-1=1011,1011&1100=1000;1111-1=1110,1110&1111=1110;
         //由上面两个例子可知道，(n-1)&n的结果相当于是将n的最后一个1去掉。
         int ret =0;
         while(n){
             ++ret;
             n=(n-1)&n;
         }
         return ret;
         
     }
};
