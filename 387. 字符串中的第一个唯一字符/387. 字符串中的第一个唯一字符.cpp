#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��23������3:36:02
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occ(26,0);
        for(auto c:s)
            occ[c-'a']++;
        for(int i=0;i<s.size();i++){
            if(occ[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};//�о����û��ʲô�ر�ġ����Կ϶�Ҳ��������������Ŀ�ɡ�

int main(){

    return 0;
}
