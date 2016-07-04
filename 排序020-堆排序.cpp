#include<iostream>
#include<vector>
using namespace std;
//�ѵ��ص�
//1������һ����ȫ���������߽�����ȫ������
//2���������ѣ����нڵ���������� 
//3������ʹ������洢�����ڽڵ�i��������Ϊ2*i+1,������Ϊ2*i+2,���ڵ�Ϊ(i-1)/2 

void MaxHeapDown(vector<int> &a, int i);
void MaxHeapUp(vector<int> &a, int i);
void MaxHeapInit(vector<int> &a);
int MaxHeapDel(vector<int> &a);
void MaxHeapInsert(vector<int>&a, int val);
//������,����ÿһ���ڵ�ִ���³� 
void MaxHeapInit(vector<int> &a){
	for (int i = (a.size() - 2) / 2; i >= 0; --i){
		MaxHeapDown(a, i);
	}
}
//�³�
void MaxHeapDown(vector<int> &a, int i){
	if (a.size() == 0)
		return;
	int tmp = a[i];
	int j = 2 * i + 1;
	while (j<a.size()){
		if (j + 1<a.size() && a[j + 1]>a[j]){//�������ѣ��������������ҵ�һ������ 
			j = j + 1;
		}
		if (tmp>a[j])//�����ǰ������������д��һ������Ļ�����Ҫ�����ˡ� 
			break;
		a[i] = a[j];
		i = j;
		j = 2 * j + 1;
	}
	a[i] = tmp;
}
//�ϸ�
void MaxHeapUp(vector<int> &a, int i){
	int tmp = a[i];
	int j = (i - 1) / 2;
	while (j >= 0 && i!=0){
		if (tmp <= a[j])
			break;
		a[i] = a[j]; //�����ڵ�С���ӽڵ㣬���ӽڵ��³����ӽڵ��λ��
		i = j;
		j = (j - 1) / 2;
	}
	a[i] = tmp;
}
//ɾ���Ѷ�Ԫ�أ��������ֵ��ɾ�������һ��Ԫ�طŵ��Ѷ���Ȼ��ִ���³� 
int MaxHeapDel(vector<int> &a){
	int ret = a[0];
	a[0] = a[a.size() - 1];
	a.erase(a.end() - 1);
	MaxHeapDown(a, 0);
	return ret;
}
//����Ԫ�أ���Ԫ�ز��뵽�ѵ�����棬���������Ȼ��ִ���ϸ�
void MaxHeapInsert(vector<int>&a, int val){
	a.push_back(val);
	MaxHeapUp(a, a.size() - 1);
}
void show(vector<int> &a){
	for (int i : a){
		cout << i << " ";
	}
	cout << endl;
}
int main(){
	vector<int> a = { 1, 3, 5, 4, 3, 2, 5, 4, 8, 0 };
	show(a);
	MaxHeapInit(a);
	MaxHeapInsert(a,7);
	int size = a.size();
	for (int i = 0; i<size; i++){
		cout << MaxHeapDel(a) << " ";
	}
	cout << endl;
	show(a);
	return 0;
}
