#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
//2021��2��2������6:52:29
//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        //������ҽ�����˼������Ŀ��ǩ���л������ڣ����뵽��ģ��
//        //����right�����ƶ������=left�Ļ��ͼ����µĳ��ȣ�����k--��ʾ�л���
//        //left�ƶ���=֮ǰ�ַ���λ�ã�����ô�����أ��뵽�����Ҿ����ˣ�����Ĳ��ᣬ��ְ�ˡ�
//    }
//};
/*
 * 1.���ǲ����������ģ��������֮��ֱ��ţ�ƣ���¼�����ڵ��ַ����ִ�����ϣ��������ת��Ϊ�����ڳ��˳���
 *   ���������ַ����ֻ����k�������������ɵؽ���ˡ�̫ţ�ˣ�����ʲô��������������ֶ�������
 * 2.https://www.cnblogs.com/grandyang/p/5999050.html ����Ҳ�ܺá�
 * 3.�ȽϹؼ���һ����ΪʲômaxNֻ��¼��ʷ���ֵ����������leftָ���ƶ�ʱʵʱ���´����ڵ����ֵ��
 *   �ٷ������������˵�ıȽ����ף�
 *   ��Ϊ�������ʷ���ֵС����ôkҲ�ǹ̶��ģ�+k�ĳ��ȣ������ǰ���ֵ����ʷmaxNС����ô�õ����ַ�������
 *   �϶�������ģ��϶��Ȳ�����ʷ�������µĸ����maxN���ֵ�ʱʱ���˵�����µĴ��ˣ�
 * 4.grand�����У����û��k�����ƣ�����������ַ������ֻ��һ���ַ��ظ����ַ�����Ҫ����С�û�������
 *   ��ô�����ַ������ܳ��ȼ�ȥ���ִ��������ַ��ĸ������������k�����ƣ�
 *   ������ʵ���������� (���ַ����ĳ��ȼ�ȥ���ִ��������ַ�����)<=k ��������ַ������ȼ��ɡ�
 *   ���˼·Ҳ���������է�֣�
 * */

//2-3
class Solution {
public:
    int characterReplacement(string s, int k) {
        //Ҳ���ǵ�ǰ�����ڳ��˳��ִ��������ַ�֮�⣬�����ַ������������ܶ���k�����ֻ�ܵ���
        int left=0,right=0,maxn=0,ans=0;
        vector<int> ct(26,0);
        while(right<s.size()){
            int c=s[right]-'A';
            ct[c]++;
            maxn=max(maxn,ct[c]);
            if(right-left+1-maxn>k){
                ct[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);//�ڿ����ƶ�leftָ������ans��Ҳ����ÿ���ƶ�rightʱ����
            right++;
        }
        return ans;//ans��ô�����أ�
    }
};//�ַ�����һ��k=0��Ҳûʲô����
/*
 * 1.�����Ļ������ڼ�ֱ��Ҫ̫�Ѻ��𣡣��������ӡ�
 * */
int main(){
	Solution s;
	cout<<s.characterReplacement("ccaabbb", 1);
	//159�⣬��Ա��Ŀ
	//https://www.cnblogs.com/grandyang/p/5185561.html
//	string s="eceba";
//	unordered_set us;
//	int left=0,right=0,res=0;
//	while(right<s.size()){
//		if(us.count(s[right])){//�Ѿ������˸ýڵ�
//			right++;
//			res=max(res,right-left);
//		}else if(us.size()<=2){//������һ���µ��ַ�
//			us.insert(s[right]);
//			right++;
//			res=max(res,right-left);
//		}else {//�ƶ��󴰿�
//			//������ŷ��ֲ�����set���棬��Ϊ������ɾ����ʱ���ɾ���˵�һ�������Ǵ�������Ȼ������
//			//����˵���ǵ��ù�ϣ������¼����Ȼ��������з�0�ĸ���������Ϊ�ж��ٸ���ͬ����ĸ
//		}
//	}
	//�ŷ�Ӧ���������������424��k��Ϊ1�ֻ�ܰ������ֲ�ͬ���ַ���û��˵��ֻ�ܰ���2����
	//���ǲ��ǣ��������ˣ�����������񣬵�����ͬһ���⣡
    return 0;
}
