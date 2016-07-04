/*
连续子数组的最大和
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？
*/ 
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //方法一：从j开始向后加，curMax表示从j到i-1的和，对于下一个点i，
        //若curMax为负数，则[j,i]的和小于[i],所以放弃前面的和，直接从i,开始。
        //否则累加curMax，在curMax累加的过程中可能减小，所以要记录一个最大值。
        /*
        if(array.size()==0)
            return 0;
        int retMax = INT_MIN;
        int curMax = 0;
        for(int i=0;i<array.size();i++){
            if(curMax<=0){
                curMax = array[i];
            }else{
                curMax += array[i];
            }
            if(curMax > retMax)
                retMax = curMax;
        }
        return retMax;*/
        //方法二：动态规划
        //f(i)表示以i结尾的子数组的和
        //1、当i==0 or f(i-1)<=0时,f(i) = a[i]
        //2、当i!=0 and f(i-1)>0时,f(i) = a[i] + f(i-1);
   		vector<int> maxF(array.size());
		solve(array, array.size() - 1, maxF);
		int ret = INT_MIN;
		for (int i = 0; i < maxF.size(); i++){
			if (maxF[i]>ret)
				ret = maxF[i];
		}
		return ret;
	}
	int solve(vector<int> &a, int i,vector<int> &maxF){
		if (i == 0)
			return a[i];
		int fi_1 = solve(a, i - 1, maxF);
		int ret = 0;
		if (fi_1 <= 0){
			ret=a[i];
		}
		else{
			ret=fi_1 + a[i];
		}
		maxF[i] = ret;
		return ret;
	}
};

