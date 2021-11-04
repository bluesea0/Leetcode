#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月6日下午3:26:13
class Solution {
public:
    //vector<int> fa(26,0);//报错：Char 20: error: expected parameter declarator
    //编译器无法区分该语句是成员变量声明还是成员函数声明
    vector<int> fa;
    bool equationsPossible(vector<string>& equations) {
        //尝试来手写一下
        //初始化
        fa.resize(26);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(auto e:equations)
            if(e[1]=='=')//以它构造并查集
                merge(e[0]-'a',e[3]-'a');

        for(auto e:equations){
            if(e[1]=='!'){
                if(find(e[0]-'a')==find(e[3]-'a'))
                    return false;
            }
        }
        return true;
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);
    }
};
/*
 * 1.Yes AC了！！注意到这里定义初始化成员变量的部分遇到的错误，还真是头一次遇到啊。
 *   天哪，这个时间复杂度的分析：O(n+ClogC)，n是方程数目，C 是变量的总数，在本题中变量都是小写字母，
 *   即 C≤26。上面的并查集代码中使用了路径压缩优化，
 *   对于每个方程的合并和查找的均摊时间复杂度都是 O(logC)。
 *   由于需要遍历每个方程，因此总时间复杂度是 O(n+ClogC)。
	其实我不太理解为什么，时间复杂度是相加呢？ 看官方讲解视频里说，并查集空间复杂度分析不是面试点，那我就
	不就结了。
	空间是O(C)
 * */
int main(){

    return 0;
}
