/*
扑克牌顺子
题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        //1、不能有对子
        //2、排序，查找不连续的数字数
        //3、查找0的个数，看是否和不连续的数字相等
        //map既可以统计次数又可以排序，所以是最佳选择
        if(numbers.size() == 0)
            return false;
        int zeroTimes=0,noncontinue=0;
        map<int,int> times;
        for(int i:numbers){
            auto ret = times.insert({i,1});  //返回的是一个pair。pair.first是一个迭代器。pair.second是一个bool变量
            if(!ret.second ){
                if(ret.first->first != 0)
                	return false;
                ++ret.first->second;
            }
        }
        if (times.count(0)>0){
			zeroTimes = times[0];
			times.erase(0);
		}
        map<int,int>::iterator iter=times.begin();
        map<int,int>::iterator pre = iter;
        ++iter;
        for(;iter!=times.end();iter++,pre++){
            noncontinue += iter->first - pre->first - 1;
        }
        if(zeroTimes >= noncontinue)
            return true;
        return false;
    }
};
