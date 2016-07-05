/*
整数中1出现的次数（从1到n整数中1出现的次数）
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	//解法一：暴力 
        int ret=0;
    	for(int i=1;i<=n;i++){
            ret += numberOf1(i);
        }
        return ret;
        //解法二：根据数值规律使用递归，见书本175 
    }
    int numberOf1(int n){
        int ret=0;
        while(n){
            if(n%10==1){
                ++ret;
            }
            n=n/10;
        }
        return ret;
    }
};
