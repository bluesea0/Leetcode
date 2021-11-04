#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��4������5:12:15
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        //��Եľ���������Ҫ�������е�
        //˼·��û��˼·����ȫ���ᣬ�ٺ١�
        int max=piles[0];
        for(auto p:piles)
            if(p>max)max=p;//��ȡ���ֵ
        int left=1,right=max+1;
        cout<<left<<" "<<right<<endl;
        while(left<right){
            int mid=left+(right-left)/2;
            //�����ﻹ��Ҫ���������е�ÿ���������㰡
            if(helper(piles,mid,H)){
                right=mid;
            }else left=mid+1;
            cout<<left<<" "<<mid<<" "<<right<<endl;
        }
        return left;
    }
    bool helper(vector<int>& piles,int mid,int H){
        int h=0;
        for(auto p:piles){
            int t=p/mid+((p%mid==0)?0:1);//��벿��Ҫ�����ţ���Ȼ?ǰ�벿�ֶ������ж������ˣ�
            h+=t;
            if(h>H) return false;
        }
        cout<<h<<endl;
        if(h>H) return false;
        return true;
    }
};
//AC�ˣ���ʵ����̫���ˣ���������֪������Ԫ�����ԭ������������
//https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.5-shou-ba-shou-shua-shu-zu-ti-mu/koko-tou-xiang-jiao
//����˴��еĽ��⣡
/*
 * ʱ�临�Ӷȣ�O(NlogW)������ N ���㽶�ѵ�������W �����㽶�ѵĴ�С��
�ռ临�Ӷȣ�O(1)��
 * */

//11-24
/*
 * 1.��θ�ϰ�ؼ���������Ϊʲô����left��������right�������˳�ʱleft==right�ģ�
 *   ����һ������3 6 7 11��H=8
 *   left=1,right=12;//����ҿ�
 *   	mid=6,h=1+1+2+2=6 true
 *   left=1,right=6;
 *   	mid=3,h=1+2+3+4=10 false
 *   left=4,right=6;
 *   	mid=5,h=1+2+2+3=8 true
 *   left=4,right=5;
 *   	mid=4,h=1+2+2+3=8 true
 *   left=4,right=4; return���Եģ��˳�ʱ����ȵģ����Է����ĸ���һ����
 * */
int main(){
	vector<int> v{3,6,7,11};
	Solution s;
	cout<<s.minEatingSpeed(v, 8);
    return 0;
}
