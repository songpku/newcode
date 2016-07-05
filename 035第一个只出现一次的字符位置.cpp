/*
第一个只出现一次的字符位置
题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1。位置索引从0开始
*/
//注意：当考察字符串中字母是否出现过或者出现次数相关的题目时，都可以考虑使用hash表。 
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //方案一，使用一个长度52的数组，存放对于位置的字母的ID+1（避免0的干扰）
        //若后面出现，则将其改为INT_MAX，并且更新ID，
        //最后扫描一遍数组a，找到大于0的最小ID，返回ID-1
        /*
        if(str.size() == 0)
            return -1;
        int a[52]={0};//前面26存A~Z的ID，后面26存放a~z的ID；
        int index;
        for(int i=0;i<str.size();i++){
            index = str[i]>='a' ? 26 + str[i] - 'a' : 0+str[i]-'A';
            if(a[index]==0){
                a[index] = i+1;
            }else{
                a[index] = INT_MAX;
            }
        }
        int ret = INT_MAX;
        for(int i=0;i<52;i++){
            if(a[i] >0 && a[i] < ret)
                ret = a[i];
        }
        if(ret == INT_MAX)
            return -1;
        return ret-1;*/
        //方案二。利用hash表
        if(str.size() == 0)
            return -1;
        int hashTable[256]={0};
        for(int i=0;i<str.size();i++){
            ++hashTable[str[i]];
        }
        for(int i=0;i<str.size();i++){
            if(hashTable[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
