#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;
//2021��10��31������11:50:10
class Solution {
public:
    string decodeString(string s) {
        if(s.empty())return s;
        stack<string> stk;//Ӧ�ô洢�ַ����ģ���Ϊƴ��֮����ȻҪ�Ž����ġ�
        int n=s.size();
        if(n<4)return s;
        for(int i=0;i<n;i++){
            if(s[i]!=']')stk.push(string(1,s[i]));//ɵ�����˰��ַ���ӽ����ˡ���
            //��ʼ��ʱ�����������⣺
            /*
            ����ַ���ֻ����һ���ַ���ʹ�ù��캯�������ʼ��ʱ��ʹ������������ʽ�ȽϺ���
            std::string s('x');    //����
            std::string s(1, 'x');    //��ȷ
            */
            else{
                //����������
                string str="",num="";
                while(!stk.empty()&&stk.top()!="["){
                    str=stk.top()+str;
                    stk.pop();
                }
                stk.pop();
                while(!stk.empty()&&isdigit(stk.top()[0])){
                    num=stk.top()+num;
                    stk.pop();
                }//����ֱ��+=��Ȼ��reverse����Ϊ�п������ڲ�ƴ��ѽ�����ģ������𣡣�
                //һ����һ��ģ�������ת�ʹ��ˣ��㻹�Ǳ�����ˣ���ֱ�Ӻ�Ӿ��С�����
                int c=stoi(num);
                string res="";
                while(c--)res+=str;
                stk.push(res);
            }
        }
        //�ٱ���stack
        string ret="";
        while(!stk.empty()){
            ret=stk.top()+ret;
            stk.pop();
        }
        //reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
	Solution s;
	cout<<s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}
