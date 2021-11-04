#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��5������11:28:09
/*
 * 1.�����ʵ���Ǻ��ѣ�������Ϊ�Ƕ����������Ĺ鲢����ô����Ҫ�õ�С���ѣ�����Ҫ�Լ��������ݽṹ
 *   �����ݽṹ�ع�> ��greater��������ͦ�ѵģ������Ҫ�������������ֻ���õ���ÿ���������������ʡ�
 * 2.�����ö��ַ���ʱ��l��r����С�����ֵ��Ȼ������½ǿ�ʼ���𣬼���С�ڵ���mid�����еĸ���x����k
 *   �Ƚϴ�С������l��r������ָ�����x>k�Ļ���ôr=mid������l=mid��ѧϰ�ˡ�
 * */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //ʹ�ù鲢����ķ������������ȼ����й���С����
        struct num{
            int val,i,j;
            num(int val,int i,int j):val(val),i(i),j(j){}
            bool operator> (const num& a)const {return this->val>a.val;}
            //����Ƚϵ�ʱ��a��ǰ����this��ǰ��
            //�ٷ�Ҳд��this����ߣ�����Ϊ�ǽ�this��Ϊ��ֵ�ˣ�����i++
        };
        priority_queue<num,vector<num>,greater<num>> pq;
        for(int i=0;i<matrix.size();i++)
            //pq.emplace_back(matrix[i][0],i,0);//pq�����ȼ����а�
            //pq.push(matrix[i][0],i,0);
            pq.push(num(matrix[i][0],i,0));//ԭ����emplace��
        for(int i=0;i<k-1;i++){
            num t=pq.top();
            pq.pop();
            if(t.j+1<matrix[0].size())
                //pq.emplace_back(matrix[t.i][t.j+1].val,t.i,t.j+1);
                //pq.push(matrix[t.i][t.j+1].val,t.i,t.j+1);
                pq.push(num(matrix[t.i][t.j+1],t.i,t.j+1));
        }
        return pq.top().val;
    }
};
/*
 * 1.������Щ���⣬����ʹ��STLʱ�Լ���д������ʱgreater��lessʱ�Ľ����
 *   lamda��дcmp��Ҫ��const������T��ָ���򲻼ӣ�
 * */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //���ֵĽⷨ
        //̫���ˣ��ѵ�ͷ��ð�͵ĸо�
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=l+((r-l)>>1);
            int ct=kth(matrix,mid);
            //��ʵ�൱��һ��Ѱ����߽�Ķ��֣����ǣ���ʵ��Ѱ���ұ߽�Ķ��֣�
            // if(ct==k){
            //     //l=mid;break;//���ﲻ��=mid����Ϊmid��һ���Ǿ����е�����
            // }else if(ct<k){
            //     l=mid+1;
            // }else r=mid-1;//��Ϊwhile��������<û��=�ţ�����
            if(ct<k)//��ôд���ǲ��ԣ���������ָ���ô�찡��
                l=mid+1;
            else r=mid;
        }
        return l;
    }
    int kth(vector<vector<int>>& matrix,int mid){
        int n=matrix.size();
        int i=n-1,j=0,ct=0;
        while(i>=0&&j<n){
            if(matrix[i][j]<=mid){
                ct+=i+1;
                j++;
            }else i--;
        }
        return ct;
    }
};
/*
 * 1.���ֵĽⷨ��ͦ��д�ģ���Ҫ��ϰͨʶ�Ķ�����ôд��
 * 2.��Ը����������ڼ���������У�l=13,r=15,mid=14,ct=8����ô��ʱ���ֵ������ǣ���Ȼk==ct�������㷵��
 *   �ĸ���һ��˵��ֱ�ӷ���mid������mid��һ�������ھ����У�Ҳ����ֱ�ӷ���l��l�ڱ�������п��ܲ��Ǵ�
 *   �������������ʵͦ��д�ġ�
 * */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //���ֵĽⷨ
        //̫���ˣ��ѵ�ͷ��ð�͵ĸо�
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<=r){
            int mid=l+((r-l)>>1);
            int ct=kth(matrix,mid);
            if(ct<k)
                l=mid+1;
            else if(ct>k){
                r=mid-1;
            }else r=mid-1;//���дr=mid��������������ѭ����
        }
        return l;//����Ҳ��l
    }
    int kth(vector<vector<int>>& matrix,int mid){
        int n=matrix.size();
        int i=n-1,j=0,ct=0;
        while(i>=0&&j<n){
            if(matrix[i][j]<=mid){
                ct+=i+1;
                j++;
            }else i--;
        }
        return ct;
    }
};
/*
 * 1.�������������ҵĸ�ϰ��������д��������������Ϊ���˱յ�[]��һ��Ҫע��һ��Ҫע��д��ʱ���Լ�
 *   ����Ϥ�Ķ��֣�< > =һ��Ҫ��������֧���жϣ���Ҫ��=����><�ϲ������������˼·����ǳ����µģ�
 * */
int main(){

    return 0;
}
