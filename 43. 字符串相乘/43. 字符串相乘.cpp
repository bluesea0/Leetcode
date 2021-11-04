#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��10������11:48:18
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";//��Ҫ�ж�һ���Ƿ�Ϊ0

        int n1=num1.size(),n2=num2.size();

        vector<int> res(n1+n2,0);//������
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int t=(num1[i]-'0')*(num2[j]-'0');
                res[i+j+1]+=(t%10);//�����֮����ܴ��ڽ�λ����Ҫ����
                res[i+j]+=(res[i+j+1]/10);
                res[i+j+1]%=10;

                res[i+j]+=(t/10);//ǰһλӦ��û��ô����ֽ�λ����һ��ѭ�����ٴ���
            }
        }
        int start=0;
        if(res[0]==0)start++;
        string s;
        for(int i=start;i<n1+n2;i++){
            s.push_back(res[i]+'0');
        }
        return s;
    }
};
int main(){

    return 0;
}
