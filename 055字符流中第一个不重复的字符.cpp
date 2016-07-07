/*
字符流中第一个不重复的字符
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
class Solution
{
public:
  //Insert one char from stringstream
    Solution():index(0){
        for(int i=0;i<256;i++){
            occu[i]=-1;
        }
    }
    void Insert(char ch)
    {
        //方案一：这种方式在字符流很大的时候会比较慢
    	/*
        s.push_back(ch);
        auto ret = times.insert({ch,1});
        if(!ret.second){
            ++ret.first->second;
        }*/
        if(occu[ch] == -1){
			occu[ch] = index;
        }else{
            occu[ch] = -2;
        }
        ++index;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        //方案一：这种方式在字符流很大的时候会比较慢
        /*
    	for(int i=0;i<s.size();i++){ 
            if(times[s[i]] == 1)
                return s[i];
        }
        return '#';
        */
        int minCh=INT_MAX;
        char ret;
        for(int i=0;i<256;i++){
            if(occu[i]>=0 && occu[i]<minCh){
                minCh = occu[i];
                ret = i;
            }
        }
        if(minCh == INT_MAX)
            return '#';
        return ret;
        
    }
    //方案一：这种方式在字符流很大的时候会比较慢
    /*
    string s;
    unordered_map<char,int> times;*/
    //方案二
    int occu[256]; //-1表示没有，-2表示重复，>0表示出现的位置
    int index;

};
