/*
�����е������
��Ŀ����
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        //������⣬���Ӷ�̫���޷�ͨ����
        /*
        int ret=0;
        for(int i=0;i<data.size()-1;i++){
            for(int j=i+1;j<data.size();j++){
                if(data[i] > data[j])
                    ++ret;
            }
        }
        return ret;*/
        //����ͳ�Ʒ���
        /* 7 5 6 4
            /   \        a����������Ϊ
          7 5 | 6 4
           /     \
         7 | 5| 6 | 4    b���������ģΪһʱ������ϲ�������ͳ�������
          \ /    \ /
          5 7 |  4 6     �ȶԣ��Ƚ�7��6����Ϊ7>6,��4 6���ź���ģ����������Ϊ2(4��6),��������5��6
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
    	if (r >= mid + 1){ //�����λ��У���ض�����С�ĵģ�ֱ�Ӹ��Ƶ�dataǰ�沿��
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
