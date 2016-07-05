/*
��С��K����
��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/ 
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //����һ�����ÿ����Ӻ����ķ�ʽ��
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
        //������:���ö�����O��nlog(k)�����Ƚ��ʺϴ������������
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
    //������,����ÿһ���ڵ�ִ���³� 
    void MaxHeapInit(vector<int> &a){
        for (int i = (a.size() - 2) / 2; i >= 0; --i){
            MaxHeapDown(a, i);
        }
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
        while (j >= 0 && i!=0){ //ע�⵽һ��ϸ�ڣ���Ϊj=(j-1)/2������j����Ϊ�������Ҫ������i!=0
            if (tmp <= a[j])
                break;
            a[i] = a[j]; //�����ڵ�С���ӽڵ㣬���ӽڵ��³����ӽڵ��λ��
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
