#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月27日上午1:13:23
class Solution {
public:
    static bool cmp(int x,int y){
        long long dx=10,dy=10;//这里需要是long long
        // int xx=x,yy=y;
        // while(xx){//这样写判断不好，因为如果x为0的话，那么它实际上应该是10才对。
        //     dx*=10;
        //     xx/=10;
        // }
        // while(yy){
        //     dy*=10;
        //     yy/=10;
        // }
        while(dx<=x)dx*=10;
        while(dy<=y)dy*=10;
        return x*dy+y>y*dx+x;//[0,9,8,7,6,5,4,3,2,1]，针对这个样例过不了。
    }//0对应dx为1，9对应dy为2
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;
        if(nums[0]==0)return "0";
        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
        }
        return res;
    }
};
/*
 * 1.如何求一位数的位数，比较两个数的大小，学到了。
 * */
int main(){
	vector<string> strs={"1,1","2,2","1,2","1,3"};
	vector<vector<int>> nums;
	for(auto& str:strs){
		int index=str.find(",",0);//从0下标开始找“，”逗号
		int x=stoi(str.substr(0,index));//从0开始截取index个字符（包括0的位置）
		int y=stoi(str.substr(index+1));//截取index+1之后的所有字符
		nums.push_back({x,y});
	}
	for(auto& n:nums)
		cout<<n[0]<<" "<<n[1]<<"\n";
    return 0;
}
