#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月27日下午3:56:09
/*
 * 1.我看到这个题的感觉就是，先递归找出来所以到叶结点的路径，然后再用前缀和+哈希来求解。
 * 2.太虐了，虐死我了，我这个废物啊，明天继续看，或者今晚回去继续看，我就不信了。
 * */
//class Solution {
//public:
//    int ans=0,sum;
//    int pathSum(TreeNode* root, int sum) {
//        if(!root) return 0;
//        this->sum=sum;
//        vector<int> path;
//        dfs(root,path);
//        return ans;
//    }
//    void dfs(TreeNode* root,vector<int> path){//但是我真的有时候对传引用还是值传存在疑问。
//        path.push_back(root->val);//我觉得传递的不是引用，就不用pop了吧。
//        if(!root->left && !root->right){
//            ans+=helper(path);//都执行不到这一步啊，这是为什么？
//            //我的天，这样的话，给的样例，就会重复算啊。。。我彻底不会了。
//        }else{
//            if(root->left) dfs(root->left,path);//发现了华点，这里如果不为空啊结界
//            if(root->right) dfs(root->right,path);
//        }
//        path.pop_back();
//    }//为什么要这么对我，为什么为什么为什么呢。。。
//    int helper(vector<int>& path){
//        unordered_map<int,int> mp;
//        int ret=0,s=0;
//        for(auto p:path){
//            s+=p;
//            if(mp.count(s-sum)!=0)ret+=mp[s-sum];
//            mp[s]+=1;
//        }
//        cout<<ret<<endl;
//        return ret;
//    }
//};

//10-29
/*
 * 1.上面时没有AC的代码，但是也是我思路的结晶啊！一开始的想法就是找出每条到叶结点的路径，然后对路径
 *   单独分析，前缀和+哈希，但是这样会重复计算路径的！样例中给的5 3就重复了。
 * 2.前天写的时候一直进入不了helper函数，今天才发现，是因为if(!root->left)??我是傻逼，这样的话
 *   空才为真啊，，才会进去判断下面啊。。。。
 * 3.看了grand的解法，https://www.cnblogs.com/grandyang/p/6007336.html，真是绝，学到了，原来是这么写啊
 *   看了第二种解法，我就说嘛！肯定能用到前缀和+哈西的啊。
 *   第三种解法也是蛮绝的。
 * 4.时空复杂度，感觉都是O(n)。
 * */
int main(){
	unordered_map<int,int> mp;
	int res=mp[1];//这样子还是没加上，我还以为能加上呢。。。
	cout<<res<<" "<<mp[1];
    return 0;
}
