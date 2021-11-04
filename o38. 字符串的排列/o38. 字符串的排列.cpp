#include <iostream>
#include<vector>
#include<queue>
#include<cstring>//����Ҳ����strlen��
#include <map>
#include<unordered_set>
using namespace std;
//10-10
/*
1.�Ҽǵ���������ֽⷨ��һ����DFS����һ���ǽ��������Ҿ��ý��������ܸ��ã��ҽ���дһ�½�������
2.���սⷨ��ͨ��map��ʵ�ֵģ���ô������һ��ͨ��set�أ����鷳��֮����˵�ɣ��л�����дһ��
 ͨ��DFS��set��
*/
class Solution {
private:
    void permu(int index,vector<string>& ans,string &s){//����Ķ�������Ʋ�̫��⡣
        if(index==s.size()){
            //�ѵ���Ҫ�����м�����ٷŽ�ȥ��
            ans.push_back(s);//��������һ������char�������ת��Ϊstring�أ�
            return;
        }
        map<char,int> mp;//�����������ڵ�ǰ����
        for(int i=index;i<s.size();i++){
            //C++��string����ͨ���±������Ӧ��Ҫת��Ϊchar����
//            if(i!=index && s[i]==s[index]) continue;
            if(mp.count(s[i])) continue;
            else mp.insert(pair<char,int>(s[i],1));
            char t=s[i];//C++���ѵ���û�и���Ľ���ֵ�ķ�������
            s[i]=s[index];
            s[index]=t;//һ��Ҫע��������index+1��������
            permu(index+1,ans,s);
            //�ٽ��������������������鷳����
            t=s[i];
            s[i]=s[index];
            s[index]=t;
        }

    }

public:
    vector<string> permutation(string s) {
        vector<string> ans;
        permu(0,ans,s);//����char*
        return ans;
    }
};
/*û��AC.
����ͨ���ҵ�if�ж���������
abc
acb
bac
cba
˵��������û��ȥ�ص�Ч��������Ϊʲô�أ��ҿ����˼ҵĴ����Ȼ�뵽�˼����ض�����dict�ģ��������
������

�ݹ���ò�Σ�
����ڲ�ʹ��permu(i+1,ans,s)�ĵ��ù��̣�
(0,[],abc):
index=0,i=0,abc://a��a�Լ�����
    (1,[],abc):
    index=1,i=1,abc://b��b�Լ�����
        (2,[],abc):index=2,i=2,abc://c��c�Լ�����
            (3,[abc],abc)
            ���� //�ٴε��ú�����ͨ���ݹ���������
        ����////forѭ������return
    index=1,i=2,acb://b��c����         ע��������ʵ���Ͼͳ����˲��������Ӧ�õ���(2,[abc],acb)����֮����b��bλ�ý��������û������ͬ
        (3,[abc],acb)
        ���� //���ú�����ͨ���ݹ���������
    ��������abc
    ����//forѭ������return
index=0,i=1,bac://����a��b
    (1,[abc,acb],bac):
    index=1,i=1,bac://����a��a
        (2,[abc,acb,bac],bac)//
		index=2,i=2,bac://����c��c
			(3,[abc,acb,bac],bac)
			����  ////���ú�����ͨ���ݹ���������
		���� //forѭ������return
	��������bac
	index=1,i=2,bac://����a��c
		(3,[abc,acb,bac],bca):
		����  ////���ú�����ͨ���ݹ���������
	��������bca
	���� //forѭ������return  ���˽���а�����[abc,acb,bac,bca]
index=0��i=2��bca��//����b��a
///���������ҷ����������ˣ����˾��ˣ��ұ����ˣ������ڵ�cpu崻��ˣ������ͼ�ס�ڲ����õ�ʱ����index+1������
 * i+1�ͺ��ˣ�ʵ���������������̫���ˣ��ҷ����ˡ�
 * Ϊʲôѡ��index+1�ݹ飬������ô��⣬��Ϊ��ѡ��index�����������һ������index�����˽�������˼��
 * Ŀǰֻ������index����ô����ĺ����ô���index+1�����ˡ�
*/
/*
1.�����ύ��֮���python������ͬ���������ϣ�"kzfxxx"����Ϊ����ظ���̫���޷������˰ɡ�
���Ի������ֵ�ȽϺ��ʡ�
*/

//10-26���츴ϰ��дһ�°ɡ�
class Solution2 {
public:
	vector<string> ans;
    vector<string> permutation(string s) {
    	//��Ȼ����һƬ�հס�����
    	per(0,s);
    	return ans;
    }
    void per(int index,string s){
    	if(index==s.size()){//��д��ʱ������ô���£����Ӳ������𣬱��뱨�˺ö����
    		ans.push_back(s);
    		return;
    	}
    	unordered_set<char> st;
    	for(int i=index;i<s.size();i++){
    		if(st.count(s[i])!=0)continue;
    		st.insert(s[i]);

    		swap(s[i],s[index]);
    		per(index+1,s);
    		swap(s[i],s[index]);
    	}
    }
};
/*
 * 1.Yes!AC�ˣ�Ӧ�û����������������ɣ�
 * 2.https://blog.csdn.net/qq_15711195/article/details/96746659
 *   ������������и������Ľ�𣬿���ȥ���õ���vector����ʱ��ѯ�жϡ�ʹ��set�洢�𰸡�
 * */

//5-23
/*
 * 1.�����ҹ۲��������Ľⷨ�������֣�
 *  ��ʹ��set����¼�ظ������ҵݹ����swap��ȥ�Ĳ��裻
 *  ��ֱ��ʹ��if(start!=i&&s[i]==s[start])continue;�������ж��Ƿ��ظ�������û��swap�Ĺ��̡�
 *  �����ַ�������ȫ����AC����һ�ַ����������ϣ��ڶ��ַ����������£�
 * */
class Solution {
public:
    vector<string> ans;
    vector<string> permutation(string s) {
        //���Ӷ���ô�����أ�
        sort(s.begin(),s.end());
        helper(s,0);
        return ans;
    }
    void helper(string s,int start){
        if(start==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(start!=i&&s[i]==s[start])continue;//�ų��ظ�����ĸ
            swap(s[i],s[start]);
            helper(s,start+1);
            //swap(s[i],s[start]);
        }
    }
};
/*
 * 3.�����ҵ�����ǣ���һ���ǱȽϺ�۵Ĺ��̣��������¼�Ƿ��ظ���������������ȫ���еĹ��̣���swapҲ��swap��ȥ
 *   ��������û���ظ�������£����Բο�lc46�⡣
 *  Ȼ�������������ظ���������ڽ����Ĺ��������жϵĻ����Ͳ���swap��ȥ�ˣ������ô˵�Ҳ��ý��ͣ������ס
 *  �����ظ�Ԫ��ʱ�����־ͺ��ˣ�Ҫô��set+������Ҫô�ж�+��swap����+������ֵ����Ȼͨ���жϵĻ�����Ҫsort��
 *  ���Ծͻ���ֱ����set���ˣ������Ǿֲ�set������ȫ��set��
 * 4.��������ĸ��Ӷȵļ��㣺O(N*N!)N�Ľ׳˼���ġ�����N�����γɸ��������ʱ�䣬N�Ǹ��Ƶ�ans�е�ʱ�䡣
 * */

//6-11
/*
 * 1.�����ҽ��������ܽ��ˣ�����ȫ�������⣬���û���ظ����֣���ôdfs��swap��������˵��ûʲô�ѵ㣬
 *   ������Դ����ظ����ֵģ������dfs���ø�vis������ȥ�أ�swap���Ƿ��index�����ȥ�أ����Ҳ���
 *   ��������������ȥ��ʧЧ����ȻҲ������set��ֻ����Ч�ʲ��ߡ�
 * */
class Solution {
public:
    vector<int> vis;
    vector<string> ans;
    vector<string> permutation(string s) {
        //дһ��dfs�汾
        vis.resize(s.size(),0);
        sort(s.begin(),s.end());
        string str;
        dfs(s,str);
        return ans;
    }
    void dfs(string& s,string& path){
        if(path.size()==s.size()){
            ans.emplace_back(path);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(vis[i]||(i>0&&s[i]==s[i-1]&&vis[i-1]==0))continue;
            path.push_back(s[i]);
            vis[i]=1;
            dfs(s,path);
            path.pop_back();
            vis[i]=0;
        }
    }
};
/*
 * 1.ȫ���о��ȿ���dfs��ok��
 * */
int main(){
    Solution2 s;
    string ss="abc";
//    cout<<s.permutation(ss);//������������ֱ�������
    vector<string> re=s.permutation(ss);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<endl;
    }
    return 0;
}
