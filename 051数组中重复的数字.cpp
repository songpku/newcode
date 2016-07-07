/*
�������ظ�������
��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        //�ⷨһ������unordered_map��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
        //�ⷨ����������������[0,n-1]����û���ظ������֣����ź����������±��Ԫ��Ӧ����ȡ�
        //1���������飬�����±�i,��i!=a[i]��Ӧ����a[i]��a[a[i]]��֪��i=a[i]
        //2���ڽ����Ĺ����У���a[i] = a[a[i]]��˵�����ظ��ġ�
        //ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
        if(length < 2)
            return false;
        for(int i=0;i<length;i++){
            while(i!=numbers[i]){
                if(numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i],numbers[numbers[i]]); //����һ�β��ܱ�֤iλ���ϵ����Ƕ�Ӧ�ģ�����һ���ܱ�֤a[i]
                									//λ���ϵ������Եģ�����ƽ������ÿ������ֻ����һ�Ρ�
            }
        }
        return false; 
    }
};
