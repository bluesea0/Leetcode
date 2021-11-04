#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月5日下午11:28:09
/*
 * 1.这道题实在是很难，可以视为是多个有序数组的归并，那么就需要用到小顶堆，还需要自己构造数据结构
 *   对数据结构重构> 即greater操作符，挺难的，这个需要技术啊。但这个只利用到了每行是有序的这个性质。
 * 2.在利用二分法的时候，l和r是最小和最大值，然后从左下角开始比起，计算小于等于mid的所有的个数x，和k
 *   比较大小，决定l和r的重新指向：如果x>k的话那么r=mid，否则l=mid。学习了。
 * */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //使用归并排序的方法，借助优先级队列构造小顶堆
        struct num{
            int val,i,j;
            num(int val,int i,int j):val(val),i(i),j(j){}
            bool operator> (const num& a)const {return this->val>a.val;}
            //这里比较的时候a在前还是this在前？
            //官方也写的this在左边，我认为是将this作为左值了，就像i++
        };
        priority_queue<num,vector<num>,greater<num>> pq;
        for(int i=0;i<matrix.size();i++)
            //pq.emplace_back(matrix[i][0],i,0);//pq是优先级队列啊
            //pq.push(matrix[i][0],i,0);
            pq.push(num(matrix[i][0],i,0));//原来是emplace啊
        for(int i=0;i<k-1;i++){
            num t=pq.top();
            pq.pop();
            if(t.j+1<matrix[0].size())
                //pq.emplace_back(matrix[t.i][t.j+1].val,t.i,t.j+1);
                //pq.push(matrix[t.i][t.j+1].val,t.i,t.j+1);
                pq.push(num(matrix[t.i][t.j+1],t.i,t.j+1));
        }
        return pq.top().val;
    }
};
/*
 * 1.遇到了些问题，关于使用STL时自己重写排序函数时greater或less时的结果。
 *   lamda重写cmp需要加const，但是T是指针则不加？
 * */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //二分的解法
        //太难了，难到头上冒油的感觉
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=l+((r-l)>>1);
            int ct=kth(matrix,mid);
            //其实相当于一个寻找左边界的二分？不是，其实是寻找右边界的二分？
            // if(ct==k){
            //     //l=mid;break;//这里不能=mid，因为mid不一定是矩阵中的数啊
            // }else if(ct<k){
            //     l=mid+1;
            // }else r=mid-1;//因为while条件中是<没有=号，所以
            if(ct<k)//这么写还是不对，那这个二分该怎么办啊。
                l=mid+1;
            else r=mid;
        }
        return l;
    }
    int kth(vector<vector<int>>& matrix,int mid){
        int n=matrix.size();
        int i=n-1,j=0,ct=0;
        while(i>=0&&j<n){
            if(matrix[i][j]<=mid){
                ct+=i+1;
                j++;
            }else i--;
        }
        return ct;
    }
};
/*
 * 1.二分的解法，挺难写的，需要复习通识的二分怎么写。
 * 2.针对给的样本，在计算过程中有：l=13,r=15,mid=14,ct=8，那么此时出现的问题是，虽然k==ct，但是你返回
 *   哪个？一般说是直接返回mid，但是mid不一定存在于矩阵中，也不能直接返回l，l在别的样例中可能不是答案
 *   所以这个二分其实挺难写的。
 * */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //二分的解法
        //太难了，难到头上冒油的感觉
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<=r){
            int mid=l+((r-l)>>1);
            int ct=kth(matrix,mid);
            if(ct<k)
                l=mid+1;
            else if(ct>k){
                r=mid-1;
            }else r=mid-1;//如果写r=mid，这样会陷入死循环中
        }
        return l;//返回也是l
    }
    int kth(vector<vector<int>>& matrix,int mid){
        int n=matrix.size();
        int i=n-1,j=0,ct=0;
        while(i>=0&&j<n){
            if(matrix[i][j]<=mid){
                ct+=i+1;
                j++;
            }else i--;
        }
        return ct;
    }
};
/*
 * 1.啊啊啊啊经过我的复习，我终于写出来了搜索区间为两端闭的[]，一定要注意一定要注意写的时候，自己
 *   不熟悉的二分，< > =一定要有三个分支来判断，不要将=随便和><合并，那样会混乱思路，会非常可怕的！
 * */
int main(){

    return 0;
}
