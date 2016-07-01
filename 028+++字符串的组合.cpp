/*�������ַ�����ϣ�
��abc�����Ϊa,b,c,ab,ac,bc,abc
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;
/*����˼·��
���� combination�󳤶Ⱥ�len����ϣ���������������ѭ���󳤶�[1��n]����� 
���ڳ���Ϊm���ַ����󳤶�Ϊn����ϣ�һ������Ϊm���ַ�����Ϊ������[left]��[left+1,m)�����������
1������[left]������У��������[left+1,m)���󳤶�Ϊm-1�����
2��������[left]������У�������� [left+1,m)���󳤶�Ϊm�����
*/ 
void combination(string &str, vector<char> &ret, int l, int len){
	if (len <=0){ //��ӡ������� 
		for (char c : ret)
			cout << c;
		cout << endl;
		return;
	}
	if (l == str.size()) //�˳����� 
		return;
	ret.push_back(str[l]);
	combination(str,ret, l + 1,len - 1);
	ret.pop_back();
	combination(str,ret,l + 1,len);
}
int main(){
	string in = "abc";
	vector<char> ret;
	for (int i = 0; i < in.size(); i++){
		combination(in, ret, 0, i+1);
	}
}
