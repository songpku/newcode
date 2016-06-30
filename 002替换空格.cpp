/*
替换空格
    参与人数：12787 时间限制：1秒 空间限制：32768K
    本题知识点： 字符串
    算法知识视频讲解

题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

*/

//length为牛客系统规定字符串输出的最大长度，固定为一个常数
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
        int j = alphaNum + spaceNum*2 -1;  //关键点，一个空格增加两个字节
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
