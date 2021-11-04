#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��9������1:35:23
class Solution {
public:
	//ʱ��O(nlogn)���ռ�O(logn)��������Ķ���ռ䡣
    static bool comp(const vector<int>& a,const vector<int>& b){//����Ҫ�����ã�������ֵ���ƵĹ���
        return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];//�ᵼ�³�ʱ!
    }//����Ҫʹ��static���β��о�û��thisָ���ˡ�
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //����һ���������Ŀ��������дsort���������
        sort(points.begin(),points.end(),comp);
        // vector<vector<int>> ans;//��ʵ��ô����Ҳû����
        // for(int i=0;i<K;i++)
        //     ans.push_back(points[i]);
        // return ans;
        return {points.begin(),points.begin()+K};//ԭ��������ô����
    }
};
/*
 * 1.AC�ˣ�����������һ���ӣ����ύ�����ζ��ǳ�ʱ��comp�в��������þͻᳬʱ��
 * 2.��Ȼ���������Ľⷨ���Ҽǵ����������Ƶ���Ŀ�����������˼�룬����Ҿ����������ģ�
 * 3.���ȶ��У�����һ���̫�С�
 * 4.������дһ�¡�
 * 5.�۰�Ŷ������ҲAC�ˣ���Ȼд�ĺ������ɣ����Ǿ͸о�����Ҳ������·��ѽ����дд��
 * */
class Solution {
public:
    // ʱ�䣺����Ϊ O(n)��� O(n^2)���ռ�:����ΪO(logn), O(n).�����ڻ���n-1��ʱ�ﵽ��
    void quick(vector<vector<int>>& points,int left,int r){
        if(left>=r)return;//���ﵽ����û��=��
        int i=left,j=r;
        vector<int> k=points[i];
        while(i<j){//�еȺ���Ӧ���У�Ҫ��Ȼ���жϲ���i��j��ָ����ˡ�
            while(i<j&&(pow(points[j][0],2)+pow(points[j][1],2)>pow(k[0],2)+pow(k[1],2))) j--;//�ؼ�������ǴӺ���ǰ�߰���
            while(i<j&&(pow(points[i][0],2)+pow(points[i][1],2)<=pow(k[0],2)+pow(k[1],2))) i++;
            //����i/j
            //�������i==j�ˣ�����Ľ����Ϳ��ܲ���Խ�硣����
            swap(points[i][0],points[j][0]);
            swap(points[i][1],points[j][1]);
        }
        //�˳�ʱӦ����i==j
        // points[i][0]=k[0];
        // points[i][1]=k[1];
        swap(points[i][0],points[left][0]);//������ĸı�Ĳ������ã�
        swap(points[i][1],points[left][1]);
        quick(points,left,i-1);
        quick(points,i+1,r);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //���ÿ��ŵ�˼��
        //��ʵ���е㺦�£�����ûд�ɹ����š�����
        //����дһ����������Ϊ��Ҫ�ݹ�İ�
        quick(points,0,points.size()-1);
        return {points.begin(),points.begin()+K};
    }
};//�´θ�ϰҪдһ�������ȶ��еģ�Ҳ���Ƕѡ�
//����뽣ָoffer40��С��k������46�����鷭��Ϊ��С�������������ƣ�
int main(){

    return 0;
}
