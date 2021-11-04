#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��11������3:52:45
//class Solution {
//public:
//    vector<int> partitionLabels(string S) {
//        //�ҵ��������п��ܸ���һ���ַ��������ܷ֣�
//        //abac��Ŷ�������ˣ�ÿ�����ܷ֣�������ÿ��������̣�������̲�������һ���Ӵ���
//        //������֮ǰһ������ĸ��
//        //�е��ѶȰ���
//    }
//};
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //ʹ��̰�ĵ�˼�룬�ȱ���ÿ�μ�¼����λ��
        vector<int> vec(26,-1);
        for(int i=0;i<S.size();i++)
            vec[S[i]-'a']=i;
        int end=-1,start=0;
        vector<int> ans;
        for(int i=0;i<S.size();i++){
            end=max(end,vec[S[i]-'a']);//������д���Ǵ���ģ��һ���û���
            if(end==i){//˵��������������
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};
/*
 * 1.AC�ˣ������ġ�̰���㷨+˫ָ�롣
 * */
int main(){
	Solution s;
	s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
