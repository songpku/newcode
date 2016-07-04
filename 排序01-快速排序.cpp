#include<iostream>
#include<vector>
using namespace std;
int quick_partition(vector<int> &a,int l,int r){
	if(l>=r)
		return l;
	int left=l;
	int right=r;
	int mid = a[l];
	while (l<r){
        //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ�ң�����Ҫ����һЩ�߽�����
        while (l<r && a[r] >= mid){
           --r;
        }
        //�ٴ���߿�ʼ
        while (l<r && a[l] <= mid){
            ++l;
        }
        swap(a[l], a[r]);
    }
    //����λд�ᣬ�ǳ���Ҫ
    a[left] = a[l];
    a[l] = mid;
	quick_partition(a,left,l-1);
	quick_partition(a,l+1,right);
}
void show(vector<int> &a){
	for(int i:a){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	vector<int> a = {1,3,5,4,3,2,5,4,8,0};
	vector<int>  b = {1,2,3,4,5,6,7,8,9,10};
	vector<int>  c= {10,9,8,7,6,5,4,3,2,1};
	vector<int> d={1};
	show(a);
	quick_partition(a,0,a.size()-1);
	show(a);
	return 0;
} 
