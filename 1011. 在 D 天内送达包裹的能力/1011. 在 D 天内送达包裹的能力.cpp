#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��4������7:55:45
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        //����ô�ö��ְ���left��right�ĳ�ʼ������֪����ô��
        //Ҳ������sum����ʼ���ɣ���Ϊ�����Ե�һ�������ŵõ�11���ǲ��Եİ������뿴��⣬
        //��ȫ�벻��������ô�����ַ���
        //������⣬���⣿�ؼ������left��right��ȷ������������
        int max=weights[0],sum=0;
        for(auto w:weights){
            if(w>max)max=w;
            sum+=w;
        }
        int left=max,right=sum+1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(helper(weights,mid,D))
                right=mid;//���Լ�С��������
            else left=mid+1;
        }
        return left;
    }
    bool helper(vector<int>& weights, int mid,int D){

    }
    // bool helper(vector<int>& weights, int mid,int D){//��������жϺ������е��ѶȰ�
    //     int d=0;//�������ô�жϰ������ѵİ���
    //     for(auto w:weights){
    //         d+=w;
    //         if(d>D){
    //             D--;
    //             d=w;
    //         }else if(d==D){D--;d=0;}
    //         if(D<0) return false;
    //     }
    //     return true;
    // }
};
//����https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.5-shou-ba-shou-shua-shu-zu-ti-mu/koko-tou-xiang-jiao
/*
 * 1.���˽̳�֮���������ô�ö��֣�ͦ�ѵġ�
 * 2.�ж��Ƿ��ܹ������������Ҳ�ѣ���ûд������������������
 * */
int main(){

    return 0;
}
