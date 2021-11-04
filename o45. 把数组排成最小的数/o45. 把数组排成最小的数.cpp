#include <iostream>
#include<vector>
#include<queue>
//#include<string>
//#include<stdlib>
using namespace std;
//10-9
//1.我记得有一个快排，还有一个写了sort的规则，将它作为库函数sort的排序方式。
//2.非常令人沮丧的是，我好像还是搞不懂快排啊！去B站看了快排的视频。
//
class Solution {
private:
    void quick(vector<string>& nums,int fr,int to){
        if(fr>=to) return ;
        int p=fr;
        int i=fr,j=to;
        while(i<j){
            while(i<j && nums[p]+nums[j]<nums[j]+nums[p]) j--;
            while(i<j && nums[p]+nums[i]>=nums[i]+nums[p]) i++;//因为i从fr也就是pivot开始，所以要加=
            //我对上面两处要不要加等号很迷惑啊
            string t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        string t=nums[p];
        nums[p]=nums[j];
        nums[j]=t;
        quick(nums,fr,j-1);
        quick(nums,j+1,to);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int i=0;i<nums.size();i++){
            str_nums.push_back(to_string(nums[i]));//我居然卡在了int如何转换为string上。。。
        }
        quick(str_nums,0,str_nums.size()-1);
        string ans="";
        for (int i=0;i<str_nums.size();i++){
            ans+=str_nums[i];
        }
        return ans;
    }
};
//哇呜！AC了！太开心心了吧。
/*
10-9
https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
评论区中给出的解答快排中两个while循环都用了=号，那我明白了，以后我也加上=。

评论区中给出的重写库函数的解法，那我要学习一下C++的库函数sort了。
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string ans;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
         //下面实现的是C++中的匿名函数吗？
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});

        for (int i = 0; i < strs.size(); i++)
            ans += strs[i];

        return ans;
    }
};
*/

//5-25
class Solution {
public:
    static bool cmp(string x,string y){//这里最好传递引用！！就不会再复制了！！
        return x+y<y+x?true:false;//cmp函数要定义的比较是<号，小于的话返回true，否则false
        //准则就是这两个，而且要static函数。
    }
    string minNumber(vector<int>& nums) {
        //先给sort写一个排序函数
        //这里的排序规则是x+y<y+x，说明字符串x比y大。
        vector<string> strs;
        for(auto& n:nums){
            strs.emplace_back(to_string(n));
        }
        sort(strs.begin(),strs.end(),cmp);
        string ans;
        for(auto& s:strs)
            ans+=s;
        return ans;
    }
};
/*
 * 1.利用库函数sort重写了比较函数。注意事项列在上面。
 * 2.下面是写快排
 * */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        //同时基于快排来写一个
        vector<string> strs;
        for(auto& n:nums){
            strs.emplace_back(to_string(n));
        }
        quickSort(strs,0,(int)strs.size()-1);
        string ans;
        for(auto& s:strs)
            ans+=s;
        return ans;
    }
    void quickSort(vector<string>& strs,int left,int right){
        if(left<right){
            int p=partion(strs,left,right);
            quickSort(strs,left,p-1);
            quickSort(strs,p+1,right);
        }
    }
    int partion(vector<string>& strs,int left,int right){
        int p=left-1;
        for(int i=left;i<right;i++){
            if(strs[i]+strs[right]<=strs[right]+strs[i]){
                p++;
                swap(strs[i],strs[p]);//天哪，这里是和p交换，当然是和p交换了。。。
            }
        }
        swap(strs[right],strs[p+1]);
        return p+1;
    }
};
/*
 * 1.本来以为轻车熟路就能写出来了，但是居然我写错了，是因为交换的时候是i和p交换啊，不是i和left。。
 *   想啥呢，和left交换，肯定是p指向的位置是<=right的。p和i之间的都是>right的。
 * 2.尝试改为随机化快排。
 * */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        //同时基于快排来写一个
        vector<string> strs;
        for(auto& n:nums){
            strs.emplace_back(to_string(n));
        }
        rquickSort(strs,0,(int)strs.size()-1);
        string ans;
        for(auto& s:strs)
            ans+=s;
        return ans;
    }
    void rquickSort(vector<string>& strs,int left,int right){
        //主要负责生成一个随机数和right交换
        int t=rand()%(right-left+1)+left;
        swap(strs[t],strs[right]);
        quickSort(strs,left,right);
    }
    void quickSort(vector<string>& strs,int left,int right){
        if(left<right){
            int p=partion(strs,left,right);
            quickSort(strs,left,p-1);
            quickSort(strs,p+1,right);
        }
    }
    int partion(vector<string>& strs,int left,int right){
        int p=left-1;
        for(int i=left;i<right;i++){
            if(strs[i]+strs[right]<=strs[right]+strs[i]){
                p++;
                swap(strs[i],strs[p]);//天哪，这里是和p交换，当然是和p交换了。。。
            }
        }
        swap(strs[right],strs[p+1]);
        return p+1;
    }
};
//加入随机化快排也成功了。
int main(){
//    int a=1,b=2;
//    a,b=b,a;
//    cout<<a<<b<<endl;//12，说明没有交换成功，C++不能像python这么方便地交换。。。
//    Solution s;
//    vector<int> a={10,2};
//    cout<<s.minNumber(a);
	string s="  abcd";
	cout<<s.find(" ",1);//会从start开始找，并且包括start，如果start就是要找的字符串，那么就地输出。
    return 0;
}
