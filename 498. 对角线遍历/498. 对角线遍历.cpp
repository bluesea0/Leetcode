#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��11��3������11:55:50
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool flag=true;
        int x=0,y=0,m=mat.size(),n=mat[0].size();
        //if(m==1)return mat[0];
        vector<int> ans;
        while(x<m&&y<n){
            ans.push_back(mat[x][y]);
            cout<<x<<" "<<y<<"\n";
            if((x==0&&flag)||(y==n-1&&flag)){//����ǵ�0�У��������ϣ���ô��Ҫת��
                flag=!flag;//��ʾ�����½��ƶ�
                if(x==0&&y!=n-1)y++;//һ��ʼ�ύ�����⣬����Ϊ��y!=m-1�ˡ�
                else x++;
            }else if((y==0&&!flag)||(x==m-1&&!flag)){//����ڵ�0���������£���ô��Ҫת��
                flag=!flag;
                if(y==0&&x!=m-1)x++;
                else y++;
            }else if(flag){//�����Ͻ�
                x--;y++;
            }else {
                x++;y--;
            }

        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<vector<int>> v={{2,3}};
	cout<<s.findDiagonalOrder(v).size();
    return 0;
}
