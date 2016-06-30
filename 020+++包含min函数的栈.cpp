/*
包含min函数的栈
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/ 
//解决思路，添加一个辅助栈，存放最小值，
//data:3,4,2,1
//assi:3,3,2,1
//辅助栈与数据栈一一对应，辅助栈标识在对应元素存在的情况下的最小值，如data(3,4)时最小值为3，data(3,4,2)时为2 
class Solution {
public:
    void push(int value) {
        data.push(value);
        if(assist.empty() || value < assist.top()){
            assist.push(value);
        }else{
            assist.push(assist.top());
        }
    }
    void pop() {
        if(data.empty() || assist.empty()) //编译器不会做这个检查
            return;
        data.pop();
        assist.pop();
    }
    int top() {
        if(data.empty()) //编译器不会做这个检查
            return INT_MAX;
        return data.top();
    }
    int min() {
        if(assist.empty())//编译器不会做这个检查
            return INT_MAX;
        return assist.top();
    }
    stack<int> data;
    stack<int> assist;
};
