#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��4������3:12:12
class Solution {
public:
    bool rotateString(string A, string B) {
        //�����жϳ��ȣ��п��ܳ��Ȳ���ͬ��
        if(A.size()!=B.size())return false;
        A=A+A;
        return A.find(B)==string::npos?false:true;
    }
};
/*
 * 1.�ҷ����ˣ��������ת�ģ����п��������ԭ���ģ������ĸ��ط���������ͬ���ֶΡ�
 * */
int main(){

    return 0;
}
