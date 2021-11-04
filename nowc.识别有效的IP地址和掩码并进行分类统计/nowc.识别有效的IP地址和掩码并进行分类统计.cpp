#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
//2021��10��15������11:44:28
vector<int> toVector(string& mask){
	int index=0;
	if(mask.back()=='.')return {};//��������.��β��ֱ�ӷ��ؿա�
	mask+=".";
	vector<int> res;
	while(mask.find(".",index)!=string::npos){//���ģ�������find������һ��������const string & str����
		//�ڶ�����������pos��λ�ã�������ô���ǣ�find��Ҫ�����ǲ����ַ�������ô�ַ���������Ҫ�Ĳ�����pos��Ĭ��Ϊ0�ģ�
		int t=mask.find(".",index);
		if(t==index)break;
		res.push_back(stoi(mask.substr(index,t-index)));
		index=t+1;
	}
	return res;
}
unordered_set<int> st={254,252,248,240,224,192,128,0};
bool isValidMask(string& mask){
	vector<int> mk=toVector(mask);
	if(mk.size()!=4)return false;
	if(mk[0]==255){
		if(mk[1]==255){
			if(mk[2]==255){
				if(st.count(mk[3]))return true;
				else return false;
			}else{
				if(st.count(mk[2])&&mk[3]==0)return true;
				else return false;
			}
		}else {
			if(st.count(mk[1])&&mk[2]==0&&mk[3]==0)return true;
			else return false;
		}
	}else{
		if(st.count(mk[0])&&mk[1]==0&&mk[2]==0&&mk[3]==0)return true;
		else return false;
	}
	return false;
}
/*

���е�IP��ַ����Ϊ A,B,C,D,E����

A���ַ1.0.0.0~126.255.255.255;

B���ַ128.0.0.0~191.255.255.255;

C���ַ192.0.0.0~223.255.255.255;

D���ַ224.0.0.0~239.255.255.255��

E���ַ240.0.0.0~255.255.255.255

˽��IP��Χ�ǣ�
10.0.0.0/8  10.������λ����255��255��255�ķ�Χ�ˡ�
10.0.0.0-10.255.255.255

172.16.0.0/12   �ڶ�����ֻ�к���λ�ܱ仯�����������15+16=31.
172.16.0.0-172.31.255.255

192.168.0.0/16 ֻ�ܺ���16λ�����仯��
192.168.0.0-192.168.255.255
 * */
int main(){
	string str;
	vector<int> res(7,0);
	while(cin>>str){
		int p=str.find("~");
		string ip=str.substr(0,p);
		string mask=str.substr(p+1);
//		cout<<ip<<" "<<mask<<"\n";
		vector<int> ip4=toVector(ip);
		if(ip4[0]==0||ip4[0]==127)continue;
		/*
		 * �����ڡ�0.*.*.*���͡�127.*.*.*��
		 * ��IP��ַ�������������������һ�࣬Ҳ�����ڲ��Ϸ�ip��ַ������ʱ�����
		 * */
		if(!isValidMask(mask)){
			res[5]++;continue;
		}

		if(ip4.size()!=4){
			res[5]++;continue;
		}
		if(ip4[0]>=1&&ip4[0]<=126){
			res[0]++;
			if(ip4[0]==10)res[6]++;
		}else if(ip4[0]>=128&&ip4[0]<=191){
			res[1]++;
			if(ip4[0]==172&&ip4[1]>=16&&ip4[1]<=31)
				res[6]++;
		}else if(ip4[0]>=192&&ip4[0]<=223){
			res[2]++;
			if(ip4[0]==192&&ip4[1]==168)
				res[6]++;
		}else if(ip4[0]>=224&&ip4[0]<=239){
			res[3]++;
		}else if(ip4[0]>=240&&ip4[0]<=255)
			res[4]++;
	}
	for(int i=0;i<7;i++){
		cout<<res[i]<<" ";
	}
    return 0;
}
