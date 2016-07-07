/*
�˿���˳��
��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        //1�������ж���
        //2�����򣬲��Ҳ�������������
        //3������0�ĸ��������Ƿ�Ͳ��������������
        //map�ȿ���ͳ�ƴ����ֿ����������������ѡ��
        if(numbers.size() == 0)
            return false;
        int zeroTimes=0,noncontinue=0;
        map<int,int> times;
        for(int i:numbers){
            auto ret = times.insert({i,1});  //���ص���һ��pair��pair.first��һ����������pair.second��һ��bool����
            if(!ret.second ){
                if(ret.first->first != 0)
                	return false;
                ++ret.first->second;
            }
        }
        if (times.count(0)>0){
			zeroTimes = times[0];
			times.erase(0);
		}
        map<int,int>::iterator iter=times.begin();
        map<int,int>::iterator pre = iter;
        ++iter;
        for(;iter!=times.end();iter++,pre++){
            noncontinue += iter->first - pre->first - 1;
        }
        if(zeroTimes >= noncontinue)
            return true;
        return false;
    }
};
