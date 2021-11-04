#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��8��28������8:02:44
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //����ջ���ݼ������ϸ�
        stack<int> stk;//�洢index
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                ans[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
/*
 * 1.��̫ţ�˰ɣ�һ�����������š���ӵ�����ջר���С�
 * */
int main(){

    return 0;
}
