#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��1������9:03:29
//�����һ�����ǵ�Ȼ�ǲ����ˣ�û����ȥ����
//���˹ٷ���������˼·��ֻ��Ҫ���ǰk�������ֵ�Ƿ�Ϊk������Ǿ�+1�����з֡�
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,ma=0;
        for(size_t i=0;i<arr.size();i++){
            ma=max(ma,arr[i]);
            if(ma==i)ans++;
        }
        return ans;
    }
};
//AC�ˣ����ǲ�����ʡ�

//12-22
//���츴ϰ��һ�£���Ȼ�Ѿ������ˡ�����
int main(){

    return 0;
}
