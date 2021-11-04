#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��11������7:07:04
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        //dfs�ķ���
        string str;
        helper(s,str,0);
        return ans;
    }
    void helper(string& s,string& path,int index){
        if(index==(int)s.size()){
            if(path.size()==s.size())
                ans.push_back(path);
            return;
        }
        for(int i=index;i<(int)s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                path.push_back(s[i]);
                helper(s,path,i+1);
                path.pop_back();
            }else{
                char c=s[i];
                path.push_back(tolower(c));
                helper(s,path,i+1);
                path.pop_back();
                path.push_back(toupper(c));
                helper(s,path,i+1);
                path.pop_back();
            }
        }
    }
};
/*
 * 1.AC�ˣ������Ҹо���д����ô��ô����������ʱ����������⣿
 * 2.���ģ������ڶ��ˣ���ȫ����ʲôforѭ���İ���ÿ�ε���һ��dfs�ͻ�ȥ����һλ��̫���ˣ�������forȥ����
 *   ÿһλ��for��������ʲô�أ��ǵ����е��У���forѭ����û��forѭ����ʲô�����أ��еĻ������ɸ��ֳ��ȵ�
 *   ����Ϊʲô�أ�һ��Ҫ�����for������ʲô���ã���Ȼ�´ο϶��ֲ��壬֮ǰȫ������Ҫ��ѭ��ÿһλ��
 *
 * */
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        //dfs�ķ���
        helper(s,0);
        return ans;
    }
    void helper(string& s,int i){
        if(i==(int)s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>'9'){
            s[i]=tolower(s[i]);
            helper(s,i+1);

            s[i]=toupper(s[i]);
            helper(s,i+1);
        }else helper(s,i+1);
        // for(int i=index;i<(int)s.size();i++){
        //     if(s[i]>'9'){//��Ϊ�����2������ĸ������û�н��뺯�����֡�
        //         s[i]=tolower(s[i]);
        //         helper(s,i+1);

        //         s[i]=toupper(s[i]);
        //         helper(s,i+1);
        //     }else helper(s,i+1);
        // }
    }
};
/*
 *dfs(a1b2,0):dfs(a1b2,1):dfs(a1b2,2):dfs(a1b2,3)
 *                        dfs(a1B2,3):dfs(a1B2,3)
 *            dfs(a1b2,2):dfs(a1b2,3)
 *            dfs(a1B2,2):
 *ͨ������ķ������Կ����������ÿһλ������ô֮ǰ�ڵݹ�ʱ�Ѿ�������ˣ��ϲ�ѭ���ٱ�������λ��ʱ����Ȼ
 *�����ٴ���һ�飬����˵i=1ʱ����ݹ�i=2�������ˣ���ô���غ�i=2���ᱻ�������Գ����ظ���
 *2.���������ȫ�������⣬ȫ������Ҫ��ĸλ�÷����仯�����ﲢ����Ҫ��ֻ�Ǵ�Сд��ĸת��һ�£���ÿλ��
 * ��һ������������ȫ����Ŷ��
 * */
int main(){

    return 0;
}
