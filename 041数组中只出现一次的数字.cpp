/*
数组中只出现一次的数字
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2){
            *num1=0;
            *num2=0;
            return;
        }
       	//解法一：利用map时间复杂度O(n*log(n)),空间复杂度O(n);
        /*
		map<int,int> times;
        for(vector<int>::const_iterator iter=data.begin();iter!=data.end();iter++){
            auto ret = times.insert({*iter,1});
            if(!ret.second){
                ++ret.first->second;
            }
        }
        int num[2],id=0;
        for(map<int,int>::const_iterator iter=times.begin(); iter!=times.end();iter++){
            if(iter->second == 1){
                num[id++] = iter->first;
            }
        }
        *num1=num[0];
        *num2=num[1];*/
        //解法二：小技巧，任何数和自己异或结果为0
        //由于其他数字都出现两次，那么异或的结果就为两个只出现一次的数字异或的结果。且结果不为0；
        //假设其结果的第一个为1的位为第n位，则利用第n为为0还是为1可以将这个数组分为A和B两个组
        //而且相同的数字必定在同一个组，且只出现一次的数必定在不同组
        //对于每一个组进行异或，其结果则为所求。
        int retAll = 0;
        for(int i=0;i<data.size();i++){
            retAll^=data[i];
        }
        int i=31;
        for(;i>=0;i--){
            if((retAll&(1<<i))>0)
                break;
        }
        int diff=1<<i;
       	*num1=0;
        *num2=0;
        for(int i=0;i<data.size();i++){
            if((data[i]&diff)==0){
                *num1^=data[i];
            }else{
                *num2^=data[i];
            }
            
        }
    }
};
