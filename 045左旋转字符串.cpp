/*
����ת�ַ���
��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/ 
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //������ת��
        //1����ת[0,n) cbaXYZdef
        //2����ת��[n,str.size()) cbafedZYX
        //3����ת�����ַ��� XYZdefabc
        if(str.size() <= n)
            return str;
        rotate(str,0,n-1);
        rotate(str,n,str.size()-1);
        rotate(str,0,str.size()-1);
        return str;
    }
    void rotate(string &s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            ++l;
            --r;
        }
    }
};
