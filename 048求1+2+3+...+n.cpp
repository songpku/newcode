/*
��1+2+3+...+n
��Ŀ����
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/ 
class SUM{
  public:
    SUM(){
        ++n;
        s+=n;
    }
    static int get_s(){
        return s;
    }
    static void reset(){
        n=s=0;
    }
   private:
    static int n;
    static int s;
};
int SUM::n = 0;
int SUM::s = 0;
class A;
A* Array[2];
class A{
  public:
    virtual int sum(int n){
        return 0;
    }
};
class B:public A{
  public:
    int sum(int n){
        return Array[!!n]->sum(n-1)+n; //n==0ʱ!!n=0,n>0ʱ!!n=1
    }
};

typedef int (*fun)(int n);
int sum_zero(int n){
    return 0;
}
int sum_nonzero(int n);
fun f[2]={sum_zero,sum_nonzero};
int sum_nonzero(int n){
    return n+f[!!n](n-1);
}
class Solution {
public:
    int Sum_Solution(int n) {
        //��ⷨһ�����ù��캯��ʵ��ѭ��
        /*
        SUM::reset();
        SUM* s = new SUM[n];
        int ret = s->get_s();
        delete[] s;
        s=NULL;
        return ret;*/
        //�ⷨ���������麯�������෵��0�������෵��f(n-1)*n
        /*
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        return b.sum(n);*/
        //�ⷨ�����ú���ָ��
        return sum_nonzero(n);
    }
};

