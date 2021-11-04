#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月10日下午3:41:19
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res=0;
        if(flowerbed.size()==1&&flowerbed[0]==0)return n<=1;//[0] 1
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                int j=i;
                while(i+1<flowerbed.size()&&flowerbed[i+1]==0)i++;
                if((j==0||i+1==flowerbed.size())&&j!=i)//主要处理边界问题
                    res+=1;
                res+=(i-j)/2;
            }
        }
        return res>=n?true:false;
    }
};//[0,0,1,0,1] 1 天啦这样的样例怎么控制呢？
//我还是想的简单了点。。。
//那开头和结尾单独处理？
//天哪，绝了，还有[0] 1这样的，绝了绝了啊。应该是能插入一个的，这怎么整啊，我还要再多加判断吗？
//[1,0,0,0,0] 2绝了，我放弃了，应该是我这种方法不对吧
//绝了绝了，我懂了这个和样例1 0 0 0 1这种两边有1的是不一样的，我大意了啊，好难的。
/*
 * 1.天哪！我AC了！我太开心了吧！
 * 2.不过这道题边界样例好多啊，比如说0从左右开始，如果邻接共2个0，那么其实也可以+1的，还有像[0] 1这样的也都
 *   需要预处理的。
 * 3.看了官解才知道，原来是元旦那天的每日一题，但是我没有仔细看官解，下次复习看吧。
 * */
int main(){
	Solution s;
	vector<int> flowerbed={0,0,1,0,1};
	cout<<s.canPlaceFlowers(flowerbed, 1);
    return 0;
}
