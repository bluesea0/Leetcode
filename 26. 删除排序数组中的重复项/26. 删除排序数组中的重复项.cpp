#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��5������2:47:54
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //˼·��˫ָ�룬j�ǿ�ָ�룬i����ָ�룬iָ����һ�����Բ����λ��
        if(nums.empty())return 0;
        int i=0;
        for(int j=0;j+1<nums.size();j++){
            if(nums[j]!=nums[j+1]){//������λ����ô�жϰ�
                i++;
                nums[i]=nums[j+1];
            }
        }
        return i+1;
    }
};
/*
 * 1.AC�ˣ���27�����������˼·����һ����swap����Ϊ��������鲻Ҫ�ˣ����ԾͲ��ùܺ���Ĳ��֣�ֱ�Ӹ�ֵ�Ϳɡ�
 *   public int removeDuplicates(int[] nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
//���ģ��ٷ�д�ı���ţ��Ŷ��ֱ����j��1��ʼ��
 * */
int main(){

    return 0;
}
