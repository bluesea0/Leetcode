#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��7������11:05:52
//class Solution {
//public:
//    int matrixScore(vector<vector<int>>& A) {
//        //˼·��״̬+����������Ĳ��������ĳλ��ת�л�����
//        //״̬�أ��Ǳ���ÿ��λ�û���˵ֻ��Ը�λ��
//        //����Ǳ����Ļ����������Σ�ֹͣ��������ʲô����Ϊ��Ŀ˵��������ƶ���
//        //̫����̫���ˡ�״̬�������Ǽ�ά�ģ�̫���ˡ�
//    }
//};
//�������֮��ֱ��ţţţ��

//12-21
//�ٿ����ǲ��ᣬ������ο������֮�󣬳��������ˡ�

//12-22
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        int res=m*1<<(n-1);//��0������Ԫ�ض���1
        for(int j=1;j<n;j++){
            //�ӵ�1�п�ʼ��������1�ĸ������������0�ĸ�������ô�ͷ�ת
            int n1=0;
            for(int i=0;i<m;i++){
                if(A[i][0]==1)
                    n1+=A[i][j];
                else n1+=(1-A[i][j]);
            }
            int k=max(n1,m-n1);
            res+=k*(1<<(n-j-1));
        }
        return res;
    }
};//AC�ˡ�
int main(){

    return 0;
}
