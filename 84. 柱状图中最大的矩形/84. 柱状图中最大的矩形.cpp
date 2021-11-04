#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��5������11:42:27
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //ö�ٸߣ��ҳ������ҵ������С�����ĸ߶�
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int left=i,right=i;
            while(left>0&&heights[left-1]>=heights[i])left--;
            while(right+1<heights.size()&&heights[right+1]>=heights[i])right++;
            ans=max(ans,heights[i]*(right-left+1));
        }
        return ans;
    }
};
/*
 * 1.���ö�ٸߵĽⷨ��ʱ�ˣ�87/96��O(n^2)�Ľⷨͨ������
 * 2.��Ҫ��˼������ҵ��������ұ߽磡�ҵ�����С�����ĸ߶ȣ�����ȷ������ˣ���Ϊ�߶ȶ��ˣ�����������
 * 3.
 * */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0,m=heights.size();
        vector<int> left(m,0),right(m,0);
        vector<int> stack;
        for(int i=0;i<m;i++){//��Ȼ�뵽��һ���ؼ������⣿�����=�أ�
        //=�϶�����
            while(!stack.empty()&&heights[stack.back()]>=heights[i])stack.pop_back();
            if(stack.empty()) left[i]=-1;
            else left[i]=stack.back();
            stack.push_back(i);
        }
        //��ô���°�stack��Ϊ�գ�����˵�¶���һ����
        stack.resize(0);
        for(int i=m-1;i>=0;i--){
            while(!stack.empty()&&heights[stack.back()]>=heights[i])stack.pop_back();
            if(stack.empty())right[i]=m;//��ʾһֱ��ĩβ��û���ҵ�����С��
            else right[i]=stack.back();
            stack.push_back(i);
        }
        for(int i=0;i<m;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};
int main(){

    return 0;
}
