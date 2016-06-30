/*
顺时针打印矩阵
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
/*
->->->->->
^        v
^        v 
^        v     
<-<-<-<-<-
特殊：
1、->->->
2、->
	v	 
    v
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        if(matrix.size()==0)
            return ret;
		int r0=0,r1=matrix.size()-1;
        int c0=0,c1=matrix[0].size()-1;
        while(r0<=r1 && c0<=c1){
            for(int i=c0;i<=c1;i++)
                ret.push_back(matrix[r0][i]);
            for(int i=r0+1;i<r1;i++)
                ret.push_back(matrix[i][c1]);
            if(r0 != r1)     //非常容易漏掉，当只剩一行的时候会重复打印  特殊1 
                for(int i=c1;i>=c0;i--)
                    ret.push_back(matrix[r1][i]);
            if(c0 != c1) //特殊2 
                for(int i=r1-1;i>r0;i--)
                    ret.push_back(matrix[i][c0]);
            ++r0;
            ++c0;
            --r1;
            --c1;
        }
        return ret;
    }
};
