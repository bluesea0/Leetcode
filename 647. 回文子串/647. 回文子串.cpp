#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��8��29������10:06:21
class Solution {
public:
    int countSubstrings(string s) {
        //������չ��������ÿһ�����ĵ㣬���ĵ����Ϊһ���������Գ�
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<2;j++){//��ʾ��չ�Ĵ�С������Ϊ����������Ϊ����
                int l=i,r=i+j;
                while(l>=0&&r<s.size()&&s[l]==s[r]){
                    ans++;
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}
