#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��3������3:29:12
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //�����Ļ��Ͳ��ش���߽�����ˡ�
    	//���Ӷ���O(n)O(1)��
        int i=0,j=int(numbers.size())-1;//ǿ������ת������ô�������ţ�
        // high = numbers.size() - 1; �ٷ���ֱ��-1�ġ�
        while(i<j){
            int s=numbers[i]+numbers[j];
            if(s==target) return {i+1,j+1};
            else if(s<target)i++;
            else j--;
        }
        return {};
    }
};
//��Ȼ�Ƿǳ��򵥵�һ�����ˣ�easy��Ŀ��

int main(){

    return 0;
}
