#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月18日下午11:30:53
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
        if(i<v1.size()){//如果v1没有遍历完
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
 * 1.一下子就AC了，相当快。
 * 2.看了题解，这种情况下空间复杂度是O(m+n)，因为额外空间保存结果，那么可以使用同时遍历的方法，
 *   在遍历时，计算是否相等，这样只需常数空间复杂度，牛啊！明天写一下。
 * */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //在遍历的过程中解析出1和2
        version1+=".";
        version2+=".";
        int m=version1.size(),n=version2.size();
        int i=0,j=0;
        while(i<m||j<n){//一开始写的是&&判断，但是这样出去循环之后还需要再判断
        	//"1.0.1"
        	//"1"，针对这样的样本，
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
这样while循环条件应该改变一下，还挺不好写的哈。
*/
int main(){

    return 0;
}
