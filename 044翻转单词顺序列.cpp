/*
翻转单词顺序列
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/ 
class Solution {
public:
    string ReverseSentence(string str) {
        //解题思路：先反转单词内的字符，再反转整个字符串
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
        while(start < end){  //容易漏掉最后一个单词
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
