/*
ջ��ѹ�룬�������� 
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
*/
class Solution {
public:
   	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        //����˼·�����ø���ջ������popv������popv�е�ÿһ��Ԫ��a[i]���ж��Ƿ��stk��ջ��
        //Ԫ����ȣ����������pushv��a[i]ǰ������Ԫ�أ�����a[i]��ѹջ��֮���ж�a[i]�Ƿ�
        //��ջ��Ԫ����ȣ�������ջ������false
        if(pushV.size()==0 || popV.size() == 0)
            return false;
		stack<int> stk;
        for(int i=0;i<popV.size();i++){
            if(stk.empty() || popV[i] != stk.top()){
                for(int j=0;j<popV[i];j++){
                    if(pushV[j] != -1){
                        stk.push(pushV[j]);
                        pushV[j]=-1;
                    }
                }
            }
            if(!stk.empty() && popV[i] == stk.top()){
                stk.pop();
            }else{
                return false;
            }
        }
        return true;
	}
};
