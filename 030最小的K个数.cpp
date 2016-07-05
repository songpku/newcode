/*
最小的K个数
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/ 
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //方法一：利用快排子函数的方式做
        /*vector<int> ret;
		if (input.size() == 0 || k==0 || input.size() < k)
			return ret;
		int left = 0, right = input.size() - 1;
		int index = quick_partition(input, left, right);
		if (k<input.size()){
			while (index != k - 1){
				if (index < k - 1){
					left = index + 1;
				}
				else{
					right = index - 1;
				}
				index = quick_partition(input, left, right);
			}
		}
		for (int i = 0; i<k&&i<input.size(); i++){
			ret.push_back(input[i]);
		}
		return ret;*/
        //方案二:利用堆排序：O（nlog(k)），比较适合大数据量的情况
        vector<int> ret;
        if (input.size() == 0 || k==0 || input.size() < k)
			return ret;
        
        for(int i=0;i<k;i++){
            MaxHeapInsert(ret,input[i]);
        }
        for(int i=k;i<input.size();i++){
            if(input[i] < ret[0]){
                MaxHeapDel(ret);
                MaxHeapInsert(ret,input[i]);
            }
        }
        return ret;
	}
    //建立堆,对于每一个节点执行下沉 
    void MaxHeapInit(vector<int> &a){
        for (int i = (a.size() - 2) / 2; i >= 0; --i){
            MaxHeapDown(a, i);
        }
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
        while (j >= 0 && i!=0){ //注意到一个细节，因为j=(j-1)/2，所以j不能为负，因此要加条件i!=0
            if (tmp <= a[j])
                break;
            a[i] = a[j]; //若父节点小于子节点，将子节点下沉到子节点的位置
            i = j;
            j = (j - 1) / 2;
        }
        a[i] = tmp;
    }
	int quick_partition(vector<int> &a, int l, int r){
		int left = l, right = r;
		int base = a[left];
		while (l<r){
			while (l<r && a[r] >= base){
				--r;
			}
			while (l<r && a[l] <= base){
				++l;
			}
			swap(a[l], a[r]);
		}
		a[left] = a[l];
		a[l] = base;
		return l;
	}
};
