/*
�ַ����е�һ�����ظ����ַ�
��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
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
        //����һ�����ַ�ʽ���ַ����ܴ��ʱ���Ƚ���
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
        //����һ�����ַ�ʽ���ַ����ܴ��ʱ���Ƚ���
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
    //����һ�����ַ�ʽ���ַ����ܴ��ʱ���Ƚ���
    /*
    string s;
    unordered_map<char,int> times;*/
    //������
    int occu[256]; //-1��ʾû�У�-2��ʾ�ظ���>0��ʾ���ֵ�λ��
    int index;

};
