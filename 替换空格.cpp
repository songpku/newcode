/*
�滻�ո�
    ����������12787 ʱ�����ƣ�1�� �ռ����ƣ�32768K
    ����֪ʶ�㣺 �ַ���
    �㷨֪ʶ��Ƶ����

��Ŀ����
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

*/

//lengthΪţ��ϵͳ�涨�ַ����������󳤶ȣ��̶�Ϊһ������
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length<=0)
            return;
		int spaceNum=0,alphaNum=0;
        for(int i=0;i<length;i++){
            if(isspace(str[i])){
               spaceNum++;
            }
            else{
               alphaNum++;
            }
        }
        int j = alphaNum + spaceNum*2 -1;  //�ؼ��㣬һ���ո����������ֽ�
        for(int i=alphaNum-1;i>=0;i--){
            if(isspace(str[i])){
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }else{
                str[j--]=str[i];
            }
            
        }
	}
};
