#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��18������10:04:10
class Solution {
public:
    int sumNums(int n) {
        //������˼���������
        return n*(1+n)/2;
    }
};
/*
 * 1.֮ǰ����ôд�ģ�����û��������⣬����ʹ��forѭ������ô�ͶԶ�Ӧ�ݹ飻
 *   ����ʹ��if�ж���ô����&&��·���á�
 * */
class Solution {
public:
    int sumNums(int n) {
        //return n&&(n+sumNums(n-1));
        n&&(n+=sumNums(n-1));//��&&����if�жϣ���n=0ʱ����·��
        return n;
    }
};
int main(){

    return 0;
}
