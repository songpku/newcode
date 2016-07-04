class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //����һ������map���ҵ����ִ�������һ������֣�
        /*int half=numbers.size()/2;
    	unordered_map<int,int> times;
        for(vector<int>::const_iterator iter = numbers.begin(); iter!=numbers.end();iter++){
            if(times.find(*iter)!=times.end()){
                ++times[*iter];
            }else{
                times[*iter]=1;
            }
            if(times[*iter]>half)
               return *iter;
        }
        return 0;*/
        //���������������飬���һ�������ִ�������һ�룬�������һ��Ҳ�����������в�������λ��
        /*
        int middle=numbers.size()>>1;
        int left=0,right=numbers.size()-1;
        int index=quick_partition(numbers,left,right);
        while(index != middle){
            if(index < middle){
                left = index+1;
            }else{
                right=index-1;
            }
            index=quick_partition(numbers,left,right);
        }
        int sum=0,half=numbers.size()>>1;
        for(int i:numbers){
            if(numbers[index] == i)
                ++sum;
            if(sum >half)
                return numbers[index];
        }
        return 0;
        */
        //���������������飬���һ�������ִ�������һ�룬����������ֵĴ�������������������Ҫ��
        //��������ret��times����������,��times==0����times=0����������ret��ȣ���times++������times--.
        //�����ִ�������һ������϶���ret��.
        if(numbers.size()==0)
            return 0;
        int ret,times=0;
        for(int i=0;i<numbers.size();i++){
            if(times == 0){
                times =1;
                ret = numbers[i];
            }else if(numbers[i] == ret){
                ++times;
            }else{
                --times;
            }
        }
        int sum=0,half=numbers.size()>>1;
        for(int i:numbers){
            if(ret == i)
                ++sum;
            if(sum >half)
                return ret;
        }
        return false;
        
    }
    int quick_partition(vector<int> &a, int l, int r){
        if (l >= r)
            return l;
        int left = l;
        int right = r;
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
        return l;
	}
    
};
