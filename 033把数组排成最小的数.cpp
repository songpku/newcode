/*
�������ų���С����
��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/
class Solution {
public:
    static bool comp(const string &s1,const string &s2){
        string sn1=s1;
        sn1.append(s2);
        string sn2=s2;
        sn2.append(sn1);
        return sn1<sn2;
    }
    string PrintMinNumber(vector<int> numbers) {
    	//����˼·�����������������ֵ�����˳��ת��Ϊ�ַ�����m��nҪô����Ϊmn��Ҫô��nm���Ƚ�����ַ�����˳��ȷ�����ߵ�˳�� 
        vector<string> strs;
        for(int i=0;i<numbers.size();i++){
            strs.push_back(to_string(numbers[i]));
        }
        sort(strs.begin(),strs.end(),comp);
       	string ret;
        for(int i=0;i<strs.size();i++){
            ret.append(strs[i]);
        }                
        return ret;
    }
};
