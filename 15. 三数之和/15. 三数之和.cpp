#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��11��27������12:05:57
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //˼·���������Ҫ����±꣬��ô��ֱ��sortȻ��˫ָ��
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        sort(nums.begin(),nums.end());
        //����Ҫ��nums.size()�����޸�
        for(int i=0;i<int(nums.size())-2;i++){//mad����֪���ˣ���Ϊ�����޷������������Բ��ܺ͸��űȽ�!
            if(i!=0&&nums[i]==nums[i-1])continue;//ȥ��
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    //ȥ��
                    while(j<k&&nums[j]==nums[j+1])j++;
                    while(j<k&&nums[k]==nums[k-1])k--;
                    j++;k--;
                }
                else if(nums[j]+nums[k]<-nums[i])
                    j++;
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
            }
        }
        return ans;//Ϊʲô��ѻ�������أ��������[0]
    }
};
/*
 * 1.������û�ˣ��߽����û�жϣ�nums�������Ϊ�գ�����vector��push_back������append������
 * 2.mad�ݣ��ύ�����ζ�ûͨ����Ҫ������ġ�������forѭ�������жϵĵط���Ҫ��-�ų���
 * 3.[-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]��mad���ڽ�����ϸ����⣬�������ûͨ������д���㷨
 *   �����⡣�����ˡ�������ĸ����̫�����ˡ�
 *   ��������ǣ��Ҳ���������ȥ�أ������ͽ����[[-2,1,1],[0,0,0]]���Ե��ˡ�����
 * 4.����������޸ģ�����AC�ˣ���Ҳ����ˡ�
 * */
int main(){
	Solution s;
	vector<int> a{-1,0,1,2,-1,-4};
	auto c=s.threeSum(a);
	cout<<c.size();
//	int a=1,b=-1,c=0;
//	if(a+b==-c)cout<<"hh";//����-0�����⡣
    return 0;
}
