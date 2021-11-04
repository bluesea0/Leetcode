#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月16日上午1:04:43
vector<long long> toVector(string& mask){
	int index=0;
	//if(mask.back()=='.')return {};//如果最后以.结尾，直接返回空。
	mask+=".";
	vector<long long> res;
	while(mask.find(".",index)!=string::npos){
		int t=mask.find(".",index);
		res.push_back(stoi(mask.substr(index,t-index)));
		index=t+1;
	}
	return res;
}
int main(){
	string ip;
	long long ip4;
	while(cin>>ip>>ip4){
//		vector<int> nums=toVector(ip);
//		long long res=0;
//		res=(nums[0]<<24)+(nums[1]<<16)+(nums[2]<<8)+nums[3];
//		234.237.37.104，上面的输入针对移动之后<<24位会产生溢出，我的妈啊。
		//所以通过上面这个样例输出为-353557144，整个就是负数。
		//所以单个的数要左移24位，仍然要定位它本身为long long型的。
		vector<long long> nums=toVector(ip);//全都变为long long之后就ok了。
		long long res=0;
		res=(nums[0]<<24)+(nums[1]<<16)+(nums[2]<<8)+nums[3];
//		string str;
//		str+=to_string(ip4>>24);
//		str+=".";
//		str+=to_string((ip4>>16)&255);
//		str+=".";
//		str+=to_string((ip4>>8)&255);
//		str+=".";
//		str+=to_string(ip4&255);
		int a1=ip4>>24;
		int a2=(ip4>>16)&255;
		int a3=(ip4>>8)&255;
		int a4=ip4&255;
		cout<<res<<"\n"<<a1<<"."<<a2<<"."<<a3<<"."<<a4<<endl;
	}
    return 0;
}
