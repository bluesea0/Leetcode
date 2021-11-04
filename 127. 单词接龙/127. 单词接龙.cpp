#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//2020��11��5������11:56:06
//class Solution {
//public:
//    unordered_set<string> st;
//    int ans=INT_MAX;
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//        //˼·��˳���滻�����濪ʼ�ʵ�ÿ��λ�ã�˳���滻Ϊendword��Ӧ��char���ж��Ƿ���list��
//        //����Ҫ��¼��ʼ�ʶ�Ӧ�ĵ����Ƿ��滻��
//        for(auto w:wordList)
//            st.insert(w);
//        if(st.count(endWord)==0)return 0;
//        //����ı����ͱ�֤
//        vector<int> visit(beginWord.size(),0);
//        dfs(beginWord,endWord,visit,0,0);
//        if(ans==INT_MAX)ans=0;
//        return ans;
//    }
//    void dfs(string beginWord, string endWord, vector<int> &visit,int index,int ct){
//        //��Ҳ�п���ת����һ��ת������ȥ�ˡ�
//        //�Ҹо����Ѿ����Ʋ�ס��������ˡ�
//        if(beginWord==endWord){
//            ans=min(ans,ct);
//            return;
//        }//��д��������Ȳ����ˣ���Ϊ����һ����ֱ��ת��һ���ģ�ʾ��1��h��ת��Ϊ��d����תΪc
//        //���ѣ��Ҳ����ˡ�
//        for(int i=index;i<beginWord.size();i++){
//            if(beginWord[i]==endWord[i])visit[i]=1;
//            else if(visit[i]==0){
//                int t=beginWord[i];
//                beginWord[i]=endWord[i];
//                if(st.count(beginWord)!=0){
//                    visit[i]=1;
//                    dfs(beginWord,endWord,visit,ct+1);
//                    visit[i]=0;
//                }
//                beginWord[i]=t;
//            }
//        }
//    }
//};//��������һ���������Һòˡ�
/*
 * 1.�����Ŀ��tag��BFS����ô����ȷ�������ܽ����DFSҲ�ܰ�����������һ�¡����Ȳ��ˣ�̫���ˡ�
 * 2.
 * */

//11-15
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS
        unordered_set<string> st;
        for(auto w:wordList){
            st.insert(w);
        }
        if(st.count(endWord)==0) return 0;
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        unordered_set<string> set;//��������¼����Ϊ������ֹ�����ô˵�����Ѿ�������֮ǰ��ת����
        set.insert(beginWord);
        //��ǰ�ٳ��֣��Ϳ϶���ԭ����·������
        while(!q.empty()){
        	int len=q.size();
        	while(len--){
                string t=q.front();
                cout<<t<<" ";
                if(t==endWord)return ans;
                q.pop();
                for(size_t i=0;i<t.size();i++){
                    string k=t;
                    for(int j=0;j<=26;j++){
                        k[i]=j+'a';
                        if(k[i]!=t[i]&&st.count(k)!=0&&set.count(k)==0){//������ܻ�����ظ���ת����
                        	//����hot->dot->hot�����ġ���Ҫ��set��
                        	set.insert(k);
                            q.push(k);
                        }
                    }
                }
        	}
        ans++;
        cout<<ans<<endl;
        }
        return 0;
    }
};
/*
 * 1.Yes������Ĵ���AC�ˣ��һ����е�ϣ���ģ�ʱ�䣺
 * 2.����grand�Ľⷨ�о�������https://www.cnblogs.com/grandyang/p/4539768.html
 *   ����д�ļ����ˡ�
 *   class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());//ԭ��������ô���س�ʼ��
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};//ԭ��������ô��ֱ࣬�ӳ�ʼ��������֮�󵥶��ټ�һ��push���
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {//ԭ������ֱ�ӱ�����
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);//�������������ֱ�ӿ����ҵ��Ǹ������set�ˣ�
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
3.����ʱ�临�ӶȵĻ�������ô�о���O(26*C*N)��
4.˫����չ�ĸо��Լ���̫�ᰡ��
 * */

//11-18
/*
 * 1.˫�����������Լ�С�����ռ䣬���Ч�ʡ�
 * */
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //˫��BFS����Ϊ��֪��endword��ʲô�����Կ�����˫����չ
        unordered_set<string> words(wordList.begin(),wordList.end());
        unordered_set<string> flag({endWord});
        if(words.count(endWord)==0) return 0;
        unordered_set<string> us1({beginWord}),us2({endWord});
        // words.erase(endWord);//��ʵҲ���أ���Ϊ��set���Զ�ȥ��
        int ans=1;//�����1��ʾ���Ǹտ�ʼ���ַ�
        while(!us1.empty()){
            if(us1.size()>us2.size()){//ѡ���С�ļ��Ͻ���BFS
                auto t=us1;
                us1=us2;
                us2=t;
            }
            //��֪���ˣ�Ϊʲô��Ҫһ���м��������Ϊ���ڱ���us1�Ĺ����У�����Ͳ���insert��
            //��Ȼ��ʵ��ı������ѭ���ģ�����Ӧ�ý�ԭ����us1�����ǵ���
            //us1��ԭ���Ķ�Ӧ�������һ��
            unordered_set<string> us3;
            for(string word:us1){
                // if(us2.count(word))return ans;//��������˽�����˵������ת��
                //��word��ÿһλ������չ
            	cout<<word<<" ";
                for(size_t i=0;i<word.size();i++){
                    char tc=word[i];
                    for(char c='a';c<='z';c++){
                    	if(c==tc)continue;
                        word[i]=c;
                        if(words.count(word)){//�����Ǳ���Ҫ����ؼ�¼�ˣ����ܽ�����words��Ҳ������erase
                        	cout<<word<<" ";
                        	if(flag.count(word)){
                        		if(us2.count(word)) return ans+1;
                        	}
                        	else{
                        		us3.insert(word);
                        		flag.insert(word);
                        	}
//                             words.erase(word);//�����ظ�����

                            //�������ﲻ��erase����Ϊ�����Ļ��Ͳ�����һ�λ����ˣ�
                            //��ʵ����ר��erase����Ϊ��ʹ�õ�set������ȥ�ص�
                        }
                    }
                    word[i]=tc;
                }
            }
            us1=us3;
            cout<<endl;
            ans++;//������׷������
        }
        return 0;
    }
};
/*
 * 1.�����޲�������AC�ˣ��ο���https://blog.csdn.net/ZouCharming/article/details/90757577��û�����
 *   ��ҲAC���ˡ�
 * 2.�ؼ��㣬�ڱ���us1��ʱ����Ҫһ����ʱ����us3����Ϊ���������л���Ҫ�޸ļ��ϣ���queue����ѭ��֮ǰ
 *   �����Ȼ�ȡ��Ŀǰ�ĳ��ȣ�����������ô��Լ��Ͼ�Ҫ�м�����ˡ�
 *   words������ϲ���erase��������Ȼ��Ҫ��¼�Ѿ����������ַ�����Ȼ���޷�ת��ʱ�ᵼ����ѭ����
 *   ���Ҫ����Ƕ�׵��ж��ˡ�
 * 3.��Ҫע��whileѭ���������� 752��Ҳ��BFS��
 * */

int main(){
	//����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
	//��������Ŀ�ļ��裬���Բ��ÿ��Ƕ�����ͬ�������û�������Ĳ���������
	Solution2 s;
	vector<string> v={"hot","dot","dog","lot","log","cog"};//���ֻ��cog�Ļ�����0
	cout<<s.ladderLength("cog", "cog", v);//������������3���������python����Ҳ��3���Ҳ������ˡ�
    return 0;
}
