#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��16������1:04:43
vector<long long> toVector(string& mask){
	int index=0;
	//if(mask.back()=='.')return {};//��������.��β��ֱ�ӷ��ؿա�
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
//		234.237.37.104���������������ƶ�֮��<<24λ�����������ҵ��谡��
		//����ͨ����������������Ϊ-353557144���������Ǹ�����
		//���Ե�������Ҫ����24λ����ȻҪ��λ������Ϊlong long�͵ġ�
		vector<long long> nums=toVector(ip);//ȫ����Ϊlong long֮���ok�ˡ�
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
