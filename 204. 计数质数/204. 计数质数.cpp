#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��3������11:59:08
//class Solution {
//public:
//    int countPrimes(int n) {
//        //������ʲô�������ѵ���Ҫ��2-nһ��һ��ȥ�жϣ����ҿ϶���ʱ�˰ɣ������ԡ�
//        //��1->����n�Ϳ�����
//        if(n==0||n==1||n==2) return 0;//ע�Ⱑn==2��ʱ����С�ڣ�û�е��ڣ����Է���0.
//int ans = 0;//�ٷ�д�Ĺ��̡�6������������жϺö��ˡ�
//for (int i = 2; i < n; ++i) {
//    ans += isPrime(i);
//}
//        int ans=1;
//        for(int i=3;i<n;i++)
//            if(helper(i))
//                ans++;
//        return ans;
//    }
//    bool helper(int n){
//        for(int i=2;i<=int(sqrt(n))+1;i++)//����ı߽�������Ĳ�ȷ������
//            if(n%i==0)//����7��˵������=Ӧ�ü��ϣ�
//                return false;
//        return true;
//    }//1500000����ʱ�ˡ��ҿޡ�
//};
/*
 * 1.n�����5 * 10^6�����泬ʱ��������1.5*10^6������Զ�ء���ʱ�临�Ӷ�ΪO(n����n)
 * 2.�ٷ�����еı���ö�ٶ�����ǿ��
 *     bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {����ֱ�Ӿ�û����sqrt���ߣ�ʵ���Ǹ߰���
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }//���μ�鸴�Ӷ�ΪO(����n)
    3.����ɸ������Ŀ���������ʲɸ����������⡣
 * */

//12-9
class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        for(int x=2;x<n;x++){
            if(isp(x)){
            	ans++;
            	cout<<x<<endl;
            }
        }
        return ans;
    }
    bool isp(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
};
/*
 * 1.���չٷ��ı����ⷨ����ȻAC�ˣ�����������Ƿ�ʱ�䰡������дһ�°���ɸ��
 *   �����㷨�Ѿ�ѧ������Сʱ�ˣ�ûʱ���ˣ��ÿ�������ѽ����
 * */

//12-10
class Solution1 {
public:
    int countPrimes(int n) {
        vector<int> p(n,1);
        int ans=0;
        for(int i=2;i<n;i++){
            if(p[i]){
                ans++;
                if((long long)i*i<n){//����һ����Ҫ�����жϣ��������forѭ������j��long longҲ����
                    for(long long j=i*i;j<n;j+=i)//���ﲻӦ�ô�2*i��ʼ��ǣ�Ӧ�ô�
                //runtime error: signed integer overflow: 46349 * 46349 cannot be represented in type 'int' (solution.cpp)
                        p[j]=0;
                }
            }
        }
        return ans;
    }
};
/*
 * 1.��������AC�ˣ�����ɸ��Ҫ��x*x��ʼ��ǣ���Ϊ2*x��Щ�϶�2���Ѿ���ǹ��ˣ�
 * 2.           for (int j = i + i; j < n; j += i) {//�����������д�������Ⱑ��Ӧ����i*i
                //�ų�������������   //�ǻ���Ӧ�ÿ��ǵ���������⡣
                signs[j] = false;
            }
    ����Ϊɶ�˼���ôд�Ͷԣ��˼�Ҳ�õ�int��������longlong�����У�
   3.�Ժ�����int��������Ļ��������жϣ�����������һ����Ӧ�Ķ���ֱ������ʱ����������������
   	   if((long long)i*i<n)���жϣ��ͷǳ����ˣ�
 * */
int main(){
	Solution1 s;
	cout<<s.countPrimes(499979);
    return 0;
}
