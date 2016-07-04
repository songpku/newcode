class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
    	int foundIndex=1;
        int n=2;
        while(foundIndex < index){
            if(isUgly(n)){
                ++foundIndex;
            }
            ++n;
        }
        return n-1;
    }
    bool isUgly(int n){
        while(n%2==0){
            n/=2;
        }
        while(n%3==0){
            n/=3;
        }
        while(n%5==0){
            n/=5;
        }
        return n==1;
    }
};
