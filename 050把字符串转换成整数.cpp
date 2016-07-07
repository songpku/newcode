/*
���ַ���ת��������
��Ŀ����
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
*/

enum Status{kValid=0,kInvalid};
class Solution {
public:
    int StrToInt(string str) {
        //1��ǰ���0���硰000123��
        //2��������-123��+123
        //3������ĸ���߿ո񣨿ո���ֱ������������Ƿ���
        //4��ֻ��һ�����Ż��߸���
        //5���ַ���Ϊ��
        //6����� 
        g_nStatus = kInvalid;
        if(str.size()==0)
            return 0;
        int pn=INT_MAX;
        int ret=0;
        for(char c:str){
            if(c == '-' || c == '+'){
                if(ret>0)//����֮���ֳ���������
                    return 0;
                if(c == '-')
                    pn=-1;
                else{
                    pn=1;
                }
            }else if(!isdigit(c)){
                return 0;
            }else{
            	if(ret > INT_MAX/10)
            		return INT_MAX;
            	if(ret < INT_MIN/10)
            		return INT_MIN;
            	ret = ret*10 + (c - '0');
            }
        }
        if(pn != INT_MAX && ret == 0){
            return 0;
        }
        if(pn == INT_MAX){
            pn = 1;
        }
        g_nStatus = kValid;
        return pn*ret;
        
    }
    int g_nStatus;//����ǷǷ����뷵��0����������Ϊ�Ƿ����롣Ϊ�˺����롰0������
};

