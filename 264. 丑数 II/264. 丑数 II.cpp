#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-15
/*
1.感觉有点难，你怎么去排序呢？比如说按规律来
1、1*2、1*3、1*5？2*2？这该怎么来判断呢？真的不知道如何判断大小了，放弃。
2.手动跑一下：
1,2
i2=1,i3=0,i5=0
min(4,3,5)
1,2,3
i2=1,i3=1,i5=0
min(4,6,5)
1,2,3,4
i2=2,i3=1,i5=0
min(6,6,5)
1,2,3,4,5
手动跑的是下面grand的解法：
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};
还是有点难度的，需要复习
*/
//10-22
//是剑指offer的第49题。下面是我错误的解题过程！
//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        if(n==1)return 1;
//        int k=1,k2=1,k3=1,k5=1;
//        int ans=1;
//        while(k<n){
//            int t=min(k2*2,min(k3*3,k5*5));//不能这么算，这么算会出现重复的数。。。
//
//            ans=t;
//            cout<<k<<" "<<ans<<endl;
//            //1 2
//            //2 3
//            //3 4
//            //4 5
//            //5 6//因为3*2和2*3都是6，所以会有2个6.。。。
//            //6 6
//            //7 8
//            //8 9
//            //9 10
//            //10
//            if(t==k2*2)k2++;
//            if(t==k3*3) k3++;//这里改为if不是else if也是不对的，求第11个的时候
//            //14，但14并不是丑数啊。因为14=2*7，你的14是这么得到的，你一开始就想错了。
//            //丑数并不是单个的数++*2/3/5就可以的，而是要对已生成的丑数*2/3/5得到最小值。
//            if(t==k5*5) k5++;
//            k++;
//        }
//        return ans;
//    }
//};

//10-23
/*
1.我记得有个思路是因为n给定了范围，不超过1690，所以可以先将所有的都求出来。这种的使用场景就是
  频繁调用的时候，那样直接访问哈希，就可以了。
*/
class Solution1 {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> v={1};
        int k2=0,k3=0,k5=0;
        for(int i=1;i<n;i++){
            int t=min(v[k2]*2,min(v[k3]*3,v[k5]*5));//也只能
            if(t==v[k2]*2)k2++;
            if(t==v[k3]*3)k3++;
            if(t==v[k5]*5)k5++;
            v.push_back(t);
        }
        return v[n-1];
}};
/*
2.YesAC！
3.官方给的参考当中时间复杂度是O(1)时间检索答案和大约 1690 \times 5 = 84501690×5=8450 次的预计算操作。
  常数空间用保存 1690 个丑数。
4.但是看到评论区中说，字节面到了这道题，那我就要看看那个堆的解法了。使用堆的话，会有一个去重的过程，明天写一下。
  C++中的堆就是优先队列。
*/

//10-24
/*
1.尝试使用堆来求解。
*/
class Solution2 {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;
        pq.push(1);
        long ans,k=0;
        while(k<n){
            long t=pq.top();pq.pop();//这里要改为long！否则int会溢出！
            while(!pq.empty()&&t==pq.top())pq.pop();//这里要判断是否为空，否则会死循环。
            ans=t;
            pq.push(t*2);
            pq.push(t*3);
            pq.push(t*5);
            k++;

        }
        return ans;
    }
};

//10-29复习
/*
 * 1.这次复习的时候忽然想到第一种解法是怎么去重的呢，那就应该是每次判断都是if，而不是if else，这样2*3
 *   和3*2导致的6就会只放进来一次？我试一下。对是这样的，t2=3时，t3=2时，两个6，对应的下标都++；
 *2.复杂度：O(1) 时间检索答案和大约1690×5=8450 次的预计算操作。
 *  常数空间用保存 1690 个丑数。
 * */

//5-26
class Solution {
public:
    int nthUglyNumber(int n) {
        //p2指向下一个*2的丑数,p3,p5也是这样。
        int p2=0,p3=0,p5=0;
        vector<int> ans={1};
        while(--n){
            int t=min(min(ans[p2]*2,ans[p3]*3),ans[p5]*5);
            // if(t==ans[p2]*2)
            //     p2++;
            // else if(t==ans[p3]*3)//因为可能存在重复数字，所以要else
            //     p3++;
            // else p5++;//2 3 4 5 6 6 8 9 10
            if(t==ans[p2]*2)p2++;
            if(t==ans[p3]*3)p3++;
            if(t==ans[p5]*5)p5++;
            ans.push_back(t);
           // cout<<t<<" ";
        }
        return ans.back();
    }
};
/*
 * 1.我实在是绝了啊，今天刚连做三道，三道都有问题，我居然还自作聪明说，存在重复数字，所以要用else
 *   我的天，我之前犯过这个问题啊，我的天绝了啊。我哭了。想象着对面有面试官，我挺害怕的，就不敢多思考
 *   这不行啊，得多适应，而去分析问题啊。
 * */
int main(){
    Solution2 s;
    cout<<s.nthUglyNumber(10);
    return 0;
}
