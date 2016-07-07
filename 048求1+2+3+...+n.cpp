/*
求1+2+3+...+n
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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
        return Array[!!n]->sum(n-1)+n; //n==0时!!n=0,n>0时!!n=1
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
        //解解法一：利用构造函数实现循环
        /*
        SUM::reset();
        SUM* s = new SUM[n];
        int ret = s->get_s();
        delete[] s;
        s=NULL;
        return ret;*/
        //解法二，利用虚函数，基类返回0，派生类返回f(n-1)*n
        /*
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        return b.sum(n);*/
        //解法三利用函数指针
        return sum_nonzero(n);
    }
};

