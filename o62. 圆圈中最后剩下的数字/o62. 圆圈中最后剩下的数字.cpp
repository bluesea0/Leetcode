#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��8������5:31:39
//class Solution {
//public:
//    int lastRemaining(int n, int m) {
//        //�Բۣ���ĺ�����˼������⣬�����Ҳ��ᣬ���Ǽ򵥼��𣬵�����Ӧ��ֻ��ģ�£�
//        //�һ�����n��ô���vector��Ȼ��һֱѭ��n-1�Σ����ж������ĸ���0
//        //���е��Ѷ�
//    }
//};
class Solution {
public:
    int lastRemaining(int n, int m) {
        //Լɪ�����⣬
        int idx=0;
        for(int i=2;i<=n;i++){
            idx=(idx+m)%i;
        }
        return idx;
    }
};
/*
 * 1.AC�ˣ����Ǵ������ѧϰ�ģ�ÿ��ȥ�����൱�ڰ�ÿ��������ǰ�ƶ���mλ�����ֻʣ����Ϊһ��index����0����ô
 *   ÿ�ζ������ƶ�m�β���ÿ�������鳤�ȶ��ڱ仯��
 * */

//6-18
/*
 * 1.�����һ����Ǻ����������⣬��ÿ��index�����ƶ�m�Σ�����ģ�ϵ�ǰ���鳤�ȡ�
 * */
int main(){

    return 0;
}
