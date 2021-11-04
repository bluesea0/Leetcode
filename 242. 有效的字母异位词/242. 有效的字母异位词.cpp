#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��22������10:24:48
class Solution {
public:
    bool isAnagram(string s, string t) {
        //�ֱ�������hash��Ȼ��Ƚ�������ϣ�Ƿ���ͬ
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> ms;
        for(auto c:s)
            ms[c]++;//�����϶��Ǵ�0��ʼ�ӵİ�
        for(auto c:t){
            if(ms.count(c)==0)return false;
            ms[c]--;
        }
        //�ٱ���ms��ÿ���ؼ����Ƿ�Ϊ0
        for(auto m:ms){
        	if(m.second!=0)return false;
        }
        return true;
        //������ô�ж��أ��ȽϹؼ��ֶ���ͬ���������ͬʱ��������map���ҹ��ˡ�
        //Ҳ����ֻ����s�Ĺ�ϣ��Ȼ����tȥ�жϣ���Ϊ���ܲ������У��Ǿ�ֱ�ӷ��ذ�
    }
};
/*
 * 1.AC�ˣ�һ��ʼ�����Ǹ���������ô˵�أ���ȥ�ж�first�Ƿ�Ϊ0�����ˡ�first�ǹؼ��ְ���
 * */

//12-20
/*
 * 1.���츴ϰ��ע�⵽���н��ף������Unicode�ַ���ô�죬������һ���ַ���Ӧ����ֽڣ�Ҳ����һ���ֽ�
 *   ��ʾ�����ַ�������Ҫ�����ֽ�,2^16��������ʾ�����Ծ���Ҫ�ù�ϣ������ʾ��
 * 2.�´θ�ϰҪ��дһ�´��룬�����̫���ˡ�
 * */
int main(){
	Solution s;
	cout<<s.isAnagram("anagram", "nagaram");
    return 0;
}
