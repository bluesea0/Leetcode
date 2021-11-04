#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��6������3:34:53
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //һ���Ƚ���Ҫ�������������Ǵ�ǰ����ȽϵĻ������ⲻ�˻����Ԫ���ƶ�
        //��ô�ʹӺ���ǰ�Ƚ��ˡ�
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
        //���ʣ��ķŽ�ȥ��
        //˵����û����
        while(i>=0)nums1[k--]=nums1[i--];
        while(j>=0)nums1[k--]=nums2[j--];
    }
};
/*
 * 1.AC�ˡ����Ӷ���O(m+n),O(1)��
 * */
int main(){

    return 0;
}
