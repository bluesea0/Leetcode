#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��18������2:27:30
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0)return t[0];//return����char���������Ҫע��
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int k=0;
        while(k<s.size()){
            if(s[k]!=t[k])break;
            k++;
        }
        return t[k];
    }
};
//��Ȼ��ֻ�뵽��������ǻ�ȥ��֪ͨ�Ľⷨ�����˹ٷ��������֣���Ļ�Ȼ����
//������λ���㡢ASCIIֵ��͡�

//12-18
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        //ʹ��ASCIIֵ
        int sum=0;
        for(auto c:s)
            sum+=c;
        for(auto c:t)
            sum-=c;
        return -sum;//ע�������Ǹ�ֵŶ����Ϊ��t����һ����ĸ
    }
};
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        //λ����
        int ans=0;//ֱ����int����
        for(auto c:s)
            ans^=c;
        for(auto c:t)
            ans^=c;
        return ans;
    }
};
int main(){

    return 0;
}
