/*
字符串的排列
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
class Solution {
public:
    void solve(vector<string> &vec,string &str,int from,int to){
        //if(to <=1)
         //   return;
        if(from == to){ //常考关键点 
            if(find(vec.begin(),vec.end(),str)==vec.end())    //字符可能重复，如aa
            	vec.push_back(str);
        }
        else{
            for(int j=from;j<=to;j++){  //j必须从from开始，若从from+1开始，对于ab,就会漏掉本身的情况，只输出ba
                swap(str[from],str[j]);
                solve(vec,str,from+1,to); //常考关键点 
                swap(str[from],str[j]);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> ret;
        solve(ret,str,0,str.size()-1);
        sort(ret.begin(),ret.end());   //字典序
        return ret;
    }
};
