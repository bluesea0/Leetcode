#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��24������1:23:35
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //���Ǽ���б�ʲ���Ҫ���������������ô�죿
        for(int i=1;i<coordinates.size();i++){//����Ҫ��1��ʼ����Ϊ�����0��ʼ�Ļ���0�ͻᱻ����Ϊ[0,0]
        	//����ļ����û�������ˡ�
            coordinates[i][0]-=coordinates[0][0];
            coordinates[i][1]-=coordinates[0][1];
        }
        int A=coordinates[1][1],B=-coordinates[1][0];
        for(int i=2;i<coordinates.size();i++){
            if(A*coordinates[i][0]+B*coordinates[i][1]!=0)
                return false;
        }
        return true;
    }
};
/*
 * 1.�����ʵ��һ��ʼ������ģ����漰����ѧ��֪ʶ�����㷨��ʾ��һ��ʼ��ͬ�ļ���k�����������漰��������������
 *   ������ͱȽ��ѡ�
 * */
int main(){
	Solution s;
	vector<int>
	cout<<s.checkStraightLine(coordinates);
    return 0;
}
