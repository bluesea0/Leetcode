#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��6������1:54:33
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //��ʵûʲô�㷨���⣬������ôд�أ�
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> t(i+1,0);
            t[0]=1;
            for(int i=1;i+1<t.size();i++){
                t[i]=ans.back()[i-1]+ans.back()[i];
            }
            t[i]=1;
            ans.push_back(t);
        }
        return ans;
    }
};
/*
 * 1.AC�ˡ����Ӷȣ�O(n^2)���ռ�Ϊ����1������Ҫ���Ƿ���ֵ�Ŀռ�ռ�á�
 * class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);//ֱ�����������ԣ�
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {//i=0//i=1ʱ������������ѭ��
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
�ٷ�д�Ĳ����㡣
 * */

//12-22
/*
 * 1.��θ�ϰ�һ��ǻῼ�ǵ�numRows=1������������������д�Ļ����϶�����д������ô���ģ��һ���
 *   �ø�ϰ��
 * */
int main(){

    return 0;
}
