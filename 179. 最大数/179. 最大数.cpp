#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��27������1:13:23
class Solution {
public:
    static bool cmp(int x,int y){
        long long dx=10,dy=10;//������Ҫ��long long
        // int xx=x,yy=y;
        // while(xx){//����д�жϲ��ã���Ϊ���xΪ0�Ļ�����ô��ʵ����Ӧ����10�Ŷԡ�
        //     dx*=10;
        //     xx/=10;
        // }
        // while(yy){
        //     dy*=10;
        //     yy/=10;
        // }
        while(dx<=x)dx*=10;
        while(dy<=y)dy*=10;
        return x*dy+y>y*dx+x;//[0,9,8,7,6,5,4,3,2,1]�����������������ˡ�
    }//0��ӦdxΪ1��9��ӦdyΪ2
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
 * 1.�����һλ����λ�����Ƚ��������Ĵ�С��ѧ���ˡ�
 * */
int main(){
	vector<string> strs={"1,1","2,2","1,2","1,3"};
	vector<vector<int>> nums;
	for(auto& str:strs){
		int index=str.find(",",0);//��0�±꿪ʼ�ҡ���������
		int x=stoi(str.substr(0,index));//��0��ʼ��ȡindex���ַ�������0��λ�ã�
		int y=stoi(str.substr(index+1));//��ȡindex+1֮��������ַ�
		nums.push_back({x,y});
	}
	for(auto& n:nums)
		cout<<n[0]<<" "<<n[1]<<"\n";
    return 0;
}
