class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //方法一：暴力，但是时间复杂度太大了
        /*
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
        return n-1;*/
        //方法二，实现方式1
        if(index <= 0)
            return 0;
        vector<int> uglyNumbers(index);
        uglyNumbers[0] = 1;
        vector<int>::iterator iter2=uglyNumbers.begin();
        vector<int>::iterator iter3=uglyNumbers.begin();
        vector<int>::iterator iter5=uglyNumbers.begin();
        vector<int>::iterator iterMax=uglyNumbers.begin();
        int foundIndex=1;
        while(foundIndex < index){
            *(++iterMax)=min((*iter2)*2,min((*iter3)*3,(*iter5)*5));
            while((*iter2)*2 <=*iterMax){
                ++iter2;
            }
            while((*iter3)*3 <=*iterMax){
                ++iter3;
            }
            while((*iter5)*5 <=*iterMax){
                ++iter5;
            }
            ++foundIndex;
        }
        return *iterMax;
        /*实现方式2
        if(index <= 0)
            return 0;
        int numbers[index];
        numbers[0]=1;
        int *p2,*p3,*p5;
        p2=p3=p5=numbers;
        int n=1;
        while(n<index){
            numbers[n]=min(*p2*2,min(*p3*3,*p5*5));
            while(*p2*2<=numbers[n]) //所有小于当前数组中最大的数的丑数在下一轮都不参与运算
                ++p2;
            while(*p3*3<=numbers[n])
                ++p3;
            while(*p5*5<=numbers[n])
                ++p5;
            ++n;
        }
        return numbers[index-1];*/
        //解法三、《参考程序员面试金典》伪代码如下
        /*
            1）初始化array和队列：Q2 Q3 Q5
            2）将1插入array
            3）分别将1*2、1*3 、1*5插入Q2 Q3 Q5
            4)令x为Q2 Q3 Q5中的最小值，将x添加至array尾部
            5）若x存在于：
                Q2：将 x * 2、x * 3、x*5 分别放入Q2 Q3 Q5，从Q2中移除x
                Q3：将 x * 3、x*5 分别放入Q3 Q5，从Q3中移除x
                Q5：将 x * 5放入Q5，从Q5中移除x
            6）重复步骤4~6，知道找到第k个元素 */
        /*
        if(index <= 0)
            return 0;
        int foundIndex=0;
        queue<int> q2,q3,q5;
        q2.push(1);
        int v2,v3,v5,vmin;
        while(foundIndex < index){
            v2=q2.empty()?INT_MAX:q2.front();
            v3=q3.empty()?INT_MAX:q3.front();
            v5=q5.empty()?INT_MAX:q5.front();
            
            vmin = min(v2,min(v3,v5));
            if(vmin == v2){
                q2.push(vmin*2);
                q3.push(vmin*3);
                q2.pop();
            }else if(vmin == v3){
                q3.push(vmin*3);
                q3.pop();
            }else{
                q5.pop();
            }
            q5.push(vmin*5);
            ++foundIndex;
        }
        return vmin;
        */
    }
    int minUgly(int u2,int u3,int u5){
        u3 = min(u2,u3);
        u5 = min(u3,u5);
        return u5;
    }
    //分解因式 
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
