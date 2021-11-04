#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��12������10:59:32
//class Solution {
//public:
//    vector<int> sortArrayByParityII(vector<int>& A) {
//        //˼·����λ˫ָ�����
//        int i=0,j=A.size()-1;
//        while(i<j){
//            while(i<j&&((i%2==0&&A[i]%2==0)||(i%2==1&&A[i]%2==1)))i++;
//            while(i<j&&((j%2==0&&A[j]%2==0)||(j%2==1&&A[j]%2==1)))j--;
//            swap(A[i],A[j]);
//            i--;j--;
//        }
//        return A;
//    }
//};
/*
 * 1.[2,3,1,1,4,0,0,4,3,3],��ʱ�ˡ�����Ϊi=2ָ����1��j=8ָ����3����ô����λ�ͻ�һֱ������������
 *   ���easy�����һ���Ϊ���ܺܿ����ء���û�뵽��Ϳ�ס�ˣ�������
 *   ����������˼·���Ǵ���ˣ��ҿ�������ˡ�����û��˼·�ˣ����ֱ�Ű�ˡ�
 * 2.���˹ٷ��Ľⷨhttps://leetcode-cn.com/problems/sort-array-by-parity-ii/solution/an-qi-ou-pai-xu-shu-zu-ii-by-leetcode-solution/
 *   ţţţ��������⣬������ʱ��Ҫ�����Թ��Ƿ�����޸�A���������������ô��ԭ���޸ģ�����Ļ���
 *   �½�һ�����������ˡ�iָ��ż����λ�ã�jָ��������λ�ã����˾��ˡ�
 * */

//11-13
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        //˼·��ά��ָ������λ�ú�ż��λ�õ�������
        //��A���Ա��޸ĵ�����¡�
        int j=1;
        for(int i=0;i<A.size();i+=2){//�ж�ż��λ�Ƿ�����
            if(A[i]%2!=0){//��Ҫ��jָ���λ�ý���
                while(A[j]%2&&j<A.size())j+=2;
                swap(A[i],A[j]);
            }
        }
        return A;
    }
};
/*
 * 1.���������˼·AC�����ڡ���ʵд��ʱ���ǲ���Ϥ���е��㱵ġ���Ҫ��ϰ�ġ�
 * */

//11-25
/*
 * 1.��θ�ϰ��ֱ��������ôд�ˣ�ֻ�ǵ�һ��ָ��ż��λ�ã�һ��ָ������λ�ã����������whileǶ������
 *   ƽ�е�forѭ�����������ˡ�����
 * */

//12-20
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j=1;//��ȥ�������е��°�����֪����δ������ҵ���
        for(int i=0;i<A.size();i+=2){
            if(A[i]%2==0)continue;
            while(j<A.size()&&A[j]%2==1)j+=2;
            swap(A[i],A[j]);
        }
        return A;
    }
};
/*
 * 1.������Ŷ��AC�ˣ�O(n) O(1)�ɡ�
 * */
int main(){
	Solution s;
	vector<int> a={2,3,1,1,4,0,0,4,3,3};
	vector<int> ret=s.sortArrayByParityII(a);
	for(auto aa:ret)
		cout<<aa<<" ";
    return 0;
}
