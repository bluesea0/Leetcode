#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��10������3:13:26
//class Solution {
//public:
//    int subarraysWithKDistinct(vector<int>& A, int K) {
//        //˼·��O(n^2)
//        int left=0,right=0,ans=0;
//        //unordered_set<vector<int>> us;
//        //��ok�İ�
//        unordered_map<int,int> um;
//        while(right<A.size()){
//            char c=A[right];
//            if(um.size()==K&&um.count(c)==0){//==0��Ϊ�˱�֤�
//                //��Сleft
//                while(um.size()==K){
//                    ans++;
//                    cout<<left<<" "<<right-1<<endl;
//                    if(--um[A[left]]==0)um.erase(A[left]);
//                    left++;
//                }
//            }
//            um[c]++;
//            right++;
//        }
//        while(um.size()==K){//˵������δ�Ƴ���
//            ans++;
//            if(--um[A[left]]==0)um.erase(A[left]);
//            left++;
//        }
//        return ans;
//    }
//};
/*
 * 1.�ұ���������д�ģ����ǵ�һ������A = [1,2,1,2,3], K = 2�����ԣ�����������Ϊ����ֻ�����ұ߽�ȷ�������
 *   �£���С��߽磬�����ұ߽�С��ʱ�����������Ķ�û�������ڡ�
 * 2.������ת��Ϊ��������K����ͬ���ַ�-������k-1��ͬ���ַ�=ǡ�ð���k����ͬ���ַ���res += right - left
 * 3.
 * */
int main(){

    return 0;
}
