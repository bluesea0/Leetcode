#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��10������1:50:32
class Solution {
public:
    string getPermutation(int n, int k) {
        //��ô����ʵ���򵥵İ�
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            nums[i]=i+1;
        while(--k)next_permutation(nums.begin(),nums.end());
        string s;
        for(auto& n:nums)
            s.push_back(n+'0');
        return s;
    }
};
/*
 * 1.Ͷ��ȡ����һ�£�ֱ�����˿⺯�����⣬������ǣ���ô��ֱ����31����Ǹ���һ��ȫ����Ҳok�İɡ�
 * 2.ֱ�Ӱ�31��ĸ��ƹ�ȥҲ�С�
 * */
int main(){

    return 0;
}
