class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //����һ������������ʱ�临�Ӷ�̫����
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
        //��������ʵ�ַ�ʽ1
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
        /*ʵ�ַ�ʽ2
        if(index <= 0)
            return 0;
        int numbers[index];
        numbers[0]=1;
        int *p2,*p3,*p5;
        p2=p3=p5=numbers;
        int n=1;
        while(n<index){
            numbers[n]=min(*p2*2,min(*p3*3,*p5*5));
            while(*p2*2<=numbers[n]) //����С�ڵ�ǰ�������������ĳ�������һ�ֶ�����������
                ++p2;
            while(*p3*3<=numbers[n])
                ++p3;
            while(*p5*5<=numbers[n])
                ++p5;
            ++n;
        }
        return numbers[index-1];*/
        //�ⷨ�������ο�����Ա���Խ�䡷α��������
        /*
            1����ʼ��array�Ͷ��У�Q2 Q3 Q5
            2����1����array
            3���ֱ�1*2��1*3 ��1*5����Q2 Q3 Q5
            4)��xΪQ2 Q3 Q5�е���Сֵ����x�����arrayβ��
            5����x�����ڣ�
                Q2���� x * 2��x * 3��x*5 �ֱ����Q2 Q3 Q5����Q2���Ƴ�x
                Q3���� x * 3��x*5 �ֱ����Q3 Q5����Q3���Ƴ�x
                Q5���� x * 5����Q5����Q5���Ƴ�x
            6���ظ�����4~6��֪���ҵ���k��Ԫ�� */
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
    //�ֽ���ʽ 
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
