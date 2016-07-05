/*
������ֻ����һ�ε�����
��Ŀ����
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2){
            *num1=0;
            *num2=0;
            return;
        }
       	//�ⷨһ������mapʱ�临�Ӷ�O(n*log(n)),�ռ临�Ӷ�O(n);
        /*
		map<int,int> times;
        for(vector<int>::const_iterator iter=data.begin();iter!=data.end();iter++){
            auto ret = times.insert({*iter,1});
            if(!ret.second){
                ++ret.first->second;
            }
        }
        int num[2],id=0;
        for(map<int,int>::const_iterator iter=times.begin(); iter!=times.end();iter++){
            if(iter->second == 1){
                num[id++] = iter->first;
            }
        }
        *num1=num[0];
        *num2=num[1];*/
        //�ⷨ����С���ɣ��κ������Լ������Ϊ0
        //�����������ֶ��������Σ���ô���Ľ����Ϊ����ֻ����һ�ε��������Ľ�����ҽ����Ϊ0��
        //���������ĵ�һ��Ϊ1��λΪ��nλ�������õ�nΪΪ0����Ϊ1���Խ���������ΪA��B������
        //������ͬ�����ֱض���ͬһ���飬��ֻ����һ�ε����ض��ڲ�ͬ��
        //����ÿһ����������������Ϊ����
        int retAll = 0;
        for(int i=0;i<data.size();i++){
            retAll^=data[i];
        }
        int i=31;
        for(;i>=0;i--){
            if((retAll&(1<<i))>0)
                break;
        }
        int diff=1<<i;
       	*num1=0;
        *num2=0;
        for(int i=0;i<data.size();i++){
            if((data[i]&diff)==0){
                *num1^=data[i];
            }else{
                *num2^=data[i];
            }
            
        }
    }
};
