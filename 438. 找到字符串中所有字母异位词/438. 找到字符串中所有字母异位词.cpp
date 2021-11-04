#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��16������4:55:49
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(auto c:p)
            need[c]++;
        int left=0,right=0,valid=0;
        vector<int> ans;
        while(right<s.size()){
            char c=s[right];
            if(need.count(c)){
                win[c]++;
                if(win[c]==need[c])
                    valid++;
            }
            //�����whileѭ�����漰��һ������������ˡ�����ұգ�
            while(right-left+1>=p.size()){//������û��=��
                if(valid==need.size())
                    ans.push_back(left);
                c=s[left];
                left++;
                if(need.count(c)){
                    if(win[c]==need[c])
                        valid--;
                    win[c]--;
                }
            }
            right++;//��֪���ˣ�ģ�����ǽ�right++���������棬������whileѭ����ʱ���û��+1������
        }
        return ans;
    }
};
/*
 * 1.AC�ˣ���ף˳����ʦ������
 * 2.ģ�壺https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 *
 * */
int main(){

    return 0;
}
