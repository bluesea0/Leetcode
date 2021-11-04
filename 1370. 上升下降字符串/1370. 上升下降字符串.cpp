#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��11��25������2:21:44
class Solution {
public:
    string sortString(string s) {
        //˼·�����ַ�������ģ����̣�
        //���ȶ��ַ�����С��������Ҫ�ù�ϣ�����ظ��Ĳ��ֳ��������������������
        //���Ӷ�O(Cnlogn)m���ظ��Ĵ�����nlogn�������Ӷȣ�n���Ҳֻ��26.
        // �ռ���O(c)����ȻҲ�����������O(logn)
        //�Ժ�Ҫ�ȷ�����˼·+���Ӷ�֮����д���룬������ĸ�רҵ
        unordered_map<char,int> um;
        for(auto c:s)
            um[c]++;
        string ans="";
        bool flag=true;//Ĭ�Ͽ�ʼ������
        while(true){
        	string temp="";
            for(auto& p:um){//maya����Ҫ���ð�!
                if(p.second!=0){
                    temp+=p.first;
                    p.second--;//�ѵ���������ܸı䣿
                }
            }
            if(temp.size()==0)return ans;//˵��ȫ�����ʹ���
            if(flag)//��������ôif(bool)�ˣ��в�����
                sort(temp.begin(),temp.end());
            else
                sort(temp.begin(),temp.end(),greater<char>());
            cout<<temp<<endl;
            flag=!flag;//ת����������bool=!bool;�в���
            ans+=temp;
        }
    }
};
/*
1.����leetcode��
 c=1,d=1,e=3,l=1,o=1,t=1
 cdelotee
2.���������ĸо�ɵ�Ʊ�˵�ľ����Ұɣ���ô�Ͱ����򶼷ŵ�forѭ�����ˣ�
3.�����AC�ˣ���Ŀǰ���������easy���ϣ�mediumδ����
4.�ٷ����������ǣ�Ͱ���������˹ٷ�����Ҳ�֪���������������ء�
  ��Ϊֻ�����ַ���������ֱ�ӽ���Ͱ�������������롣ѧ���ˡ�
*/

//12-20
class Solution {
public:
    string sortString(string s) {
        vector<int> occ(26,0);//��¼��Ӧ�ַ����ֵĴ���
        for(auto c:s)
            occ[c-'a']++;
        string ans="";
        while(ans.size()<s.size()){//���ģ������ѭ�����Ӷ���ô���
            for(int i=0;i<26;i++){
                if(occ[i]==0)continue;
                ans+=(i+'a');//Ҳ���Ի���push_back
                occ[i]--;
            }
            for(int i=25;i>=0;i--){
                if(occ[i]==0)continue;
                ans+=(i+'a');
                occ[i]--;
            }
        }
        return ans;
    }
};
/*
 * 1.AC�ˡ�ʱ�䣺���Ӷ��Ҳ����㰡
 * 2.ͨ������⣬�ҷ������Ѿ������˶�����ֻ��Сд�ַ�������Ŀ��ֱ����������vector<int> occ(26,0)��
 *   �������ϣ�����ˣ�
 * 3.����һ����⣬ԭ�����ڵ�˵���ǣ�Ͱ������
 * 4.   for (char &ch : s) {
            num[ch - 'a']++;
        }//����forѭ���õ������ð���ѧ���ˡ�
   5.���ˣ����˹ٷ����ĸ��Ӷȷ�����O(|C||s|)������C��ʾ�ַ����У��ַ��еĸ�����|s|Ϊ�ִ����ȡ�
     �����ǵ������������������ַ�����ͬһ������ô�͵����صر��������˾��ˣ�ֱ�����ˣ�
 * */
int main(){
	Solution s;
	cout<<s.sortString("rat");
//	string a="bca";
//	sort(a.begin(),a.end(),greater<char>());//cba
//	cout<<a;
    return 0;
}
