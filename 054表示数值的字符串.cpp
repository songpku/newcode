/*
��ʾ��ֵ���ַ���
��Ŀ����
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/ 
class Solution {
public:
    bool isNumeric(char* string)
    {
        /*���������
        [sign]integral-digitd[.[franction-digitd]][e|E[sign]exponential-digits]
        []��ʾѡ����п���*/
        if(string == NULL)
            return false;
        //1.[sign]
        if(*string == '+' || *string == '-')
            ++string;
        if(*string == '\0')
            return false;
        //2.integral-digitd
        scanDigits(&string);
        if(*string!='\0'){
            if(*string == '.'){ //3.[.franction-digitd]
                ++string;
                //if(*string == '\0'){
                 //   return false;
                //
                scanDigits(&string);
                if (*string == 'e' || *string == 'E'){ //[e|E[sign]exponential-digits]
					++string;
					if (*string == '\0'){
						return false;
					}
					if (!isExponential_digits(&string)){
						return false;
					}
				}
            }else if(*string == 'e' || *string == 'E'){ //[e|E[sign]exponential-digits]
                ++string;
                if(*string == '\0'){
                    return false;
                }
                if(!isExponential_digits(&string)){
                    return false;
                }
            }else{
            	return false;
            }
        }
        if(*string == '\0')
            return true;
        return false;
    }
    void scanDigits(char **c){
        while(**c!='\0' && isdigit(**c))
            ++(*c);
    }
    bool isExponential_digits(char **string){//[sign]exponential-digits
         //1.[sign]
        if(**string == '+' || **string == '-')
            ++(*string);
        if(**string == '\0')
            return false;
        //2.integral-digitd
        scanDigits(string);
        if(**string == '\0')
            return true;
        return false;
    }

};
