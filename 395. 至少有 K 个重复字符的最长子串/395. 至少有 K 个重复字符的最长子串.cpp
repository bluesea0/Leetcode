#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��21������10:57:01
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res=0;
        for(int i=1;i<=26;i++){
            int left=0,right=0,ct=0;//ct��¼��ǰ�����ַ�����������
            vector<int> chars(26,0);//��¼��Χ�ڵ��ַ�����
            while(right<s.size()){
                bool flag=true;//ÿ�δ��ڱ䶯��ʱ��Ҫ�ж�
                chars[s[right]-'a']++;
                if(chars[s[right]-'a']==1)ct++;
                right++;
                while(ct>i){//��ǰ���೬��������������
                    chars[s[left]-'a']--;
                    if(chars[s[left]-'a']==0)ct--;
                    left++;
                }
                //�жϴ������Ƿ��в�����������
                for(int j=0;j<26;j++){
                    if(chars[j]>0&&chars[j]<k){
                        flag=false;break;
                    }
                }
                if(flag)res=max(res,right-left);
            }
        }
        return res;
    }
};
/*
 * 1.�ο�grand��д�����ģ�����ö�ٻ��������е��ַ������ֵ��Ȼ�󻬴��ڸ������ȥ������
 *   ��ʵ�Ҳ��Ǻ��������ԭ��������Ҫ��¼�ж������ַ�����Ҫ�󣬼�����>k�ġ�
 * 2.���������˼·�Ļ�������Ҫö��ÿһ���ַ�������n2����ģ�����ͳ�ƻ����ڵ��ַ����༰������
 * */
int main(){

    return 0;
}
