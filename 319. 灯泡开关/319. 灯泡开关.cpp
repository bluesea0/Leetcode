#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��19������2:30:13
class Solution {
public:
    int bulbSwitch(int n) {
        //�����Ŀ��������������n�ڵ���ȫƽ�����ĸ�������������ҾͲ�д�ˣ�
        //���ˣ��������ˣ�������AC�ɡ�
        //Ҳ���Ǳ�λ�������ĸ�������������������Ļ�����ô�������ģ������ż���Ļ���ô�������
        //1����ȫƽ������ֻ����ȫƽ�����Ż���������ͬ������
        if(n==0)return 0;
        int res=0,k=1;
        while(k*k<=n){
            k++;
            res++;
        }
        return res;
    }
};
int main(){

    return 0;
}
