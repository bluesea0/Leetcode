#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-16 ��ָoffer��15��
class Solution {
public:
    //ѭ���ж�ʱ�临�Ӷ�ΪO(logn)
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            if(n%2==1)
                ans++;//���Ի�Ϊans+=(n&1)//��ʾ����ĩλ�Ƿ���1.
            n/=2;//n&=(n-1)
        }
        return ans;
    }
};
/*
1.���Ͼ�AC�˰����ѵ�����ʲô�����𣿻�����n=n>>1.
2.�ܵ���˵ûʲô�Ѷȣ���ֵ����ϰ�����Ըո�˵�Ļ�̫�Դ��ˣ�����һ�½ⷨ��ȷʵ��֪ʶ�㡣
3.n&=n-1��������ǴӶ����Ƶ��ӽ��������ˣ���ר�Ŵ�������Ƶ����⡣
*/
//10-19
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){//���������ˡ�
            ans++;
            n&=n-1;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.hammingWeight(11);
    return 0;
}
