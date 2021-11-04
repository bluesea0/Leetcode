#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年11月3日下午11:55:50
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
            if((x==0&&flag)||(y==n-1&&flag)){//如果是第0行，且向右上，那么需要转向
                flag=!flag;//表示向左下角移动
                if(x==0&&y!=n-1)y++;//一开始提交有问题，是因为把y!=m-1了。
                else x++;
            }else if((y==0&&!flag)||(x==m-1&&!flag)){//如果在第0列且向左下，那么需要转向
                flag=!flag;
                if(y==0&&x!=m-1)x++;
                else y++;
            }else if(flag){//向右上角
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
