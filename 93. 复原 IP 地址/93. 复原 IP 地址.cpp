#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��10������3:04:27
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        //����
        if(s.empty()||s.size()<4)return{};
        vector<string> path;
        helper(s,0,path);
        return ans;
    }
    void helper(string& s,int index,vector<string>& path){
        if(s.size()==index){
            if(path.size()==4){
                string t=path[0];
                for(int i=1;i<path.size();i++){
                    t.push_back('.');//׷�ӵ����ַ�
                    t.append(path[i]);//׷���ַ���
                }
                ans.push_back(t);
            }
            return;
        }
        if(path.size()>=4)return;//���û�б�����s�ͷ���4������ôreturn
        for(int i=0;i<3&&i+index<s.size();i++){//i��ʾ��index�����жϼ���������Ŀ
            if(s[index]=='0'&&i>0)break;//���ܰ���ǰ��0
            string t=s.substr(index,i+1);
            if(check(t)){//�����ǰ��������
                path.push_back(t);
                helper(s,index+i+1,path);
                path.pop_back();
            }
        }
    }
    bool check(string s){
        int n=0;
        for(int i=0;i<s.size();i++){
            n*=10;
            n+=(s[i]-'0');
        }
        if(n>=0&&n<=255)return true;//�ҵ��裬����Ӧ��ʱ&&����
        return false;
    }
};
/*
 * 1.��ʵҲ�����˵����⣬���ǻ��ݿ��Ƶ�ʱ��i������û�㶮����ʾ��index�����ȡ����������Ҫ�з�Χ����
 * */

//10-2
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4)return {};
        vector<string> path;
        restore(s,0,path);
        return ans;
    }
    void restore(string& s,int index,vector<string>& path){
        if(index==s.size()){
            if(path.size()==4){
                string temp=path[0];
                for(int i=1;i<path.size();i++){
                    temp+=".";
                    temp+=path[i];
                }
                ans.push_back(temp);
            }
            return;
        }
        if(path.size()>=4)return;
        for(int i=index;i-index<3&&i<s.size();i++){
            //iӦ�ó�ʼ��Ϊ0��������index������iָ����
        //��index����ƫ���Ƕ��١���ô����һ�������ʼ��Ϊindex
            if(i!=index&&s[index]=='0')break;//���ܰ���ǰ��0
            string temp=s.substr(index,i-index+1);
            if(helper(temp)){
                path.push_back(temp);
                restore(s,i+1,path);
                path.pop_back();
            }
        }
    }
    bool helper(string& s){
        int t=stoi(s);
        return t>=0&&t<=255;
    }
};
/*
 * 1.��Ϊ֮ǰֻд��һ�Σ��о��������������һ����д�������������д�ĺ�֮ǰ���˵����ƣ����ǹ������i
 *   ��index��ʼ���Ĺ�ϵ���ұ��ˣ����i��ʼ��Ϊindex����ô�ж������ǲ�ֵ������3�Ҳ�Խ�磬��Ҫ������ط���
 *   ��Ϊ���ж�ǰ���㣬��ֱ����i!=index�Ƚ�ϰ���ˡ�
 * */
int main(){
	Solution s;
	vector<string> ans=s.restoreIpAddresses("25525511135");
	cout<<"\n";
	for(auto& a:ans)
		cout<<a<<"\n";
    return 0;
}
