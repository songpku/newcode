/*
��һ��ֻ����һ�ε��ַ�λ��
��Ŀ����
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ���λ�á���Ϊ�մ�������-1��λ��������0��ʼ
*/
//ע�⣺�������ַ�������ĸ�Ƿ���ֹ����߳��ִ�����ص���Ŀʱ�������Կ���ʹ��hash�� 
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //����һ��ʹ��һ������52�����飬��Ŷ���λ�õ���ĸ��ID+1������0�ĸ��ţ�
        //��������֣������ΪINT_MAX�����Ҹ���ID��
        //���ɨ��һ������a���ҵ�����0����СID������ID-1
        /*
        if(str.size() == 0)
            return -1;
        int a[52]={0};//ǰ��26��A~Z��ID������26���a~z��ID��
        int index;
        for(int i=0;i<str.size();i++){
            index = str[i]>='a' ? 26 + str[i] - 'a' : 0+str[i]-'A';
            if(a[index]==0){
                a[index] = i+1;
            }else{
                a[index] = INT_MAX;
            }
        }
        int ret = INT_MAX;
        for(int i=0;i<52;i++){
            if(a[i] >0 && a[i] < ret)
                ret = a[i];
        }
        if(ret == INT_MAX)
            return -1;
        return ret-1;*/
        //������������hash��
        if(str.size() == 0)
            return -1;
        int hashTable[256]={0};
        for(int i=0;i<str.size();i++){
            ++hashTable[str[i]];
        }
        for(int i=0;i<str.size();i++){
            if(hashTable[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
