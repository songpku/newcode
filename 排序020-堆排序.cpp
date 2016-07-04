#include<iostream>
#include<vector>
using namespace std;
//堆的特点
//1、堆是一棵完全二叉树或者近似完全二叉树
//2、对于最大堆，所有节点大于其子树 
//3、可以使用数组存储，对于节点i的左子树为2*i+1,右子树为2*i+2,父节点为(i-1)/2 

void MaxHeapDown(vector<int> &a, int i);
void MaxHeapUp(vector<int> &a, int i);
void MaxHeapInit(vector<int> &a);
int MaxHeapDel(vector<int> &a);
void MaxHeapInsert(vector<int>&a, int val);
//建立堆,对于每一个节点执行下沉 
void MaxHeapInit(vector<int> &a){
	for (int i = (a.size() - 2) / 2; i >= 0; --i){
		MaxHeapDown(a, i);
	}
}
//下沉
void MaxHeapDown(vector<int> &a, int i){
	if (a.size() == 0)
		return;
	int tmp = a[i];
	int j = 2 * i + 1;
	while (j<a.size()){
		if (j + 1<a.size() && a[j + 1]>a[j]){//对于最大堆，在左右子树中找到一个最大的 
			j = j + 1;
		}
		if (tmp>a[j])//如果当前点比左右子树中大的一个还大的话则不需要调整了。 
			break;
		a[i] = a[j];
		i = j;
		j = 2 * j + 1;
	}
	a[i] = tmp;
}
//上浮
void MaxHeapUp(vector<int> &a, int i){
	int tmp = a[i];
	int j = (i - 1) / 2;
	while (j >= 0 && i!=0){
		if (tmp <= a[j])
			break;
		a[i] = a[j]; //若父节点小于子节点，将子节点下沉到子节点的位置
		i = j;
		j = (j - 1) / 2;
	}
	a[i] = tmp;
}
//删除堆顶元素，返回最大值；删除后将最后一个元素放到堆顶，然后执行下沉 
int MaxHeapDel(vector<int> &a){
	int ret = a[0];
	a[0] = a[a.size() - 1];
	a.erase(a.end() - 1);
	MaxHeapDown(a, 0);
	return ret;
}
//插入元素，将元素插入到堆的最后面，即数组最后，然后执行上浮
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
