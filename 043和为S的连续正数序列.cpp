/*
��ΪS��������������
��Ŀ����
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/ 
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        //����˼·��������������s��b��ʾ��Сֵ�����ֵ����Ϊ���ٰ���������������sum��СΪ3��
        //��ʼ��s��bΪ1��2������[s~b]�ĺͣ�֪��b����(sum+1)/2Ϊֹ��
        //1��������sum�����¼�����������b�������
        //2����С��sum,������b�������
        //3��������sum��������s�����
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
