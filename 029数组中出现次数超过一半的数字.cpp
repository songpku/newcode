/*
数组中出现次数超过一半的数字
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int half=numbers.size()/2;
    	unordered_map<int,int> times;
        for(vector<int>::const_iterator iter = numbers.begin(); iter!=numbers.end();iter++){
            if(times.find(*iter)!=times.end()){
                ++times[*iter];
            }else{
                times[*iter]=1;
            }
            if(times[*iter]>half)
               return *iter;
        }
        return 0;
    }
};
