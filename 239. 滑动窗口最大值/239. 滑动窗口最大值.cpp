#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��31������2:58:40
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        //���ֻ��¼���ڵ����ֵ����ô�ؼ��������ǣ�������ֵ�Ĵ��ڵط����ˣ���ôȥ�ж�
//        //�δ�ֵ�أ��Ҹո��뵽�öѣ����ǲ��У���Ϊ����ʱ�����Ǹ�ɶ����Ҳֻ�ܵ���һ��ֵ
//        //������ѡ�񵯳��ĸ���
//        //��Ȼ�뵽�˵���ջ
//        //Ҳ�����õ���ջ��Ҫ���ߵ�left�п���ѹ��ջ�׵������������˾��ˣ���ͦ�ѵİ�����
//        //�ǲ���ֻ��Ҫ��¼�δ�ֵ�����ˣ����Ұ�����ΪleftҪ���ߣ�
//        //����΢дһ�°�
//        int cm=nums[0],cm2=nums[0],left=0,right=0;
//        while(right<nums.size()){
//            int r=nums[right++];
//            if(r>cm)cm=r;
//            else if(r==cm)cm2=r;//��¼�δ�ֵ
//            else if(r>cm2)cm2=r;
//            if(right-left>=k){
//                //��ʼ��С�󴰿�
//                int l=nums[left++];
//                if(l==cm)cm=cm2;
//                //cm2��ô�����أ������
//                //�Ҳ����ˣ���Ϊleftָ��1���������ֱ������ˡ����������ô�찡����һ����������ʱ
//                //sort���Ҳ����ˡ�
//            }
//        }
//    }
//};
/*
 * 1.ȷʵ��֪����ô�����о������Ŀ��ʵ���Ĳ��ǻ������ڵ�֪ʶ�㰡��Ϊʲô������ڻ������ܽ������ֹ�
 *   ��������������˻�����ģ��Ҿ������б�Ҫ��������
 * 2.���˹ٷ�������⣬��ĺþ�����˫����к�dp�ⷨ����left��right��¼��ֵ�����������left��right�ļ��㣬��
 * */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //˼·����left��right�ֱ��¼���ڵ����ֵ
    	cout<<"here";//���Ҳ��ӡ�������������ˡ�
        int m=nums.size();
        if(m<=1) return nums;
        vector<int> left(m,0),right(m,0);


        //left[0]=nums[0],right[m-1]=nums[m-1];
        for(int i=0;i<m;i++){
            if(i%k==0)left[i]=nums[i];
            else left[i]=max(left[i-1],nums[i]);
        }
        for(int i=m-1;i>=0;i--){//����ɵ���������ﻹi++����������ɵ���ˡ�
            if((i+1)%k==0||i==m-1)right[i]=nums[i];
            else right[i]=max(right[i+1],nums[i]);//���������Խ�����ô����
        }
//        for(int i=0;i<ans.size();i++){
//            ans[i]=max(left[i+k-1],right[i]);
//        }
        vector<int> ans(m-k+1,0);
        for(int i=0;i<ans.size();i++){
        	ans[i]=max(left[i+k-1],right[i]);
        }
        return ans;
    }
};
/*
 * 1.����AC�ˣ����ˣ�һֱ�Զ��˳���֪����ô���£����������Ҫi++�ǿɲ���Խ������
 * 2.�ٽ��е�һ�ֽⷨҲ�ǲ�������˵�ƶ��˴��ھ�Ҫ����ߵ������Ƴ�ȥ������������������ʱ���Ƴ�ȥ��
 *   �������ȶ����д����pair�������±�ġ�
 * 3.�´θ�ϰѧϰ�ڶ��ֽⷨ��
 * */

//3-21
/*
 * 1.������������Ҳ���ʶ�����ϵķ���ֻ�Ǻ��ɵķ��������������Թ��������ĳ���Ľⷨ����֮ǰȷʵ���е�Ͷ��ȡ��
 *   �ˣ����Ӧ�����ô󶥶��������
 * */
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //���ȶ�����ô��ʼ�����ţ�
        priority_queue<pair<int,int>> pq;//Ĭ����vector<pair<int,int>>��
        vector<int> ans;
        for(int i=0;i<k;i++)
            pq.push(make_pair(nums[i],i));//�����Ļ���Ĭ�ϰ��յ�һ��Ԫ�شӴ�С����
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            //����Ҫע��pq����Ϊ�գ������������ѭ��
            while(!pq.empty()&&pq.top().second<=i-k)pq.pop();
            pq.push(make_pair(nums[i],i));
            ans.push_back(pq.top().first);
        }
        //cout<<ans.size();
        return ans;
    }
};
/*
 * 1.AC�ˣ�����ǳ�����������ʱ�䣺O(nlogn)����������Ϊ������������ôforѭ����Ҫѭ��n�η��룬ÿ����һ��
 *   Ԫ�صĸ��Ӷ�Ϊlogn���ռ䣺O(n)�����������ȶ��д洢����Ԫ�ء�
 * 2.�������дһ�µ������еĽⷨ��
 * */

//6-16
/*
 * 1.���Ĳ��ǵ���ջ���ǵ������У���ͷ���ģ����˾��ˣ�����һ���ӾͶ���
 * 2.��������Ҫ��˫���deque��
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //ʹ�÷��ϸ�ݼ��ĵ�������
        //queue<pair<int,int>> q;
        deque<pair<int,int>> q;
        for(int i=0;i<k;i++){
            //��������˴��ڵ��ڵģ���ô���Ե�����Ϊ��ǰ����֮ǰ�����Ʒ�ˡ�
            while(!q.empty()&&q.back().first<nums[i]){
                q.pop_back();//ע�������Ǻ�back�Ƚϰ���ͬʱҲ�Ǵ�back����
            }
            q.push_back(make_pair(nums[i],i));
        }
        vector<int> ans;
        ans.push_back(q.front().first);
        for(int i=k;i<nums.size();i++){
            //�������ڵ�ǰ���ڵ�ֵ
            while(!q.empty()&&q.front().second<=i-k)q.pop_front();
            //while(!q.empty()&&nums[i]>q.front().first)q.pop();
            //�Ӻ��浯��С�ڵ�ǰԪ�ص�ֵ
            while(!q.empty()&&nums[i]>q.back().first)q.pop_back();
            q.push_back(make_pair(nums[i],i));
            ans.push_back(q.front().first);
        }
        return ans;
    }
};
/*
�������[1,3,1,2,0,5] 3
��ȷ���[3,3,2,5]
���ʹ�õ��򵯳��Ķ��У�Ҳ����ֻ��ͷ�������ܱ�֤�ǵ����ģ�������Ҫ��deque��
*/
int main(){
//	Solution2 s;
//	vector<int> nums={1,-1};
//	s.maxSlidingWindow(nums, 1);
	string s="  ab ";
	int index=-1;
	while(s.find(" ",index+1)!=string::npos){
		index=s.find(" ",index+1);
		cout<<index<<"\n";
	}
    return 0;
}
