#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��8������2:01:50
//class Solution {
//public:
//    vector<int> ans;
//    vector<int> splitIntoFibonacci(string S) {
//        //˼·�����ݣ��з����������ֱ��жϡ�
//        //���Ӷ���ô�������Ҳ��ᰡ������Ҫ�ö�������log������O(n^2)һ��
//        if(S.size()<=2) return ans;
//        //DFS�Ļ����������forѭ���𣿲�����ʲô��
//        //����dfs������϶�Ҫ�в�forѭ���İɣ�
//        //���ݼ��кõ��ַ������Ǵ����±��أ�
//        //���ʵ�ּ���s3��
//        //����Ϊʲô�أ���������˼·�������ڴ���ʵ������д��������
//        //������s1Ҫ��һ���������У�s2ҲҪ��һ���������У�
//        //�ҹ��ˡ�
//    }
//};
/*
 * 1.˼·������ô��˼·������д�����������Ҽǵ�֮ǰ����һ���ǳ���ģ�
 * 2.����grand�͹ٷ���⣬�����˼���ţƤ��//������Ŀ306��17��93
 * */

//12-22
/*
 * 1.����������ĸ��ܾ���ͷ�ۣ�����飡����������������Ŀ������·�ģ�ֻ�����Ҳ�֪�������·��ô�����
 * 2.�����Ҫ���ǵ����ʵ���Ƕ࣬�ǵ��ֶ����м�����������������⡣
 * 3.�Կ��и�Ĳ���������������Ĳ���������ǰ��ɵĽ������Ҫ����start���ݹ����ǰ�����ֵļ��룬֮��
 *   ��pop������ǵ��͵ĵݹ鰡��
 * */

//12-23
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> out,ans;
        dfs(S,0,out,ans);
        return ans;
    }
    void dfs(string s,int start,vector<int>& out,vector<int>& ans){
        if(!ans.empty())return;//ΪʲôҪ����һ���أ�//����������123
        //��Ҫ����һ�䣬��Ϊ��������Ҫ�󷵻����еĽ����ֻҪ�ҵ�һ����ok
        //���Ҳ�൱��һ����֦�Ĳ����������Ҫ�������еĽ������ô��������һ���ˡ�

        if(start>=s.size()&&out.size()>2){//����Ҫע��out�ĳ��ȣ�����������ȫ�����ֵ�һ������������ֻ������Ԫ�ء�
            ans=out;return;
        }
        for(int i=start;i<s.size();i++){
            string str=s.substr(start,i-start+1);
            if(str.size()>1&&str[0]=='0')break;//�������>1�ҿ�ͷ��0����ô��break��
            //����Ҫ�ٽ��б����ˡ�
            long long cur=stol(str);
            if(cur>INT_MAX)break;//�������ͷ�Χ���˳�ѭ��
            int len=out.size();
            if(len>1){
                if(cur<(long)out[len-1]+out[len-2])continue;//����Ҫת��Ϊlong��
                //signed integer overflow: 2 + 2147483647 cannot be represented in type 'int'��Ӧ�þ�����Ϊ�ұ���ӳ�����int�ı�ʾ��Χ��������Ҫת��Ϊlong
                if(cur>(long)out[len-1]+out[len-2])break;
            }
            out.push_back(cur);
            dfs(s,i+1,out,ans);
            out.pop_back();
        }
    }
};//�۰�Ŷ��AC�ˣ���ô���Ӷ���η����أ���ȫ�������������ݼ�ֽ�ģ�������������
//��ô���ǣ������󲻳�����
/*
 * 1.O(nlog^2C)����Ϊֻ��ǰ����������Ҫȷ���ģ����������ͷ�Χ�ڣ����ĳ��Ȳ�Ӧ�ó���log10C��
 * */
int main(){

    return 0;
}
