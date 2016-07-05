/*
和为S的连续正数序列
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/ 
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        //解题思路：考虑用两个数s和b表示最小值和最大值，因为至少包含两个数，所以sum最小为3；
        //初始化s和b为1和2，计算[s~b]的和；知道b超过(sum+1)/2为止。
        //1、若等于sum，则记录结果，并增加b继续求解
        //2、若小于sum,则增加b继续求解
        //3、若大于sum，则增加s，求和
        vector<vector<int> > ret;
        if(sum < 3)
            return ret;
        int small=1,big=2,end=(sum+1)/2;
        int curSum=3;
        while(big <= end){
            if(curSum == sum){
                vector<int> tmp;
                for(int i=small;i<=big;i++){
                    tmp.push_back(i);
                }
                ret.push_back(tmp);
                ++big;
                curSum+=big;
            }else if(curSum < sum){
                ++big;
                curSum+=big;
            }else{
                curSum-=small;
                ++small;
            }
        }
        return ret;
    }
};
