#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-15
/*
1.��ȥ��easy����Ŀ����ô�ѣ��ҵ�һ�뷨��Ҫ��hash������������ô�����أ�
*/
class Solution {
public:
//    char firstUniqChar(string s) {//����д���Ǵ�İ����˼�˵����s�еġ��������ǰ�����ĸ��ġ���
//        vector<int> chars(26);
//        for(auto ss:s){
//            chars[ss-'a']+=1;
//        }
//        for(int i=0;i<chars.size();i++){//���ﳤ�ȸ���ô�����أ�
//            if(chars[i]==1)
//                return i+'a';
//        }
//        return ' ';
//    }
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto ss:s)
            mp[ss]+=1;
        for(auto ss:s){
            if(mp[ss]==1)
                return ss;
        }
        return ' ';
    }
};
/*
2.�����AC�ˣ���Ȼ������һ�Ṥ�򡣡���
���츴ϰ��ʱ���ٿ�����ɡ�
*/
//10-19
/*
1.����ʱ��������һ�£���������ֻ��ͨ��һ�α����������������ƺ�������ˡ�
  ����һ�¾�Ե�ӵĽⷨ��Ҳ����ôд�ģ���������򵥵���Ͳ����ٻ������ˡ�
*/
int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode");
    return 0;
}
