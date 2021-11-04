#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��19������3:20:05
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //˼·����ת�ã����ÿ��reverse
        for(int i=0;i<matrix.size();i++)
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());//���ģ��һ�����û����cpp���ù���ת����
    }
};//ʱ�临�Ӷ�:O(n^2)

//7-12
//ԭ�ظ����±귴ת
/*
 * 1.��Ҫ�������ѵ㣬һ��ԭ�ط�ת��������ת��ʽ��һ����Ҫö�ٵķ�Χ��
 * 2.���֮�¾��õڶ�������ѡ�
 * ���ȸ��ݹ�ʽmatrix[j][n-i-1]=matrix[i][j]���Ƶ����ĸ�λ�ñ任�Ĺ�ʽ
 * matrix[][]=matrix[j][n-i-1]�����һʽ�õ����շŵ�λ����matrix[n-i-1][n-j-1]
 * matrix[][]=matrix[n-i-1][n-j-1]�����һʽmatrix[n-j-1][i]
 * matrix[][]=matrix[n-j-1][i]�����һʽmatrix[i][j]
 * �����ٵ���ֵ��ʹ��temp�洢�ʼ��matrix[i][j]
 * ���յĹ�ʽ��
 *   matrix[j][n-i-1]=matrix[i][j]
 *   matrix[n-i-1][n-j-1]=matrix[j][n-i-1]
 *   matrix[n-j-1][i]=matrix[n-i-1][n-j-1]
 *   matrix[i][j]=matrix[n-j-1][i]
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){//�Ҳ��������ΪʲôҪ��������ѵ�˵��ֻ��ת���1/4��λ�þ��У�
                int temp=matrix[i][j];//��Ϊÿ�β���4������
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};
/*
 * 1.��ʽ���ܻ��Ƶ����������ö�ٵ�λ��ʵ����̫���ˣ��Ҳ���⣬���������ֻ�����������ˡ�
 *   �϶�����ʱ�벻�������ؼ��ĵ����ֻ�������Ͻǵ�1/4���У�j��i��ʼ��j���������ơ�
 * */
int main(){

    return 0;
}
