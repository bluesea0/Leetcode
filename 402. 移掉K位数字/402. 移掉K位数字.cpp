#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��15������4:46:44
//class Solution {
//public:
//    string removeKdigits(string num, int k) {
//        //������о���Ĳ��ᣬ���е�˼·����ȥ��ÿһλ���ԣ�
//        //�Ӹ�λ��ʼȥ������������1����û�н���˵��ȥ�����λ��1���Ǿͱ���ö����
//        //���ǳ�����10002����̫���˰����Ҳ��ᣬͷ�񡣡�����Ҫ������
//    }
//};
/*
 * 1.����˼·����Ǿ��ˣ���ѧԭ���ǣ��������ֵĴ�С��ȡ���ڲ�ͬ�����λ���ִ�С��
 * 2.����Ŀ��316���ơ�
 * */

//11-22
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==0)return num;
        vector<char> v;
        //�Ǿʹ����翪ʼ�ƶ�
        for(size_t i=0;i<num.size();i++){
            // if(k==0)break;
            while(v.size()&&num[i]<v.back()&&k){
                v.pop_back();
                k--;
            }
            v.push_back(num[i]);
            cout<<num[i]<<" ";
        }
        for(;k>0;k--)//���k��Ϊ0����ô˵��ջ���ǵ����ģ���ɾ������ľͺ�
            v.pop_back();
        cout<<endl;
        string ret="";
        for(size_t i=k;i<v.size();i++){//����֮����ѡ���k����������Ϊ��"9" 1����������
//            if(v[i]=='0')continue;//����д��Ҳ���԰���Ӧ���Ǻ�������λ0�����������е�0��
        	//���ģ���ô������λ0��
        	if(v[i]=='0'&&ret.size()==0)continue;
            ret+=v[i];
            cout<<v[i]<<" ";
        }
        return ret==""?"0":ret;
    }
};
/*
 * 1.����"10" 2��������������Ҫ����0����������return��ʱ�������ж�
 *  ���ύһ�Σ���"9" 1�������������ҿ��ˣ���������Թ��˰��͡�
 *  ������"112" 1�������ҷ�����д���߼��Ǵ���ģ��ҿ��ˡ���ô��ô��˳�ء�
 *  ��֪����Ӧ�ð�while�е�=��ȥ������һ��ʼ��Ϊ1432219��ȥ��=Ҳû�ã��ҵ��߼����ǻ��ҵġ�����
 *  �ҷ�����
 * 2.�ύ���������������⣺
 *   vector����pop_back����pop��������ʼ��Ӧ����{}��Ҳ���ǽ���ѧ����uninitialized_list��ʼ���б�
 *   ������()�������ͳ������벻���Ĵ��󰡡�
 * */

//11-23
//�������ˣ����˽ⷨ�������������ˣ����k��Ϊ0����ôջ�е����ǵ��������ģ�ֱ�ӽ��󼸸����ų��Ϳ����ˣ�
//�Դ���ѧϰ����ջ��֪ʶ��
//https://www.cnblogs.com/grandyang/p/5883736.html

//11-24
//����AC�ˣ������װ���

//12-20
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for(auto c:num){
            if(stk.size()==0)
                stk.push_back(c);
            else{
                while(stk.size()!=0&&k>0&&stk.back()>c){stk.pop_back();k--;}
                //������жϲ�����=�Ű�����"112" 1������
                stk.push_back(c);
            }
        }
        while(k--)stk.pop_back();
        string ans="";
        for(auto c:stk){
            if(ans.size()==0&&c=='0')continue;//ȥ������λ0
            ans+=c;//����ɵ�ƣ���д����stk+char��������
        }
        return ans.size()==0?"0":ans;//������������"10" 2������
    }
};

//2021-8-31
class Solution {
public:
    string removeKdigits(string num, int k) {
        //����ջ�����ϸ�������ҵ��죬��һֱ������ˣ�������ʱ����
        stack<char> stk;
        for(int i=0;i<num.size();i++){
            while(k&&!stk.empty()&&num[i]<stk.top()){//��ʾɾ��
                k--;
                stk.pop();
            }
            stk.push(num[i]);
        }//�������ջ��ô�γ��Ҷ������˰�����ô���¡�
        while(k--&&!stk.empty())stk.pop();
        if(stk.empty()) return "0";
        string ans="";
        while(!stk.empty()){
            ans=stk.top()+ans;
            stk.pop();
        }
        //�����Ļ���ôɾ��ǰ��0�أ�
        int j=0;
        while(ans[j]=='0')j++;
        return j==ans.size()?"0":ans.substr(j);
    }
};

int main(){
	Solution s;
	cout<<s.removeKdigits("112", 1);
    return 0;
}
