#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��18������11:30:53
class Solution {
public:
    vector<int> toVec(string s){
        s+=".";
        vector<int> ret;
        int index=0;
        while(s.find(".",index)!=string::npos){
            int t=s.find(".",index);
            ret.push_back(stoi(s.substr(index,t-index)));
            index=t+1;
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1=toVec(version1);
        vector<int> v2=toVec(version2);
        int i=0;
        while(i<v1.size()&&i<v2.size()){
            if(v1[i]<v2[i])return -1;
            else if(v1[i]>v2[i])return 1;
            i++;
        }
        if(i<v1.size()){//���v1û�б�����
            while(i<v1.size()){
                if(v1[i++]!=0)return 1;
            }
        }else{
            while(i<v2.size()){
                if(v2[i++]!=0)return -1;
            }
        }
        return 0;
    }
};
/*
 * 1.һ���Ӿ�AC�ˣ��൱�졣
 * 2.������⣬��������¿ռ临�Ӷ���O(m+n)����Ϊ����ռ䱣��������ô����ʹ��ͬʱ�����ķ�����
 *   �ڱ���ʱ�������Ƿ���ȣ�����ֻ�賣���ռ临�Ӷȣ�ţ��������дһ�¡�
 * */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //�ڱ����Ĺ����н�����1��2
        version1+=".";
        version2+=".";
        int m=version1.size(),n=version2.size();
        int i=0,j=0;
        while(i<m||j<n){//һ��ʼд����&&�жϣ�����������ȥѭ��֮����Ҫ���ж�
        	//"1.0.1"
        	//"1"�����������������
            int x=0;
            if(version1.find(".",i)!=string::npos){
                int t=version1.find(".",i);
                x=stoi(version1.substr(i,t-i));
                i=t+1;
            }
            int y=0;
            if(version2.find(".",j)!=string::npos){
                int t=version2.find(".",j);
                y=stoi(version2.substr(j,t-j));
                j=t+1;
            }
            if(x>y)return 1;
            else if(x<y)return -1;
        }
        return 0;
    }
};
/*
"1.0.1"
"1"
����whileѭ������Ӧ�øı�һ�£���ͦ����д�Ĺ���
*/
int main(){

    return 0;
}
