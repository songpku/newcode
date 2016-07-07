/*
������ʽƥ��
��Ŀ����
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //����һ������ȥ��ƥ����ַ���
        //�����ַ��͡�.��ֱ�Ӵ�ţ���x*�����Ϊ"x*"
        //���ַ����в�ͨ������aaa��a*a
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
        //������������״̬��
        /* ����ba*ab      <a<
        			     /  \
                         \  /
             --(1)-->b>--(2)-->a>--(3)-->b>--(4)  
        1������"."���ַ���һ���Ĵ���״̬������++s��++p
        2��������һ���ַ�ʱ"*"��������������
        	A����ǰ�ַ�ƥ�����ˣ�������Ϊ�������
                a��ƥ���������s=s;p=p+2;
                b��ƥ��1������++s;p=p+2;
                c��ƥ��������++s;p=p;�����Ѿ�ƥ���˵�ǰ�����м���ƥ��
            B����ǰ�ַ�û��ƥ���ϣ���s=s;p=p+2;
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
            if(*p==*s || (*p=='.' && *s!='\0')){//�Ѿ�ƥ����һ��������a,b,c�������
                return solve(s,p+2) || solve(s+1,p+1) || solve(s+1,p);
            }else{ //һ��Ҳû��ƥ��
                return solve(s,p+2);
            }
           
        }
        if((*p=='.' && *s!='\0') || *p==*s)
            return solve(s+1,p+1);
        return false;
    }
};
