#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��11������4:28:17
class Solution {
public:
	//���Ӷ�O(nlogk)��O(k)
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //дһ�¶Ѱɣ�����������·����һ���ġ�
        vector<int> ans;
        if(k==0)return ans;//ûע�⿴k�ķ�Χ����硣����
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<k;i++)
            pq.push(arr[i]);
        for(int i=k;i<arr.size();i++){
            int t=pq.top();//����front����
            if(arr[i]<t){
                pq.pop();pq.push(arr[i]);
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
/*
 * 1.֮ǰ����pythonд��AC�ˣ���û��������ܽᣬ��ʵ������ͨ���ѻ������ʵ�ֵģ������������������
 * 2.ʹ�ÿ��ŵĻ���ʱ��������O(n)���Ҫ��n-1����O(n2)���ռ�������O(logn)����
 * 3.�´θ�ϰдһ�¿��Űɣ�Ӧ��û��ʲô�Ѷȡ�
 * */

//5-23
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //�����ô󶥶�������
        if(k==0||arr.empty()) return {};//[0,0,0,2,0,5] 0���ǵ��п�
        priority_queue<int,vector<int>> pq;//ָ����������
        int m=k;
        while(k--){//��ʵ����ԹԵ���forѭ�����У�������ôץ��
            pq.push(arr[k]);
        }
        for(int i=m;i<arr.size();i++){
            if(arr[i]<pq.top()){//ǰ��Ҫ�ж�k==0��������ж�����pq��Ϊ�յ�,pq.top()�����ڻ����
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
//������������Žⷨ��
//�����ǵݹ�ġ�
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //�������
        if(k==0||arr.empty())return {};
        rquickSort(arr,k,0,(int)arr.size()-1);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(arr[i]);
        return ans;
    }
    void rquickSort(vector<int>& arr,int k,int left,int right){
        if(left>=right)return;
        int pivot=rand()%(right-left+1)+left;
        //����pivot��right//����Ӧ�ú�right��������Ϊ֮��Ŀ��Ŷ�����rightΪ��׼�Ƚϵ�
        swap(arr[pivot],arr[right]);
        int p=quickSort(arr,left,right);//�ҵ�pivot������λ��
        if(p+1>k)rquickSort(arr,k,left,p-1);
        else if(p+1<k) rquickSort(arr,k,p+1,right);
    }
    int quickSort(vector<int>& arr,int left,int right){
        int p=left-1;
        for(int i=left;i<right;i++){
            if(arr[i]<=arr[right]){
                p++;
                swap(arr[p],arr[i]);//p������߱���С��arr[right]��Ԫ��
            }
        }
        swap(arr[p+1],arr[right]);
        return p+1;
    }
};
//����ҲAC�ˣ������ף�������д��������̣������⡣û���ø���������˾��ְ����ÿ�������Ĺ��ܻ��д�ȷ�ϡ�
/*
 * 1.�����Ŀ��lc215��Ϊ������Ŀ��
 * 2.Ӧ�����������е���rquickSort�������𷵻�һ��pֵ�����������֮����±꣬��k�Ƚϣ��ж���ȥ���±Ƚ����
 *   �����ұߡ�rquickSort�в���һ���������arr[right]������Ȼ�����partion������partion��������һ���±꣬��
 *   ���ѡ���Ԫ�����մ�ŵ��±ꡣ������top-k����ⷨ�С�
 * 3.�ڿ����У�QuickSort����partition������partition������Զ����ͬ�ģ�����һ������õĽ����Ȼ����QuickSort
 *   �ݹ�����������ҡ���ô����������У�RandomQuickSort����randomPartition��randomPartition�����������ʵ��
 *   �ϻ��ǵ���partion����ȥ���֡����Թؼ��㻹��partion���������
 * 4.��ô��top-k�����У�mainֱ�ӵ���randomPartition�����־Ϳ����ˣ�Ȼ��������ķ���ֵ���ж�������û�����
 *   ���á�
 * */
int main(){

    return 0;
}
