/*
��ΪS����������
��Ŀ����
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������
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
        if(ret[0]*ret[1] >= INT_MAX-1){ //������©���ĵط�
            ret.erase(ret.begin());
            ret.erase(ret.begin());
        }
        return ret;
    }
};
