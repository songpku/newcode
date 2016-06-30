/*
 ��ά�����еĲ���

    ����������14100 ʱ�����ƣ�1�� �ռ����ƣ�32768K
    ����֪ʶ�㣺 ����
    �㷨֪ʶ��Ƶ����

��Ŀ����
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
��������:

array�� �����ҵĶ�ά����
target�����ҵ�����

�������:
���ҵ�����true�����Ҳ�������false

*/ 



class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        
        //����һ���򵥵�forѭ�������Ӷ�̫��
        /*
        for(int i=0;i<array.size();i++){
            for(int j=0;j<array[i].size();j++){
                if(array[i][j] == target)
                    return true;
            }
        }
        */
        /*�������������½�ɨ��
        --------
        ------||
        ----||||
        --||||||
       	||||||||
        */
       	if(array.size()==0)
            return false;
        int row = 0;
        int col = array[0].size()-1;
		while(row<array.size() && col>=0){
            for(;col>=0;col--){
                if(array[row][col]==target)
                    return true;
                if(array[row][col]<target)
                	break;
            }
            if(col<0)         //ע�⣬����©���ĵط� 
                return false;
            for(;row<array.size();row++){
                if(array[row][col]==target)
                    return true;
                if(array[row][col]>target)
                   break;
            }
        }
        return false;
    }
};
