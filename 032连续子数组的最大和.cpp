/*
���������������
��Ŀ����
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��
*/ 
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //����һ����j��ʼ���ӣ�curMax��ʾ��j��i-1�ĺͣ�������һ����i��
        //��curMaxΪ��������[j,i]�ĺ�С��[i],���Է���ǰ��ĺͣ�ֱ�Ӵ�i,��ʼ��
        //�����ۼ�curMax����curMax�ۼӵĹ����п��ܼ�С������Ҫ��¼һ�����ֵ��
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
        //����������̬�滮
        //f(i)��ʾ��i��β��������ĺ�
        //1����i==0 or f(i-1)<=0ʱ,f(i) = a[i]
        //2����i!=0 and f(i-1)>0ʱ,f(i) = a[i] + f(i-1);
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

