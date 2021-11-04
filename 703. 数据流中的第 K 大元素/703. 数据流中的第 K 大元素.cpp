#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��11������1:40:53
class KthLargest {
public:
    priority_queue<int> big;//Ĭ���Ǵ󶥶�
    priority_queue<int,vector<int>,greater<int>> small;//С����
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        if(nums.empty()) return ;

        for(auto n:nums)
            big.push(n);
        for(int i=0;i<k&&!big.empty();i++){//������������⣬��������������nums����Ϊ�ա�
            small.push(big.top());
            big.pop();//[[2,[0]],[-1],[1],[-2],[-4],[3]]
            //����������������̫���˺����˰ɡ�
        }
    }
   //["KthLargest","add","add","add","add","add"]
//[[1,[]],[-3],[-2],[-4],[0],[4]]
//���������������һ��ʼ��û�еİ�
    int add(int val) {
        if(small.empty()||small.size()<K){
            small.push(val);
        }else{
            if(val<=small.top()){//������ϸ����������ﻹҪ����size
                big.push(val);
            }else{
                big.push(small.top());
                small.pop();
                small.push(val);
            }
        }
        return small.top();
    }
};
/*
 * 1.���������AC�ˣ����ύ�˺ü��κü��ΰ����ҿ����ҵ��裬����ˣ���Ϊ�Ǹ�easyû�뵽�ܶ�Ӱ���
 *   �Ҷ�û�п��ǵ����ؼҵ���Ϣ�ɡ�������������֮����Ϊ�Լ��ĺ��˾��ύ�ˣ�ʵ���ϻ��Ǵ������⣡
 * 2.ʱ�临�Ӷȣ����캯����O(nlogn)��add������O(logn)
 * 3.�Բۣ��ұ������ˣ��ҿ��˹ٷ���⣬ԭ��ֻ��Ҫһ�����ȶ��оͿ����˰����ҿ����ˣ���ô���£�
 *   ���size>k����ô��pop��ѧ���ˡ�
 * */

//2-13
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K=0;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            if(i<k)pq.push(nums[i]);
            else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.size()<K)pq.push(val);
        else{
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
/*
 * 1.AC�ˣ�����ˮƽ������ߡ�
 * 2.�ؼ���С���ѣ�����ǰk�����ֵ��
 * */
int main(){
	vector<int> nums={0};
	KthLargest kl(2,nums);
	vector<int> a={-1,1,-2,-4,3};
	for(auto n:a)
		cout<<kl.add(n)<<endl;
    return 0;
}
