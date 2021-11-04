#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//2020年11月5日上午11:56:06
//class Solution {
//public:
//    unordered_set<string> st;
//    int ans=INT_MAX;
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//        //思路：顺序替换，保存开始词的每个位置，顺序替换为endword对应的char，判断是否在list中
//        //还需要记录开始词对应的单词是否被替换，
//        for(auto w:wordList)
//            st.insert(w);
//        if(st.count(endWord)==0)return 0;
//        //下面的遍历就保证
//        vector<int> visit(beginWord.size(),0);
//        dfs(beginWord,endWord,visit,0,0);
//        if(ans==INT_MAX)ans=0;
//        return ans;
//    }
//    void dfs(string beginWord, string endWord, vector<int> &visit,int index,int ct){
//        //但也有可能转换到一半转换不过去了。
//        //我感觉我已经控制不住这个函数了。
//        if(beginWord==endWord){
//            ans=min(ans,ct);
//            return;
//        }//我写的这个抢救不了了，因为它不一定是直接转换一样的，示例1中h先转换为了d，再转为c
//        //好难，我不会了。
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
//};//又生产了一堆垃圾，我好菜。
/*
 * 1.这个题目的tag是BFS？怎么个广度法？广度能解决的DFS也能啊。我再抢救一下。抢救不了，太难了。
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
        unordered_set<string> set;//这里来记录，因为如果出现过，那么说明就已经出现了之前的转换，
        set.insert(beginWord);
        //当前再出现，就肯定比原来的路径长。
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
                        if(k[i]!=t[i]&&st.count(k)!=0&&set.count(k)==0){//这里可能会出现重复的转换，
                        	//比如hot->dot->hot这样的。需要用set吗？
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
 * 1.Yes！上面的代码AC了！我还是有点希望的，时间：
 * 2.看了grand的解法感觉好厉害https://www.cnblogs.com/grandyang/p/4539768.html
 *   比我写的简洁多了。
 *   class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());//原来可以这么简洁地初始化
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};//原来可以这么简洁，直接初始化，不用之后单独再加一个push语句
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {//原来可以直接遍历。
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);//这里擦除掉，就直接堪比我的那个额外的set了！
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
3.关于时间复杂度的话，我怎么感觉是O(26*C*N)。
4.双向扩展的感觉自己不太会啊。
 * */

//11-18
/*
 * 1.双向广度搜索可以减小搜索空间，提高效率。
 * */
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //双向BFS，以为你知道endword是什么，所以可以用双向扩展
        unordered_set<string> words(wordList.begin(),wordList.end());
        unordered_set<string> flag({endWord});
        if(words.count(endWord)==0) return 0;
        unordered_set<string> us1({beginWord}),us2({endWord});
        // words.erase(endWord);//其实也不必，因为是set会自动去重
        int ans=1;//这里的1表示的是刚开始的字符
        while(!us1.empty()){
            if(us1.size()>us2.size()){//选择较小的集合进行BFS
                auto t=us1;
                us1=us2;
                us2=t;
            }
            //我知道了，为什么需要一个中间变量，因为你在遍历us1的过程中，下面就不能insert了
            //不然其实会改变最初的循环的，而且应该将原来的us1给覆盖掉，
            //us1中原来的都应该像队列一样
            unordered_set<string> us3;
            for(string word:us1){
                // if(us2.count(word))return ans;//如果出现了交集，说明可以转换
                //对word的每一位进行扩展
            	cout<<word<<" ";
                for(size_t i=0;i<word.size();i++){
                    char tc=word[i];
                    for(char c='a';c<='z';c++){
                    	if(c==tc)continue;
                        word[i]=c;
                        if(words.count(word)){//看来是必须要另外地记录了，不能仅仅用words，也更不能erase
                        	cout<<word<<" ";
                        	if(flag.count(word)){
                        		if(us2.count(word)) return ans+1;
                        	}
                        	else{
                        		us3.insert(word);
                        		flag.insert(word);
                        	}
//                             words.erase(word);//避免重复放入

                            //天哪这里不能erase，因为这样的话就不给下一次机会了！
                            //其实不必专门erase，因为都使用的set，都会去重的
                        }
                    }
                    word[i]=tc;
                }
            }
            us1=us3;
            cout<<endl;
            ans++;//这个到底放在哪里？
        }
        return 0;
    }
};
/*
 * 1.几经修补，终于AC了！参考了https://blog.csdn.net/ZouCharming/article/details/90757577，没有这个
 *   我也AC不了。
 * 2.关键点，在遍历us1的时候需要一个临时集合us3，因为遍历过程中会需要修改集合，像queue进入循环之前
 *   可以先获取它目前的长度，并弹出，那么针对集合就要中间变量了。
 *   words这个集合不能erase，但是仍然需要记录已经遍历过的字符，不然在无法转换时会导致死循环，
 *   这就要进行嵌套的判断了。
 * 3.还要注意while循环的条件。 752题也是BFS。
 * */

int main(){
	//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
	//上面是题目的假设，所以不用考虑二者相同的情况，没有那样的测试用例！
	Solution2 s;
	vector<string> v={"hot","dot","dog","lot","log","cog"};//如果只有cog的话就是0
	cout<<s.ladderLength("cog", "cog", v);//天啦这样子是3？算了这个python代码也是3，我不纠结了。
    return 0;
}
