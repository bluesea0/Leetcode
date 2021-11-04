#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��13������8:59:38
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //O(k)�Ŀռ临�Ӷȣ�����ÿһ�в�������ǰһ�м���������ǾͲ�����ֱ�Ӽ����k��
        //�İ���ֱֻ������һ������Ϊk�����飿�Ҿ��ò��аɣ�
        //��֪���ˣ�ֻ����һ������Ϊk�ģ������ڼ���ǰ���ʱ����治�þͺ��ˣ�
        //ʱ�临�Ӷȿ϶��ǲ����С�ģ�����ԭ�ظ�����
        vector<int> nums(rowIndex+1,1);
        for(int k=2;k<=rowIndex;k++){
            for(int j=k-1;j>=1;j--){
                nums[j]=nums[j]+nums[j-1];
            }
        }
        return nums;
    }
};
/*
 * 1.AC�ˣ��ȽϿ��ģ�������³��ָ��ǵ������Ǿ͵�����¡�
 * 2.������������ĵ���ǣ���Ϊ�����ж���Ŀռ䣬�Ǿ�ԭ�ظ��£�������ⷢ����ʵ�ǹ��������˼�룬
 *   �ǳ����ģ���
 * */
int main(){

    return 0;
}
