/*
��ת�������С����

��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //����һ����˫��ѭ��������ʱ�临�Ӷ�̫�ߡ�
        /*
        if(rotateArray.size()==0)
            return 0;
        int minx = rotateArray[0];
        for(int i=1;i<rotateArray.size();i++){
            minx = min(minx,rotateArray[i]);
        }
        return minx;
        */
        //�����������ֲ���
        //���з�Ϊ������ǰ������������кͺ�������������
        //һ��a[l]<a[r],˵��ֻʣ�º���������,�����˳�
        //��a[l]<=a[m],˵��������������m֮��
        //��a[m]<=a[r],˵����Сֵ��m֮ǰ��
        //��l = r -1,ʱ����������� ��100,1��1,2�������˳�����Сֵ��
        
        int left = 0,right = rotateArray.size()-1,mid;
        while(rotateArray[left]>=rotateArray[right]){
        	if((right - left) == 1)
                break;
            mid = (right + left)/2;
            if(rotateArray[left] == rotateArray[mid] &&  //�ڷǵݼ����飨�����ظ���������µ��������{1,0,1,1,1}{1,1,1,0,1}
               rotateArray[mid] ==rotateArray[right]){
                int ret = rotateArray[left];
                for(int i=left;i<=right;i++){
                    if(ret>rotateArray[i])
                        ret = rotateArray[i];
                }
                return ret;
            }
            if(rotateArray[left] <= rotateArray[mid]){
               left = mid;
            }else if(rotateArray[mid] <= rotateArray[right]){
                right = mid;
            }
        }
        return min(rotateArray[left],rotateArray[right]);
    }
};
