/*
数字在排序数组中出现的次数
统计一个数字在排序数组中出现的次数。
*/ 
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //方案一:利用二分查找找到k，然后想两边扩展
        if(data.size()==0)
            return 0;
        int l=0;
        int r=data.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(data[mid] == k)
                break;
            if(data[mid] < k){
                l = mid + 1;
            }else{
                r = mid -1;
            }
        }
        if(l>r)
            return 0;
        int ret = 1;
        for(int i=mid+1;i<data.size();i++){
            if(data[i] != k)
                break;
            ++ret;
        }
        for(int i=mid-1;i>=0;i--){
            if(data[i] != k)
                break;
            ++ret;
        }
        return ret;
        //方法二:首先利用二分查找找到第一个k，然后利用二分查找找到最后一个，相减加一即为结果
        //在方法一中，若k出现的次数非常对，则时间主要浪费在扩展上，但是方法二可以解决这个问题。
    }
};
