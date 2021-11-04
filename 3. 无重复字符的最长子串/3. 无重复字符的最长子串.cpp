#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
//10-13
/*
1.�о����ѣ���ֻ���뵽һ��O(n2)�ķ���������
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                string t=s.substr(i,j-i);
                //д���Լ����о��ᳬʱ�����ˣ�д����ȥ��
                //����һ���ֵ䣿�ж��Ƿ�����ظ������鷳����
            }
        }
    }
};
/*
2.https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
��������������⣬����Ĳ������л���������Ŀ�Ļ��ܣ�ѧ���ˡ��⼸����Ҫ��һ�������������
�о��������Ѷȵģ����⼸�����ƽ��ˣ�
*/
//10-14
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans=0,start=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){//����ôд�Ǵ�ģ��������ˡ�ԭ������������
                st.erase(s[i]);//��ɾ������ߵģ���start��ʼɾ��һֱɾ��������
                start=i;//���컹�ǵø�ϰ����
            }
            st.insert(s[i]);
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
/*
1.����2�и������������кܶ໬�����ڵ���Ŀ�����Ǻö඼��hard����ֻ��209��567��m������ֻ���������ɡ�
*/
//10-15
/*
1.��Ӧ��ָoffer48�⡣
2.AC�ˡ�
*/
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,len=s.size();
        unordered_set<char> st;
        for(int i=0;i<len;i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
//10-22
/*
1.����1����Ӵ���������뵽�������ڣ����������û�и����������Ҳ���ǻ������ڽⷨ��
*/

//11-16
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,right=0;
        unordered_set<char> st;
        while(right<s.size()){
            char c=s[right];
            right++;
            if(st.count(c)==0){
                ans=max(ans,right-left);//����Ͳ���+1��
            }else{
                while(st.count(c)){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(c);
        }
        return ans;
    }
};
/*
 * 1.����ģ���˼·���ģ��аɣ�������AC���У��Լ�Ҳ�����û�������������
 * */

//2-10
/*
 * 1.��Ҫ��ס�����ڵ���left��ʱ��һ���Ǹ���ans��ʱ��ÿ���ƶ�rightҲ�����ans��
 * */

//5-26
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,right=0;
        unordered_set<char> us;
        while(right<s.size()){
            char c=s[right];
            right++;

            while(us.count(c)){//��С������߽�
                us.erase(s[left]);
                left++;
            }
            us.insert(c);
            ans=max(ans,right-left);//right�Ѿ������ƶ��ˣ�����Ҫ��+1�ˡ�
        }
        return ans;
    }
};
/*
 * 1.������Ŀ�����˵���ǱȽϼ򵥣���ס�������裬whileѭ���ڣ��ƶ�right+�Ƿ����������ƶ�left+����ans
 *   �����������ǲ��еģ�ͬ�ȵ�λ�ġ�
 * */
int main(){
    Solution2 s;
    cout<<s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
