#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��3������7:54:13
//class Solution {
//public:
//    bool validMountainArray(vector<int>& A) {
//        //��Ȼ�е��£���ô�ͱ����ɣ���һֱ�ھ�����ôд�������򵥣�
//        //����жϴ�������������жϴ����½����������½�֮��Ͳ�����������
//        // bool up=true,down=true;
//        bool up=true;
//        for(int i=0;i<A.size()-1;i++){//��ʵ����ȫ������ģ�����������ϵĵط���Ҫreturn��
//            if(A[i]==A[i+1])return false;//һ��ʼ���ǽ�
//            if(up&&A[i]>A[i+1]) up=false;//���鷳�����ҵ�˼·����������
//            else if(!up&&A[i]<A[i+1]) return false;//�ݣ��������뾫���д�������Ҳ����ˡ�
//        }//�������˵��˫ָ�룿���Ǵΰ¡����ᡣ���������ء�
//        return true;
//    }
//};
/*
 * 1.��ô˵�أ��о��Լ����Ǹ��˼�����ޡ�
 * 2.�����󽵣��ҵ�i�㣬i==0||i==N-1���β���ɽ�壬Ȼ���i�������ҡ�
 * 2.˼·2�Ƿֱ�������Һʹ������������
 * */
//11-4
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        //��ǰ�����������
        if(A.size()==0) return false;
        int i=0;
        while(i<A.size()-1)//���A�ǿ������Ļ�����ô�Ͳ��ܵ���size()�������ᱨ������֮ǰҪ���ж�
            if(A[i]<A[i+1])i++;
            else break;
        if(i==0||i==A.size()-1) return false;
        //��i�����������
        while(i<A.size()-1)
            if(A[i]>A[i+1])i++;
            else break;
        return i==A.size()-1;//�ж��Ƿ���ĩβ��
    }
};
//AC�ˣ�
int main(){

    return 0;
}
