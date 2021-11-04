#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��30������4:16:16
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //�����о�û��ʲô�㷨˼�밡
        if(nums.empty()) return {};
        if(nums.size()==1) return {to_string(nums[0])};//��������Ӧ���ǿ��Եİ�
        int start=0,end=0;//��¼��ʼ�ͽ������±�
        vector<string> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[end]+1)
                end=i;
            else{
                if(start==end)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                start=end=i;
            }
        }
        if(start==end)//����forѭ��������Ҫ������ôһ�£�ͦ���µġ�
            ans.push_back(to_string(nums[start]));
        else
            ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
        return ans;
    }
};
/*
 * 1.���ģ���Ȼ�����100%�����ˡ����Ӷȣ�O(n) ����������Ļ����ռ���O(1)��
 * 2.��Ϊ��ÿ�ζ��Ǻ���֮ǰ��ȥ�Ƚϣ��Ͳ��ã��˳�ѭ����������һ�¡�
 * public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> summary = new ArrayList<>();
        for (int i = 0, j = 0; j < nums.length; ++j) {
            // check if j + 1 extends the range [nums[i], nums[j]]
            if (j + 1 < nums.length && nums[j + 1] == nums[j] + 1)//�����������Ԫ�صĻ����ͻ�ֱ��
                continue;//���������
            // put the range [nums[i], nums[j]] into the list
            if (i == j)
                summary.add(nums[i] + "");
            else
                summary.add(nums[i] + "->" + nums[j]);
            i = j + 1;//i����start
        }
        return summary;
    }
}
3.�ٷ��Ľ���д�ĺúð�����������һ���Ҫ�ٶ�ѧϰ����
 * */

//1-10
class Solution2 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(i+1<nums.size()&&nums[i]+1==nums[i+1])i++;
            if(i==j)ans.emplace_back(to_string(nums[i]));
            else ans.emplace_back(to_string(nums[j])+"->"+to_string(nums[i]));
        }
        return ans;
    }
};
/*
 * 1.��Ҳget�˹ٷ�����д��~~~
 * */
int main(){

    return 0;
}
