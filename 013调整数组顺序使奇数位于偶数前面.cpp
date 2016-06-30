/*
调整数组顺序使奇数位于偶数前面
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include<vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //方案一：冒泡法
        /*
        int j;
        for(int i=array.size()-1;i>=0;i--){
            if((array[i] & 0x1) == 0){
                j=i;
                while(j<(array.size()-1) && (array[j+1])&0x1 == 1){
                    swap(array[j],array[j+1]);
                    ++j;
                }
            }
        }
        */
        //方案二：even指向第一个偶数，i遍历数组，当遇到a[i]为基数时将tmp=a[i],a[even,i)移动到a(even,i],a[even]=tmp;
        int tmp, even = 0;
		for (int i = 0; i<array.size(); i++){
			if ((array[i] & 1) == 1){
				if (i != even){ //如果连续式奇数即可能产生这种情况
					tmp = array[i];
					for (int j = i; j>even; j--){
						array[j] = array[j - 1];
					}
					array[even] = tmp;
					++even;
				}
				else{ //容易漏掉的地方
					even = i + 1;
				}
			}
		}
    }
};
int main(){
	Solution s;
	vector<int> a={1,2,3,4,5,6,7};
	s.reOrderArray(a);
}
