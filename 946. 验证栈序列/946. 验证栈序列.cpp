#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//10-17
/*
1.��ʵ�о���������Ѿ�����Ϥ�ˣ����ǿ���һ��֮ǰ���ύ��¼���ųɹ���һ�Σ���ô�һ���Ҫ��C++��
  дһ��ġ�
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
2.oh yes!!ͨ���ˣ�����
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
};//ͦeasy��
//������Ҫע�������ǰ�Ҷ�����vector������stack�����Բ���ʱpush_back��back()�����������������
//stack�����Բ�����push��top����Ҫע����ô���
int main(){
    Solution s;
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={4,3,5,1,2};
    cout<<s.validateStackSequences(v1,v2);
    return 0;
}
