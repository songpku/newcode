/*
��ת����˳����
��Ŀ����
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/ 
class Solution {
public:
    string ReverseSentence(string str) {
        //����˼·���ȷ�ת�����ڵ��ַ����ٷ�ת�����ַ���
        if(str.size()==0)
            return "";
        int start,end,next;
        start = end = next = 0;
        while(end < str.size()){
            if(str[end] == ' '){
                next = end+1;
                --end;
                while(start < end){
                    swap(str[start],str[end]);
                    ++start;
                    --end;
                }
                start = end = next;
            }else{
                ++end;
            }
        }
        --end;
        while(start < end){  //����©�����һ������
            swap(str[start],str[end]);
            ++start;
            --end;
        }
        start = 0;
        end = str.size()-1;
        while(start<end){
            swap(str[start],str[end]);
            ++start;
            --end;
        }
        return str;
    }
};
