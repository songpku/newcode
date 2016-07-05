/*
数组中的逆序对
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        //暴力求解，复杂度太大，无法通过。
        /*
        int ret=0;
        for(int i=0;i<data.size()-1;i++){
            for(int j=i+1;j<data.size();j++){
                if(data[i] > data[j])
                    ++ret;
            }
        }
        return ret;*/
        //分治统计法：
        /* 7 5 6 4
            /   \        a、将问题拆分为
          7 5 | 6 4
           /     \
         7 | 5| 6 | 4    b、当问题规模为一时将问题合并，排序，统计逆序对
          \ /    \ /
          5 7 |  4 6     比对，比较7和6，因为7>6,且4 6是排好序的，所以逆序对为2(4和6),继续考察5和6
           \      /
            4 5 6 7   */
        vector<int> srt(data.size());
        return solve(data,srt,0,data.size()-1);
        
    }
    int solve(vector<int> &data,vector<int> &srt,int l,int r){
        if(l >= r)
            return 0;
        int mid=(l+r)/2;
        int ret=0;
        ret += solve(data,srt,l,mid);
        ret += solve(data,srt,mid+1,r);
        int left = l,right=r;
        int srtR=r;
        int lr=mid;
        while(lr >= l && r >= (mid + 1)){ 
            if(data[lr] > data[r]){
                ret += r-mid; //r-(mid+1) +1;
                srt[srtR--] = data[lr];
                --lr;
            }else{
                srt[srtR--] = data[r];
                r--;
            }
        }
    	if (r >= mid + 1){ //若后半段还有，则必定是最小的的，直接复制到data前面部分
			int ll = left;
			for (int i = mid+1; i <=r; i++){
				data[ll++] = data[i];
			}
		}
        for(int i=right;i>srtR;i--){
            data[i] = srt[i];
        }
        return ret;
    }
};
