#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��29������4:28:29
class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0,n=chars.size(),start=0;
        for(int i=0;i<n;i++){
            if(i!=n-1&&chars[i]==chars[i+1])continue;
            if(i==start){//˵��ֻ��һ���ַ�����
                chars[index++]=chars[i];
                start++;//["a","a","a","a","a","b"]
                //˵��������Ȼ��Ҫ������
            }else{
                string t=to_string(i-start+1);
                chars[index++]=chars[i];
                for(int i=0;i<t.size();i++){
                    chars[index++]=t[i];
                }
                start=i+1;
            }
        }
        return index;
    }
};
/*
 * 1.AC�ˣ�������Ȼ��Ҫ��ϰ��д��ʱ��������Щ��·����֪���ǲ������Ž⡣
 *   ������⣬������д�ĺܲ�����ͦ����ģ����ģ��ܰ���
 * */
int main(){

    return 0;
}
