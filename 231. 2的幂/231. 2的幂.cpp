#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-16
/*
1.��Ҫ��˼·�ǣ��ж����ұߵ�1�Ƿ������λ��
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;//��Ҫ��������жϣ����뵱�л��и�����
        //��Ŀ��˵���ǡ�����һ����������
        return (n&(n-1))==0;
    }
};
//10-22��ϰ��ͦ���������
int main(){
    Solution s;
    cout<<s.isPowerOfTwo(8);
    return 0;
}
