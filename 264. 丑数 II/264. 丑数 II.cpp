#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-15
/*
1.�о��е��ѣ�����ôȥ�����أ�����˵��������
1��1*2��1*3��1*5��2*2�������ô���ж��أ���Ĳ�֪������жϴ�С�ˣ�������
2.�ֶ���һ�£�
1,2
i2=1,i3=0,i5=0
min(4,3,5)
1,2,3
i2=1,i3=1,i5=0
min(4,6,5)
1,2,3,4
i2=2,i3=1,i5=0
min(6,6,5)
1,2,3,4,5
�ֶ��ܵ�������grand�Ľⷨ��
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};
�����е��Ѷȵģ���Ҫ��ϰ
*/
//10-22
//�ǽ�ָoffer�ĵ�49�⡣�������Ҵ���Ľ�����̣�
//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        if(n==1)return 1;
//        int k=1,k2=1,k3=1,k5=1;
//        int ans=1;
//        while(k<n){
//            int t=min(k2*2,min(k3*3,k5*5));//������ô�㣬��ô�������ظ�����������
//
//            ans=t;
//            cout<<k<<" "<<ans<<endl;
//            //1 2
//            //2 3
//            //3 4
//            //4 5
//            //5 6//��Ϊ3*2��2*3����6�����Ի���2��6.������
//            //6 6
//            //7 8
//            //8 9
//            //9 10
//            //10
//            if(t==k2*2)k2++;
//            if(t==k3*3) k3++;//�����Ϊif����else ifҲ�ǲ��Եģ����11����ʱ��
//            //14����14�����ǳ���������Ϊ14=2*7�����14����ô�õ��ģ���һ��ʼ������ˡ�
//            //���������ǵ�������++*2/3/5�Ϳ��Եģ�����Ҫ�������ɵĳ���*2/3/5�õ���Сֵ��
//            if(t==k5*5) k5++;
//            k++;
//        }
//        return ans;
//    }
//};

//10-23
/*
1.�Ҽǵ��и�˼·����Ϊn�����˷�Χ��������1690�����Կ����Ƚ����еĶ�����������ֵ�ʹ�ó�������
  Ƶ�����õ�ʱ������ֱ�ӷ��ʹ�ϣ���Ϳ����ˡ�
*/
class Solution1 {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> v={1};
        int k2=0,k3=0,k5=0;
        for(int i=1;i<n;i++){
            int t=min(v[k2]*2,min(v[k3]*3,v[k5]*5));//Ҳֻ��
            if(t==v[k2]*2)k2++;
            if(t==v[k3]*3)k3++;
            if(t==v[k5]*5)k5++;
            v.push_back(t);
        }
        return v[n-1];
}};
/*
2.YesAC��
3.�ٷ����Ĳο�����ʱ�临�Ӷ���O(1)ʱ������𰸺ʹ�Լ 1690 \times 5 = 84501690��5=8450 �ε�Ԥ���������
  �����ռ��ñ��� 1690 ��������
4.���ǿ�����������˵���ֽ��浽������⣬���Ҿ�Ҫ�����Ǹ��ѵĽⷨ�ˡ�ʹ�öѵĻ�������һ��ȥ�صĹ��̣�����дһ�¡�
  C++�еĶѾ������ȶ��С�
*/

//10-24
/*
1.����ʹ�ö�����⡣
*/
class Solution2 {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;
        pq.push(1);
        long ans,k=0;
        while(k<n){
            long t=pq.top();pq.pop();//����Ҫ��Ϊlong������int�������
            while(!pq.empty()&&t==pq.top())pq.pop();//����Ҫ�ж��Ƿ�Ϊ�գ��������ѭ����
            ans=t;
            pq.push(t*2);
            pq.push(t*3);
            pq.push(t*5);
            k++;

        }
        return ans;
    }
};

//10-29��ϰ
/*
 * 1.��θ�ϰ��ʱ���Ȼ�뵽��һ�ֽⷨ����ôȥ�ص��أ��Ǿ�Ӧ����ÿ���ж϶���if��������if else������2*3
 *   ��3*2���µ�6�ͻ�ֻ�Ž���һ�Σ�����һ�¡����������ģ�t2=3ʱ��t3=2ʱ������6����Ӧ���±궼++��
 *2.���Ӷȣ�O(1) ʱ������𰸺ʹ�Լ1690��5=8450 �ε�Ԥ���������
 *  �����ռ��ñ��� 1690 ��������
 * */

//5-26
class Solution {
public:
    int nthUglyNumber(int n) {
        //p2ָ����һ��*2�ĳ���,p3,p5Ҳ��������
        int p2=0,p3=0,p5=0;
        vector<int> ans={1};
        while(--n){
            int t=min(min(ans[p2]*2,ans[p3]*3),ans[p5]*5);
            // if(t==ans[p2]*2)
            //     p2++;
            // else if(t==ans[p3]*3)//��Ϊ���ܴ����ظ����֣�����Ҫelse
            //     p3++;
            // else p5++;//2 3 4 5 6 6 8 9 10
            if(t==ans[p2]*2)p2++;
            if(t==ans[p3]*3)p3++;
            if(t==ans[p5]*5)p5++;
            ans.push_back(t);
           // cout<<t<<" ";
        }
        return ans.back();
    }
};
/*
 * 1.��ʵ���Ǿ��˰�����������������������������⣬�Ҿ�Ȼ����������˵�������ظ����֣�����Ҫ��else
 *   �ҵ��죬��֮ǰ����������Ⱑ���ҵ�����˰����ҿ��ˡ������Ŷ��������Թ٣���ͦ���µģ��Ͳ��Ҷ�˼��
 *   �ⲻ�а����ö���Ӧ����ȥ�������Ⱑ��
 * */
int main(){
    Solution2 s;
    cout<<s.nthUglyNumber(10);
    return 0;
}
