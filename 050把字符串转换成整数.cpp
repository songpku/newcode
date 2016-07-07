/*
把字符串转换成整数
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
*/

enum Status{kValid=0,kInvalid};
class Solution {
public:
    int StrToInt(string str) {
        //1、前面带0，如“000123”
        //2、正负数-123，+123
        //3、带字母或者空格（空格是直接跳过还是算非法）
        //4、只有一个正号或者负号
        //5、字符串为空
        //6、溢出 
        g_nStatus = kInvalid;
        if(str.size()==0)
            return 0;
        int pn=INT_MAX;
        int ret=0;
        for(char c:str){
            if(c == '-' || c == '+'){
                if(ret>0)//数字之后又出现正负号
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
    int g_nStatus;//如果是非法输入返回0，并且设置为非法输入。为了和输入“0”区分
};

