/*
表示数值的字符串
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/ 
class Solution {
public:
    bool isNumeric(char* string)
    {
        /*解决方案：
        [sign]integral-digitd[.[franction-digitd]][e|E[sign]exponential-digits]
        []表示选项，可有可无*/
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
