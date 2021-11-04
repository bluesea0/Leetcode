#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��16������2:34:29
//class Solution {
//public:
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        //��ȥ����Ҳ���˰ɡ�����
//        //�����������Ļ�����ôÿ����һ����Ҫ�������е�֮ǰ�������Ƿ�ϸ�
//        //�������ˣ��Ծ�û��˼·���ٴ���ȥҲ�����и���˼·������������
//    }
//};//��Ȼ�������û��ʲô˼·�ģ����˹ٷ���⿴��̫��������grand�ıȽϺá�
//https://www.cnblogs.com/grandyang/p/5928417.html��
//����������˵�ÿ��ŵģ���֪����Σ����ǰ�sort��Ϊ�˿�����

//12-20
/*
 * 1.���ӷ�����[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *   �����[4,4] [5,2] [5,0] [6,1] [7,1] [7,0]
 *   �ٷ�����У���С�����������û�������������ʲô��˼�������ˡ�
 *   ����[7,0] [7,1] [6,1] [5,0] [5,2] [4,4]
 *   �Ӹߵ��ͷǳ�����⣬��Ϊ������˲����ǰ��Ĳ�����Ӱ�죬ֻ��Ҫ�����i��λ�ã���i��λ��ǰ��ki��
 *   �˾ͺ��ˣ�������ˣ�����
 * */
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]>b[0] ||(a[0]==b[0]&&a[1]<b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans;
        for(auto p:people){
            ans.insert(ans.begin()+p[1],p);
        }
        return ans;
    }
};//��������򵥵ķ������㶨�ˡ�����
int main(){

    return 0;
}
