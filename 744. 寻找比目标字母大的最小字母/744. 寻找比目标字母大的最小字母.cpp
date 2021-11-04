#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��12������2:01:37
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //���ֲ��ң����ұ�target�պô����ĸ�����û�ҵ��ͷ�����С��
        int left=0,right=letters.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(letters[mid]<=target)
                left=mid+1;
            else right=mid;
        }
        return right==letters.size()?letters[0]:letters[right];
    }
};
/*
 * 1.������һ���Ӿ�AC�ˣ�ʱ��O(logn)���Ƚϻ����Ķ��֣�����right��ʼ��Ϊsize���Ȼ����㡣
 *   �˳�ѭ��ʱ��left==right�ģ���ô֮����right�Ϳ����ˣ�Ҳ����+1/-1�Ȳ�����
 * 2.
 * */
int main(){

    return 0;
}
