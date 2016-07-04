/*
把数组排成最小的数
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
class Solution {
public:
    static bool comp(const string &s1,const string &s2){
        string sn1=s1;
        sn1.append(s2);
        string sn2=s2;
        sn2.append(sn1);
        return sn1<sn2;
    }
    string PrintMinNumber(vector<int> numbers) {
    	//解题思路：这个题根本在于数字的排列顺序，转换为字符串，m和n要么排列为mn，要么是nm，比较这个字符串的顺序确定两者的顺序。 
        vector<string> strs;
        for(int i=0;i<numbers.size();i++){
            strs.push_back(to_string(numbers[i]));
        }
        sort(strs.begin(),strs.end(),comp);
       	string ret;
        for(int i=0;i<strs.size();i++){
            ret.append(strs[i]);
        }                
        return ret;
    }
};
