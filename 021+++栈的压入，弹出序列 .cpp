/*
栈的压入，弹出序列 
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/
class Solution {
public:
   	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        //解题思路：利用辅助栈，遍历popv，对于popv中的每一个元素a[i]，判断是否和stk的栈顶
        //元素相等，若不相等则将pushv中a[i]前的所有元素（包括a[i]）压栈。之后判断a[i]是否
        //和栈顶元素相等，相等则出栈，否则false
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
