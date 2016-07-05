/*
���������������г��ֵĴ���
ͳ��һ�����������������г��ֵĴ�����
*/ 
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //����һ:���ö��ֲ����ҵ�k��Ȼ����������չ
        if(data.size()==0)
            return 0;
        int l=0;
        int r=data.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(data[mid] == k)
                break;
            if(data[mid] < k){
                l = mid + 1;
            }else{
                r = mid -1;
            }
        }
        if(l>r)
            return 0;
        int ret = 1;
        for(int i=mid+1;i<data.size();i++){
            if(data[i] != k)
                break;
            ++ret;
        }
        for(int i=mid-1;i>=0;i--){
            if(data[i] != k)
                break;
            ++ret;
        }
        return ret;
        //������:�������ö��ֲ����ҵ���һ��k��Ȼ�����ö��ֲ����ҵ����һ���������һ��Ϊ���
        //�ڷ���һ�У���k���ֵĴ����ǳ��ԣ���ʱ����Ҫ�˷�����չ�ϣ����Ƿ��������Խ��������⡣
    }
};
