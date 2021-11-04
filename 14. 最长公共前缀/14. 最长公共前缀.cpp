#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��27������9:49:31
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0,k=0,count=0;
            while(j<ans.size()&&k<strs[i].size()&&ans[j]==strs[i][k]){
                j++;
                k++;
                count++;
            }
            if(count==0)return "";
            else ans=ans.substr(0,count);
        }
        return ans;
    }
};
/*
 * 1.��Ȼ���Ǹ�easy�������Ŀ�����Ǹо�д�����ò�������������룬��Ư����
 *   ���ӶȵĻ�������ƽ������Ϊm������n���ַ�������ô�������£����������ַ�����һ������ô����O(mn)
 * 2.����������һ��˵���ǣ�������������С���ǿ���һ�α�����ȡ�������С��Ȼ��Ƚϡ�
 * */
int main(){

    return 0;
}
