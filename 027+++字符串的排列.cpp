/*
�ַ���������
��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba�� ����밴��ĸ˳�������
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/
class Solution {
public:
    void solve(vector<string> &vec,string &str,int from,int to){
        //if(to <=1)
         //   return;
        if(from == to){ //�����ؼ��� 
            if(find(vec.begin(),vec.end(),str)==vec.end())    //�ַ������ظ�����aa
            	vec.push_back(str);
        }
        else{
            for(int j=from;j<=to;j++){  //j�����from��ʼ������from+1��ʼ������ab,�ͻ�©������������ֻ���ba
                swap(str[from],str[j]);
                solve(vec,str,from+1,to); //�����ؼ��� 
                swap(str[from],str[j]);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> ret;
        solve(ret,str,0,str.size()-1);
        sort(ret.begin(),ret.end());   //�ֵ���
        return ret;
    }
};
