/*
和为S的两个数字
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        unordered_set<int> hashTable;
        vector<int> ret = {INT_MAX/2,2};
        for(int i=0;i<array.size();i++){
            hashTable.insert(array[i]);
        }
        for(int i=0;i<array.size();i++){
            if(hashTable.find(sum-array[i])!=hashTable.end() &&
               (ret[0]*ret[1]) > (array[i]*(sum-array[i]))){
                   ret[0] = array[i];
               	   ret[1] = sum - array[i];
               }
        }
        if(ret[0]*ret[1] >= INT_MAX-1){ //很容易漏掉的地方
            ret.erase(ret.begin());
            ret.erase(ret.begin());
        }
        return ret;
    }
};
