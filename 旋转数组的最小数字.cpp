/*
旋转数组的最小数字

题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //方案一：简单双重循环，但是时间复杂度太高。
        /*
        if(rotateArray.size()==0)
            return 0;
        int minx = rotateArray[0];
        for(int i=1;i<rotateArray.size();i++){
            minx = min(minx,rotateArray[i]);
        }
        return minx;
        */
        //方案二：二分查找
        //序列分为两个，前半个递增子序列和后半个递增子序列
        //一旦a[l]<a[r],说明只剩下后半个子序列,即可退出
        //当a[l]<=a[m],说明后半个子序列在m之后
        //当a[m]<=a[r],说明最小值在m之前。
        //当l = r -1,时，有两种情况 如100,1和1,2，所以退出求最小值。
        
        int left = 0,right = rotateArray.size()-1,mid;
        while(rotateArray[left]>=rotateArray[right]){
        	if((right - left) == 1)
                break;
            mid = (right + left)/2;
            if(rotateArray[left] == rotateArray[mid] &&  //在非递减数组（允许重复）的情况下的特殊情况{1,0,1,1,1}{1,1,1,0,1}
               rotateArray[mid] ==rotateArray[right]){
                int ret = rotateArray[left];
                for(int i=left;i<=right;i++){
                    if(ret>rotateArray[i])
                        ret = rotateArray[i];
                }
                return ret;
            }
            if(rotateArray[left] <= rotateArray[mid]){
               left = mid;
            }else if(rotateArray[mid] <= rotateArray[right]){
                right = mid;
            }
        }
        return min(rotateArray[left],rotateArray[right]);
    }
};
