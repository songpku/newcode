class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //方法一：利用map，找到出现次数大于一半的数字；
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
        //方法二：对于数组，如果一个数出现次数大于一半，这这个数一定也出现在数组中部，即中位数
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
        //方法三：对于数组，如果一个数出现次数大于一半，则这个数出现的次数比其他数加起来还要多
        //用两个数ret和times，遍历数组,若times==0，则times=0；否则：若和ret相等，则times++，否则times--.
        //最后出现次数大于一半的数肯定在ret中.
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
            //顺序很重要，要先从右边开始找，否则要处理一些边界条件
            while (l<r && a[r] >= mid){
                --r;
            }
            //再从左边开始
            while (l<r && a[l] <= mid){
                ++l;
            }
            swap(a[l], a[r]);
        }
        //将基位写会，非常重要
        a[left] = a[l];
        a[l] = mid;
        return l;
	}
    
};
