#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��10������2:14:03
class Solution {
public:
    string longestPalindrome(string s) {
        //Ҫ����ż��
        //��ô��һ�������ж�i-1��i+1��λ���Ƿ���ͬ��
        //dp[i]��ʾ����Ϊ���������չ���Ļ����Ӵ�����
        //������������뷨�Ļ�����ʵ�ò���dp�İ���
        //��Ϊÿ�����Ķ���һ�������Էֿ��жϾͺ��ˡ�
        int n=s.size(),start=0,len=1;//��̵�����������len��ʼ��Ϊ1
        for(int i=1;i<n-1;i++){
            int t=check1(s,i);
            if(t>len){
                len=t;
                start=i-len/2;
            }
        }
        for(int i=0;i<n-1;i++){
            int t=check2(s,i);
            if(t>len){
                len=t;
                start=i-len/2+1;
            }
        }
        return s.substr(start,len);
    }
    int check1(string& s,int index){
        int i=1,n=s.size();
        while(index+i<n&&index-i>=0){
            if(s[index+i]==s[index-i])i++;
            else break;
        }
        return 2*(i-1)+1;
    }
    int check2(string& s,int index){
        int i=0,n=s.size();
        while(index-i>=0&&index+i+1<n){
            if(s[index-i]==s[index+i+1])i++;
            else break;
        }
        return 2*i;
    }
};
/*
 * 1.AC�ˣ�����д�ıȽϷ�����ö�ٻ������ģ�ʹ��������չ�����ٽ�ػ�����չ��д�ĺܼ�ֻ࣬д��һ����
 *   ����������ʱ���Σ�expandAroundCenter(s, i, i);ż��ʱ����expandAroundCenter(s, i, i+1);
 *   ѧϰ�ˡ����ص�Ҳ�����ұ߽�{}��
 * 2.ʹ��dp�Ľⷨ��dp[i,j]��ʾi~j�Ƿ��ǻ��Ĵ�����Ҫ��С������и��¡�ö���ִ����ȣ�ö����㣬��������
 *   ��ʵ��ͦ�鷳�Ĺ����ռ临�Ӷȸ����ˡ�
 * */
int main(){

    return 0;
}
