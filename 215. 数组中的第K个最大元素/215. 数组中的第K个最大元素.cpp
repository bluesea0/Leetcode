#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��7������4:00:54
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //˼·��ʹ�ô󶥶ѱ���Ԫ�أ��ڵ���ʱȥ��
        priority_queue<int> pq;
        if(nums.size()==0)return 0;
        for(auto n:nums)
            pq.push(n);
        int ans=pq.top();
        //�Բۣ�������ˣ������˼��ǵ�k��������Ǿ�ҪС����Ҳ���԰ɡ�
        //�Բۣ��Ҹɴ������ɣ������������ˣ��˼��ǲ���ȥ�ء������ǵ�k����ͬ��Ԫ�أ����ˣ�
        while(k--){//��Ψһ��ȷ���ľ���pq����Щ���������Ƿ��ǶԵġ�����
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};
/*
 * 1.�Ҳ�����¡�ֱ�������ȼ������ˡ��ٷ���������ֱ����˺�Ѵ��룬���ˣ�����˵���������Ҫ��ģ���Ҫѧ
 * 2.����grand�Ľⷨ���Ҳŷ��֣������ǲ�����µ�д������Ҳ������������һ��ģ�
 *class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};//̯��!
 * */

//12-9
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //ʹ����������������
        //�����ѡ��һ���ŵ����÷ŵ�λ�ã�֮���ж����λ��==k��
        //<k�Ļ�left=p+1��>k�Ļ�right=p-1
        if(nums.size()==0)return 0;
        int left=0,right=nums.size()-1;
        k=nums.size()-k;
        while(left<right){
            int p=partition(nums,left,right);
            if(p==k)return nums[p];
            else if(p<k) left=p+1;
            else right=p-1;//����ȥ��ֻ��һ��Ϳ�����
        }
        //��ô������淵��ʲô�أ���΢�е������ˡ�
        return nums[left];//��ȵ�ʱ����˳�
    }
    int partition(vector<int>&nums,int left,int right){
        int p=rand()%(right-left+1)+left;//[left,right]
        swap(nums[right],nums[p]);
        return quickSort(nums,left,right);
    }
    int quickSort(vector<int>&nums,int left,int right){
        int x=nums[right];
        int p=left-1;
        for(int i=left;i<right;i++){
            if(nums[i]<=x){
                p++;
                swap(nums[p],nums[i]);
            }
        }
        swap(nums[p+1],nums[right]);
        return p+1;
    }
};
/* 1.�����������AC�ˣ�̫�����ˣ�������ʱ����۵������� O(n)��
 *   �ݹ�ʹ��ջ�ռ�Ŀռ���۵�����ΪO(logn)
 * 2.������Ҫ����ʹ�ö�����������
 * */

//12-14
//�о���д�������������������
/*
 * 1.��ô�����ֶ�����һ�°ɡ����ӣ�[3,2,1,5,6,4]
 *  i=2: max(2,5):larget=5,nums[2]=4,i=5,nums[5]=1;=>[3 2 4 5 6 1]
 *  i=1: max(1,5):larget=3,larget=4,A[i]=A[1]=6,i=4,A[4]=2,
 *  �������������д���ҷ��֣�ȷʵ������̫�а������ֶѻ��ǾͿ��ӻ��ȽϷ���ģ�
 * */
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //�Ƚ���
        //�ӵ����ĵ�һ����Ҷ�ڵ㿪ʼ
        int m=nums.size()-1;
        for(int i=nums.size()/2-1;i>=0;i--){
            maxHeap(i,m,nums);//����±껹ͦ�Ѹ�İ�
        }
        for(auto n:nums)
        	cout<<n<<" ";
        cout<<endl;
        for(int i=1;i<k;i++){
            //���׸�0�����һ������
            swap(nums[0],nums[m-i+1]);
            maxHeap(0,m-i,nums);
            for(auto n:nums)
            	cout<<n<<" ";
            cout<<endl;
        }
        return nums[0];
    }

    void maxHeap(int i,int end,vector<int>& nums){//�����Ŀ���ǵ�����i��Ԫ�ص����ʵ�λ��
        int t=nums[i];//indexָ���������Ҫ���õ�λ��
        for(int largest=2*i+1;largest<=end;largest=2*largest+1){//largest����ȥ�����������Ǹ�����
            if(largest!=end&&nums[largest]<nums[largest+1])largest++;
            if(nums[largest]>t){//������i��Ԫ�ص����ʵ�λ�ã��������ﶼ��t�Ƚϡ�
                nums[i]=nums[largest];
                i=largest;
            }else break;
        }
        nums[i]=t;
    }
};
int main(){
	Solution2 s;
	vector<int> v={2,1};
	s.findKthLargest(v, 2);
    return 0;
}
