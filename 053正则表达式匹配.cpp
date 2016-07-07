/*
正则表达式匹配
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //利用一个队列去存匹配的字符串
        //单个字符和‘.’直接存放，“x*”存放为"x*"
        //这种方法行不通，对于aaa和a*a
        /*
    	queue<string> quePat;
        int i=0;
        while(pattern[i]!='\0'){
            if(pattern[i+1]!='\0' && pattern[i+1] == '*'){
                string tmp;
                tmp.push_back(pattern[i]);
                tmp.push_back('*');
                quePat.push(tmp);
                ++i;
            }else{
                string tmp;
                tmp.push_back(pattern[i]);
                quePat.push(tmp);
            }
            ++i;
        }
        i=0;
        while(str[i]!='\0'){
            if(quePat.empty())
                return false;
            string pat = quePat.front();quePat.pop();
            if(pat.size() == 1){
                if(pat[0]!='.' && pat[0] != str[i]){
                    return false;
                }
                ++i;
            }else{
                if(pat[0] == '.'){
                   while(str[i]!='\0'){
                   		++i;
                   }
                }
                while(str[i]!='\0' &&str[i] == pat[0]){
                    ++i;
                }
            }
        }
        if (quePat.empty() || (quePat.size() == 1 && quePat.front().size() == 2))
			return true;
        return false;
        */
        //方案二：有限状态机
        /* 对于ba*ab      <a<
        			     /  \
                         \  /
             --(1)-->b>--(2)-->a>--(3)-->b>--(4)  
        1、对于"."和字符是一样的处理状态；都是++s和++p
        2、对于下一个字符时"*"的情况有两种情况
        	A、当前字符匹配上了，则后面分为三种情况
                a、匹配零个，即s=s;p=p+2;
                b、匹配1个，即++s;p=p+2;
                c、匹配多个，即++s;p=p;级是已经匹配了当前，还有继续匹配
            B、但前字符没有匹配上，即s=s;p=p+2;
        */
        if(str == NULL || pattern == NULL)
            return false;
        return solve(str,pattern);
    }
    bool solve(char* s, char* p){
        if(*s=='\0' && *p=='\0')
            return true;
        if(*s!='\0' && *p=='\0')
            return false;
        if(*(p+1)=='*'){
            if(*p==*s || (*p=='.' && *s!='\0')){//已经匹配了一个，还有a,b,c三种情况
                return solve(s,p+2) || solve(s+1,p+1) || solve(s+1,p);
            }else{ //一个也没有匹配
                return solve(s,p+2);
            }
           
        }
        if((*p=='.' && *s!='\0') || *p==*s)
            return solve(s+1,p+1);
        return false;
    }
};
