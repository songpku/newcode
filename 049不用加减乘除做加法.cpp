/*
���üӼ��˳����ӷ�
��Ŀ����
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/ 
class Solution {
public:
	int Add(int num1, int num2)
	{	//����˼·��
		int s,c;
        do{
            s = num1^num2;
            c = (num1&num2)<<1;
            num1 = s;
            num2 = c;
        }while(num2 != 0);
        return num1;
	}
};
