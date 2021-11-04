#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//10-17
/*
1.其实感觉对这个题已经很熟悉了，但是看了一下之前的提交记录，才成功过一次？那么我还是要在C++上
  写一遍的。
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int k=0;
        for(auto p:pushed){
            st.push(p);
            while(!st.empty() && k<popped.size() && st.top()==popped[k]){
                    k++;
                    st.pop();
            }
        }
        return st.empty();
    }
};
/*
2.oh yes!!通过了！！！
*/

//5-22
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int k=0;
        for(int i=0;i<pushed.size();i++){
            stk.push(pushed[i]);
            while(!stk.empty()&&k<popped.size()&&stk.top()==popped[k]){
                stk.pop();
                k++;
            }
        }
        return stk.empty();
    }
};//挺easy的
//但是需要注意的是以前我都是用vector来代替stack，所以操作时push_back和back()，但是我最近又用了
//stack，所以操作是push和top，需要注意别用错！！
int main(){
    Solution s;
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={4,3,5,1,2};
    cout<<s.validateStackSequences(v1,v2);
    return 0;
}
