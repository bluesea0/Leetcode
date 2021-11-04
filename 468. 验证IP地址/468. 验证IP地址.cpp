#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月17日下午7:58:59
class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPv4(IP))return "IPv4";
        if(isIPv6(IP))return "IPv6";
        return "Neither";
    }
    bool isIPv4(string ip){
        if(ip.back()=='.')return false;
        ip+=".";
        int index=0,count=0;
        while(ip.find(".",index)!=string::npos){
            int t=ip.find(".",index);
            if(t==index)return false;//可能会有连续两个.
            string s=ip.substr(index,t-index);
            if(s.size()>3)return false;
            for(auto& ch:s)//如果不全是数字的话返回false；
                if(isdigit(ch)==false)return false;
            if(s.size()>1&&s[0]=='0')return false;//首部0
            if(stoi(s)>255)return false;
            count++;
            index=t+1;
        }
        if(count!=4)return false;
        return true;
    }
    bool isIPv6(string ip){
        if(ip.back()==':')return false;
        ip+=":";
        int index=0,count=0;
        while(ip.find(":",index)!=string::npos){
            int t=ip.find(":",index);
            if(t==index)return false;
            string s=ip.substr(index,t-index);
            //cout<<s<<"\n";
            if(s.size()>4)return false;
            for(auto& ch:s){
                if(isalpha(ch)){
                    if(tolower(ch)>'f')return false;//十六进制中F表示15！！！
                }
            }
            index=t+1;
            count++;
        }
        //cout<<count<<"\n";
        if(count!=8)return false;
        return true;
    }
};
int main(){
	string s;
	cin>>s;
	Solution su;
	cout<<su.validIPAddress(s);
    return 0;
}// 2001:0db8:85a3:0:0:8A2E:0370:7334
