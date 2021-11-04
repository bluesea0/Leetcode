#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-20
//class Solution {
//public:
//    vector<int> printNumbers(int n) {
//        long long x=pow(10,n);
//        vector<int> v;
//        for(int i=1;i<x;i++)//O(10^n)
//            v.push_back(i);
//        return v;
//    }
//};
/*
1.�����AC�ˣ���ʵ�Ҳ�֪���������ʲô���壿��Ҫ�Ŀ������ʲô�أ�
2.ԭ���Ǵ������Ⱑ���һ���Ҫѧϰһ�µġ�
https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/
ȫ���з�+����λ0����
https://blog.csdn.net/qq_15711195/article/details/94651798
���������C++�汾�ģ�
*/

//5-22
/*
 * 1.����һ������Ǵ�ӡstring�Ļ���ͨ��ȫ������д��
 * */
class Try {
public:
    void printNumbers(int n) {
        vector<string> ans;
        string s="";
//        for(int i=1;i<=n;i++){
//        	printN(ans,s,i);
//        }
        printN(ans,s,n);//ע�����ﲻ��Ҫforѭ������Ϊn��һֱ������ȥֱ���ַ�������Ϊn��
        //�ٽ�ans����ת��Ϊint����
        for(int i=0;i<(int)ans.size();i++){
        	cout<<ans[i]<<" ";
        	if(i%10==0)cout<<"\n";
        }
    }
    void printN(vector<string>& ans,string& s,int len){
    	if((int)s.size()==len){
    		ans.push_back(s);
    		return;
    	}
    	for(int i=0;i<10;i++){
    		s.push_back(i+'0');
    		printN(ans,s,len);
    		s.pop_back();
    	}
    }
};

int main(){
    Try t;
    t.printNumbers(2);
    return 0;
}
