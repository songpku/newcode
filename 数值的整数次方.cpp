/*
��ֵ�������η�
��Ŀ����
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/ 
class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent==0)
            return 1;
        double ret=1.0;
        bool flag = false;
        if(exponent<0){
            exponent = 0-exponent;
            flag=true;
        }
        //�ⷨһ��ֱ����
        /*
        for(int i=0;i<exponent;i++){
            ret*=base;
        }*/
        //�ⷨ��:Ч�ʸ���
        ret = PowerWithIntExponent(base,exponent);
        if(flag){
            if(base>-0.0000001&&base<0.0000001){  //���ǳ���Ϊ0�����
                return 0;
            }
            return 1/ret;
        }
        return ret;
    }
    double PowerWithIntExponent(double base,int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double ret=PowerWithIntExponent(base,exponent>>1);
        ret *= ret;
        if(exponent & 0x1 == 1){//�ж��Ƿ��ǻ���
            ret *= base;
        }
        return ret;
    }
};
