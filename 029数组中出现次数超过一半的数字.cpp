/*
�����г��ִ�������һ�������
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int half=numbers.size()/2;
    	unordered_map<int,int> times;
        for(vector<int>::const_iterator iter = numbers.begin(); iter!=numbers.end();iter++){
            if(times.find(*iter)!=times.end()){
                ++times[*iter];
            }else{
                times[*iter]=1;
            }
            if(times[*iter]>half)
               return *iter;
        }
        return 0;
    }
};
