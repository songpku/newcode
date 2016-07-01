/*求所有字符的组合：
如abc的组合为a,b,c,ab,ac,bc,abc
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;
/*解题思路：
函数 combination求长度和len的组合，所以在主函数中循环求长度[1，n]的组合 
对于长度为m的字符串求长度为n的组合，一个长度为m的字符串分为两部分[left]和[left+1,m)有两种情况：
1、加入[left]在组合中，则继续在[left+1,m)中求长度为m-1的组合
2、不加入[left]在组合中，则继续在 [left+1,m)中求长度为m的组合
*/ 
void combination(string &str, vector<char> &ret, int l, int len){
	if (len <=0){ //打印结果条件 
		for (char c : ret)
			cout << c;
		cout << endl;
		return;
	}
	if (l == str.size()) //退出条件 
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
