#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��10������3:41:19
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res=0;
        if(flowerbed.size()==1&&flowerbed[0]==0)return n<=1;//[0] 1
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                int j=i;
                while(i+1<flowerbed.size()&&flowerbed[i+1]==0)i++;
                if((j==0||i+1==flowerbed.size())&&j!=i)//��Ҫ����߽�����
                    res+=1;
                res+=(i-j)/2;
            }
        }
        return res>=n?true:false;
    }
};//[0,0,1,0,1] 1 ����������������ô�����أ�
//�һ�����ļ��˵㡣����
//�ǿ�ͷ�ͽ�β��������
//���ģ����ˣ�����[0] 1�����ģ����˾��˰���Ӧ�����ܲ���һ���ģ�����ô�������һ�Ҫ�ٶ���ж���
//[1,0,0,0,0] 2���ˣ��ҷ����ˣ�Ӧ���������ַ������԰�
//���˾��ˣ��Ҷ������������1 0 0 0 1����������1���ǲ�һ���ģ��Ҵ����˰������ѵġ�
/*
 * 1.���ģ���AC�ˣ���̫�����˰ɣ�
 * 2.���������߽������öడ������˵0�����ҿ�ʼ������ڽӹ�2��0����ô��ʵҲ����+1�ģ�������[0] 1������Ҳ��
 *   ��ҪԤ����ġ�
 * 3.���˹ٽ��֪����ԭ����Ԫ�������ÿ��һ�⣬������û����ϸ���ٽ⣬�´θ�ϰ���ɡ�
 * */
int main(){
	Solution s;
	vector<int> flowerbed={0,0,1,0,1};
	cout<<s.canPlaceFlowers(flowerbed, 1);
    return 0;
}
