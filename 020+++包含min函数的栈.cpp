/*
����min������ջ
��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/ 
//���˼·�����һ������ջ�������Сֵ��
//data:3,4,2,1
//assi:3,3,2,1
//����ջ������ջһһ��Ӧ������ջ��ʶ�ڶ�ӦԪ�ش��ڵ�����µ���Сֵ����data(3,4)ʱ��СֵΪ3��data(3,4,2)ʱΪ2 
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
        if(data.empty() || assist.empty()) //������������������
            return;
        data.pop();
        assist.pop();
    }
    int top() {
        if(data.empty()) //������������������
            return INT_MAX;
        return data.top();
    }
    int min() {
        if(assist.empty())//������������������
            return INT_MAX;
        return assist.top();
    }
    stack<int> data;
    stack<int> assist;
};
