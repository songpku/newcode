/*
 二维数组中的查找

    参与人数：14100 时间限制：1秒 空间限制：32768K
    本题知识点： 查找
    算法知识视频讲解

题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
输入描述:

array： 待查找的二维数组
target：查找的数字

输出描述:
查找到返回true，查找不到返回false

*/ 



class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        
        //方法一：简单的for循环，复杂度太高
        /*
        for(int i=0;i<array.size();i++){
            for(int j=0;j<array[i].size();j++){
                if(array[i][j] == target)
                    return true;
            }
        }
        */
        /*方法二：向左下角扫描
        --------
        ------||
        ----||||
        --||||||
       	||||||||
        */
       	if(array.size()==0)
            return false;
        int row = 0;
        int col = array[0].size()-1;
		while(row<array.size() && col>=0){
            for(;col>=0;col--){
                if(array[row][col]==target)
                    return true;
                if(array[row][col]<target)
                	break;
            }
            if(col<0)         //注意，容易漏掉的地方 
                return false;
            for(;row<array.size();row++){
                if(array[row][col]==target)
                    return true;
                if(array[row][col]>target)
                   break;
            }
        }
        return false;
    }
};
