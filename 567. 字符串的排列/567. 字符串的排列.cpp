#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-14
/*
1.������ѣ���ȥ��һ����û��ʲô˼·���ѵ�Ҫһһ�ж��ַ������е����У��е��Ѷȡ�
2.���Ҳ����˫ָ�����Ŀ�ɣ��������д�Ļ���һһ�ж�ÿ��ȫ�����Ƿ���s2�У��ͺܱ�����
3.����grandyang�Ľⷨ�����Ǿ���ͦ���ӵģ������ֶ�����һ�°ɡ�
s1=ab,s2=eidbaooo
a=1,b=1
l=0,r=0:m[e]=-1,l=1,m[i]=1
l=1,r=1:m[i]
�ҿ��ˣ��������ˣ�������Ϊû�и����ǰ++�ͺ�++�Ĺ�ϵ��


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        vector<int> m(128);
        for (char c : s1) ++m[c];
        for (int right = 0; right < n2; ++right) {
            m[s2[right]]--;
            if ( m[s2[right]]< 0) {//ע��ǰ++�ͺ�++������
                m[s2[left]]++;
                while (m[s2[left]]!= 0) {//��������΢������һ��
                    left++;
                }
                //�������Ի���ǣ��ж���right����s1�У������ƶ�left������ôȷ��left
                //��û�г���right�أ��ͺ���ְ���
            } else if (right - left + 1 == n1) return true;
        }
        return n1 == 0;
    }
};
����������ϰ�ɡ�
*/
//10-15
/*
1.����д��̫�������Ҳ�����ԭ���ͺ����Σ�����һ��������ϣ��Ľⷨ����Ҳ�벻��������ôд���ˡ�
̫���ˣ��ѵ�ͷͺ������Ѫ�����ѣ�������
2.����Ҫдһ����������ķ��������ַ����Ǻö಩�Ͷ�����ôд�ġ�
3.https://zhuanlan.zhihu.com/p/76887991�������ҵ�һ�����ܿ�����д���ˣ�
4.grand��д��������Ŀ��������������ˣ�����Լ��ˡ���
*/

//11-16

//class Solution {
//public:
//    bool checkInclusion(string s1, string s2) {
//        //�ǰ����Ӵ������ǰ��������С�
//        //����ڶ������������������а�����ab�����С�
//        unordered_map<char,int> need;//s1����ֱ�ӳ�ʼ����
//        for(auto c:s1)
//            need[c]++;
//        int left=0,right=0;
//        while(right<s2.size()){
//            //���������76�Ⲣ��һ����������Ӵ������о�������Ǹ����Ӹ����ˡ�
//            if(need.count(s2[i])!=0){//����жϿ϶��ǲ��Եģ�ba��
//                left=i;
//                //����϶����ܲ���need�ɣ�
//                //��Ҫ��¼��ǰ��������������ĸ��𡣷�����
//            }
//        }
//    }
//};
//
/*
 * 1.���ˣ�ԭ������ǰ�˼ҵĽⷨ������������
 * 2.��76����Ҫ�������������Сleft��ʱ����жϣ�ǰ����ͨ��valid==need.size()����������ͨ��
 * */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(auto c:s1)
            need[c]++;
        int left=0,right=0,valid=0;
        while(right<s2.size()){
            char c=s2[right++];
            if(need.count(c)){
                win[c]++;//Ҫע��������++
                if(win[c]==need[c])
                    valid++;
            }
            while(right-left>=s1.size()){
                if(valid==need.size())
                    return true;
                c=s2[left++];
                if(need.count(c)){
                    if(win[c]==need[c])
                        valid--;
                    win[c]--;//�����--��
                }
            }
        }
        return false;
    }
};//����AC�ˣ�ģ���������־��ǣ�

//12-7��ϰ
/*
 * 1.����û��������˼·����Ϊ��֪��left��ô�ƶ���
 * while(right-left>=s1.size())������ƶ�left��while�ж����̫ţ���˺��𣡣������һ��ǵø�ϰ
 * ���ǲ�̫�а���
 * */

//12-23
/*
 * 1.˼·���������ڣ����ȶ�s1�и����ַ����ֵĴ�����¼��ϣ����s2���ڱ�����������С��������right-left>=s1.size()���жϴ������Ƿ��ܸ���s1�����ܸ��ǵĻ�left�����ƶ���
���Ӷȣ�O(n),O(m+n)
  �ǽ�������˼·�ġ�
 * */

//2021-6-10
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //�����������
        int n1=s1.size(),n2=s2.size();
        int valid=0;
        //ͳ��s1�г��ֵ��ַ�
        unordered_map<char,int> um1,win;
        for(auto&c :s1)
            um1[c]++;

        int left=0,right=0;
        while(right<n2){
            char c=s2.at(right++);
            if(um1.count(c)){
                win[c]++;
                if(win[c]==um1[c])
                    valid++;
            }
            if(right-left==n1){//��Ҫ�ƶ��󴰿�
                if(valid==um1.size())return true;//������Ҫ�Ͳ�ͬ�ĸ����Ƚϣ�ע�ⲻ�Ǻ�n1�Ƚ�
                c=s2[left++];
                if(um1.count(c)){
                    if(win[c]==um1[c])
                        valid--;
                    win[c]--;
                }
            }
        }
        return false;
    }
};
/*
 * 1.��ϰд�����ˣ�����ֻ�����8%��������ô���£�
 * 2.����������������Ľⷨ���൱��డ��ѧϰ�ˡ������һ��Ǹ�ϲ��������Ľⷨ��
 * */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // �ų��쳣�ı߽������Ҳ�޶���ģʽ���ĳ���
        if(s1.size() > s2.size()) return false;

        // ƥ����õĴ��ڴ�СΪģʽ����С
        int windowSize = s1.size();

        // ģʽ�����ֵ䣺���Կ���һ��Ƶ�ʷֲ�
        vector<int> hashmap1(26, 0);
        // ��̬���µ�ƥ�䴰���ֵ�
        vector<int> hashmap2(26, 0);

        // �����ֵ�
        for(int i = 0; i < windowSize; i++) {
            hashmap1[s1[i] - 'a']++;
            hashmap2[s2[i] - 'a']++;
        }

        // ����ÿһ�ֻ�����ѯ����������ֵ����(Ƶ�ʷֲ�һ��)��������
        for(int i = windowSize; i < s2.size(); i++) {
            // �����ֵ����(Ƶ�ʷֲ�һ��)��������
            if(hashmap1 == hashmap2) return true;

            // �������һ������������� hash ��Ĳ�����Ϊ��ӦƵ�ʵ�����
            hashmap2[s2[i - windowSize] - 'a']--;
            hashmap2[s2[i] - 'a']++;
        }

        // �����㷨��������ҿ����䣬��������һ������û���ж�
        return hashmap1 == hashmap2;
    }
};
int main(){
    Solution s;
    cout<<s.checkInclusion("ab","eidbaooo");
    return 0;
}
