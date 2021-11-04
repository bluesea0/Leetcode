#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��7������3:00:40
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //�ȹ������������飬��ʾÿ����֮ǰ�ĳ˻������Ȼ���ٹ��������ǣ������õ����
        if(a.empty())return {};
        vector<int> b(a.size(),0);
        b[0]=1;//0֮ǰԪ�صĳ˻�
        for(int i=1;i<b.size();i++)
            b[i]=b[i-1]*a[i-1];
        int t=a.back();//��Ҫ��һ��ֵ���ۼƼ�¼�İ���
        for(int i=b.size()-2;i>=0;i--){
            b[i]*=t;
            t*=a[i];
        }
        return b;
    }
};
/*
 * 1.Ҳ�ǿ������֮��������ˡ�
 * */

//6-18
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //B[i]��ʾ�������
        //�������ʱ���㵱ǰ��i��ߵĳ˻�����������ٽ��ұߵĳ˻��˽���
        int n=a.size();
        vector<int> B(n,1);
        for(int i=1;i<n;i++)
            B[i]=B[i-1]*a[i-1];
        int temp=1;
        for(int i=n-1;i>=0;i--){
            B[i]*=temp;
            temp*=a[i];
        }
        return B;
    }
};
/*
 * 1.��˹д�����ˣ���Ҫ�ǵ�һ�α���ʱB[i]��������ߵĵ�i-1���������Ľ���������������ʱ���ٳ��Ե�ǰ��
 *   �ұߵĳ˻���
 * */
int main(){
	Solutoin s;
	s.constructArr();
    return 0;
}
