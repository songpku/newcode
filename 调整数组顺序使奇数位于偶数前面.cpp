/*
��������˳��ʹ����λ��ż��ǰ��
��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/
#include<vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //����һ��ð�ݷ�
        /*
        int j;
        for(int i=array.size()-1;i>=0;i--){
            if((array[i] & 0x1) == 0){
                j=i;
                while(j<(array.size()-1) && (array[j+1])&0x1 == 1){
                    swap(array[j],array[j+1]);
                    ++j;
                }
            }
        }
        */
        //��������evenָ���һ��ż����i�������飬������a[i]Ϊ����ʱ��tmp=a[i],a[even,i)�ƶ���a(even,i],a[even]=tmp;
        int tmp, even = 0;
		for (int i = 0; i<array.size(); i++){
			if ((array[i] & 1) == 1){
				if (i != even){ //�������ʽ���������ܲ����������
					tmp = array[i];
					for (int j = i; j>even; j--){
						array[j] = array[j - 1];
					}
					array[even] = tmp;
					++even;
				}
				else{ //����©���ĵط�
					even = i + 1;
				}
			}
		}
    }
};
int main(){
	Solution s;
	vector<int> a={1,2,3,4,5,6,7};
	s.reOrderArray(a);
}
