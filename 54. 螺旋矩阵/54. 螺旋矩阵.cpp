#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������3:42:52
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if(matrix.empty()) return {};
//        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
//        vector<int> ans;
//        while(top<=bottom&&left<=right){
//            for(int i=left;i<=right;i++)
//                ans.push_back(matrix[top][i]);
//            top++;
//            for(int i=top;i<=bottom;i++)
//                ans.push_back(matrix[i][right]);
//            right--;
//            for(int i=right;i>=left;i--)
//                ans.push_back(matrix[bottom][i]);
//            bottom--;
//            for(int i=bottom;i>=top;i--)
//                ans.push_back(matrix[i][left]);
//            left++;
//        }
//        return ans;
//    }
//};
/*
 * 1.�����������ͳ���������[[1,2,3,4],[5,6,7,8],[9,10,11,12]]����ӡ��[1,2,3,4,8,12,11,10,9,5,6,7,6]
 *   �����ӡ��һ��6������Ϊ������forѭ����left��right�ĵط����ظ���ӡ�ˣ��Ѿ��ڵ�һ��forѭ�������ӡ����
 *   ������ô����أ�����жϣ�����Ҫ�������ж��أ�
 * 2.�Һ�Ȼ���ˣ���õ��ж�������ʲô�أ����Ǹ��ݽڵ����������������������У�����forѭ�����ġ�
 * */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int> ans;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;
            for(int i=right;i>=left&&top<=bottom;i--)//����&������жϿ��Ա���
            //3��4�е��ظ���ӡ[1,2]λ�õ���
                ans.push_back(matrix[bottom][i]);
            bottom--;
            for(int i=bottom;i>=top&&left<=right;i--)//���������Ϊ��4��3�е����֣�
            //����������ʱ��top==bottom������left<right�ģ�left��right�Ѿ������ӡ���ˣ�
            //�����Ǹ���������Ѿ���ӡ���ˣ����Բ����ظ���ӡ�ġ�
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};
/*
 * 1.�����ǲ����������и����Ĵ��룬Ȼ���ҿ��ܶ���ⶼ�����������Ľⷨ��
 * */
//�����������Ƶ�
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return {};
        vector<int> res;
        int l = 0;                      //��߽�
        int r = matrix[0].size() - 1;   //�ұ߽�
        int t = 0;                      //�ϱ߽�
        int b = matrix.size() - 1;      //�±߽�
        while (true)//����ʹ������ѭ��
        {
            //left -> right
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if (++t > b) break;//��ʵһ����һ���ӻ������ˣ���ô�ͱ�ʾ�Ѿ���ӡ���ˡ�
            //top -> bottom
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if (--r < l) break;
            //right -> left
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if (--b < t) break;
            //bottom -> top
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};
int main(){

    return 0;
}
