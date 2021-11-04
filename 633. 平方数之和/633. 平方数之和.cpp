#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
//2020年12月3日下午3:48:09
//class Solution {
//public:
//    bool judgeSquareSum(int c) {
//        int i=0,j=int(sqrt(c));//不是四舍五入，是将小数点部分都去掉
//        //在math.h头文件中
//        while(i<=j){
//        	cout<<i<<" "<<j<<" ";
//            int s=i*i+j*j;//2147482647，给我溢出了？
//            cout<<s<<endl;
//            //但是c不是能用int表示吗？为什么s反倒溢出了呢？
//            if(s==c)return true;
//            else if(s<c) i++;
//            else j--;
//            if(i==5)break;
//        }
//        return false;
//    }
//};//心累，以为easy的题目还会比较好解决呢，没想到啊，有点心累了。
//上面使用双指针的思想，s的地方溢出了，哭泣啊。

//12-6
class Solution {
public:
    bool judgeSquareSum(int c) {
    	for(long long a=0;a*a<=c;a++){//注意这里要有=号的啊，大姐。
    		double b=sqrt(c-a*a);
    		if(b==int(b))//居然可以这么来判断int和double时是否相同啊！
    			return true;
    	}
    	return false;
    }
};
/*
 * 1.需要注意的是：a是long long类型的，for循环有=号。时间O(n^2)。
 * 2.评论区中同样也提到了因为溢出所以需要修改代码的情况，那么我修改一下。
 * */
class Solution2 {
public:
   bool judgeSquareSum(int c) {
       int i=0,j=sqrt(c);//在定义j的类型时就已经默认强制转换了，就不必再显示地转换了
       //在math.h头文件中
       while(i<=j){
           if(i*i==c-j*j)return true;
           else if(i*i<c-j*j) i++;
           else j--;
       }
       return false;
   }
};
//修改了之后又AC了，不错子。时间复杂度其实也是O(根号c)。
int main(){
	Solution s;
	cout<<s.judgeSquareSum(2147482647);
    return 0;
}
