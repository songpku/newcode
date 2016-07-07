/*
数组中重复的数字
题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        //解法一：利用unordered_map；时间复杂度O(n),空间复杂度O(n)
        //解法二：由于数字是在[0,n-1]，若没有重复的数字，在排好序后数组的下标和元素应该相等。
        //1、遍历数组，对于下标i,如i!=a[i]则应交换a[i]和a[a[i]]，知道i=a[i]
        //2、在交换的过程中，若a[i] = a[a[i]]则说明有重复的。
        //时间复杂度O(n),空间复杂度O(1)
        if(length < 2)
            return false;
        for(int i=0;i<length;i++){
            while(i!=numbers[i]){
                if(numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i],numbers[numbers[i]]); //交换一次不能保证i位置上的数是对应的，但是一定能保证a[i]
                									//位置上的数数对的，所以平均下来每个数字只交换一次。
            }
        }
        return false; 
    }
};
