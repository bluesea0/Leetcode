#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��7������3:47:43
//class Solution {
//public:
//    string findLongestWord(string s, vector<string>& d) {
//        //�ⲻ������Ϊ�ң�������˫ָ��ɽ�������⣿Ϊʲô��û��˼·�أ�
//        //������Ĳ��ᰡ
//    }
//};
//����������ǹ��ˣ����ַ������ݽ��������ء�

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        //˼·���ж�d�е�ÿ���Ƿ���s�������У�����ѡ�����
        //�������Ӷ�:O(m*n*c)��c��d���ַ�����ƽ������ O(1)�ռ�
        string ans="";
        for(auto dstr:d){
            if(subStr(dstr,s)&&(dstr.size()>ans.size()||(dstr.size()==ans.size()&&dstr<ans)))
                //���س�������ֵ�˳����С���ַ���
                ans=dstr;
        }
        return ans;
    }
    bool subStr(string d,string s){
        int i=0;
        for(int j=0;j<s.size();j++){
            if(d[i]==s[j]){//ע��iָʾd���±�
                i++;
                if(i==d.size())return true;
            }
        }
        return false;
    }
};
/*
 * 1.���������һ������֪ʶ�㣬�����ж�һ���ַ����Ƿ�����һ���ַ����������С���ʵ����ô�򵥣�˫ָ��
 *   ѧ���ˡ�
 * 2.�˼��ж������еĺ�����
 *  public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)//���������ж�����˼
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
	��д���ƺ��Ͳ�̫�У�ÿ�ζ�Ҫ�ж�i==d.size()��������ʱ�䡣
 * */

//12-23
/*
 * 1.bool subStr(string d,string s){
        int i=0,j=0;//���j����ȫ���������ﶨ�尡��
        for(i=0,j=0;i<d.size()&&j<s.size();j++){//i���س����ڳ�ʼ���
            if(d[i]==s[j])
                i++;
        }
        return i==d.size();
    }
    ���츴ϰ��д���ж������к������ƺ�����̫ɵ�ˡ�
   2.ʱ�临�Ӷ���Ҳ����ˣ���Ϊ��������Ƚϵĸ��ӶȾ��������ַ�����ƽ������x�ɡ�
     O(nx)��n��d���ַ����ĸ�������һ��ʼ����ж������еĸ��Ӷȸ�����ˣ�����Ϊ��m*n*c�ء���
 * */

//1-16
/*
 * 1.�������ȽϺ����������ˣ�֪����˫ָ��ֱ�ָ�򣬵���forѭ�����˳��������������ˣ�����������ͬʱ������
 *   Ȼ���˳��������Ƚ��ٶȸ��졣
 * */
int main(){

    return 0;
}
