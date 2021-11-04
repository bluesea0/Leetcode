#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��5������2:09:05
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int i=0,j=nums.size()-1;
//        while(i<j){//�˳�ѭ����i==j
//            while(i<=j&&nums[j]==val)j--;
//            while(i<j&&nums[i]!=val)i++;
//            swap(nums[i],nums[j]);
//        }
//        return i==0?0:i+1;
//    }
//};//���ģ���[1,2,2] [2,2,2]��������������ô�찡����ô�ж������������أ�

//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //if(nums.size()==1) nums[0]==val?0:1;
//        int j=nums.size(),i=0;
//        for(i=0;i<j;i++){
//            if(nums[i]==val){
//                while(i<j-1&&nums[j-1]==val)j--;
//                swap(nums[i],nums[j-1]);
//            }
//        }//�ݣ�������������[2,2] 3��������ȫû����Ҫȥ�������ݣ������д�������������Ⱑ
//        return i;//��Ϊj-1��i�����ֳ��������⣬���Ѿ���ȫ�����ˡ�
//    }
//};
/*
 * 1.�ݣ��ύ�ˣ�ǧ�����㣬û�㵽���е���Ԫ������[2] 3���ݣ����������ˡ�
 * 2.д�����ַ����о���ͨ����������������
 * 3.���ģ����˽������Բ��Ǽ򵥼������Ŀ�ɣ����Ѱ�������ʹ�ø��ǣ�Ҳ������������size�Ĵ�С��
 *   ������û���뵽�ģ���һֱ����i�����ƣ�����ʵ���ǿ��Ʋ��˵ġ�
 * */

//1-6
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while(i<=j){//��Ҫ��=����Ȼ�����ж���һ��Ԫ��
            if(nums[i]==val){
                nums[i]=nums[j];
                j--;
            }else i++;
        }
        return j+1;
    }
};//ֻ�ǵ���һ�ַ�����AC�ˡ�O(n) O(1)
/*
 * 1.��Ҫ�Ƴ���Ԫ�غ���ʱ�����������ķ����Ƚ����á�����������˵���˵������������鶼��Ҫ�Ƴ���Ԫ�أ���ô
 *   ���������ͻ�Ƚϵ�Ч����ÿ��Ԫ�ض�Ҫ���и�ֵ������
 * 2.����ʹ�ÿ���ָ�룬iָ����õ�ĩβ��jָ����һ��!=valҲ���Ǵ������λ�á��´�Ҫдһ�����
 * */
int main(){

    return 0;
}
