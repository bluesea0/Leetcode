#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��23������4:21:52
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        //˼·�����ʾ���һ���ϲ���������⣬��ȥ��������ʵҲ���ǵ���������ϲ�������Ҫ���̰��
//        //�е��Ѷȡ������ҿ��Կ�ʼ���н�����䷽��������ˡ�
//        //��ôdp[i]��Ҫ��i-1�Ƚϣ�ҲҪ��i-2�Ƚϣ�����Ҫ��i֮ǰ���еıȽϣ��Ǿ���O(n2)
//        //�ȽϺ�֮ǰ�Ƿ����ص�
//    }
//};
//̫���ˣ�ʵ�����ѣ��Ҳ��ᣬ��Ȼ�������֮���ƺ������ˡ�

//11-24
class Solution {
public:
	//�����������Ҫд��const������Ϊʲô�أ���֮ǰ������
    static bool cmp(vector<int>a,vector<int>b){//�������д��̫���˰�
        if(a[1]<b[1])return true;
        else if(a[1]==b[1]&&a[0]<b[0])return true;//�Ҷ˵���ͬ����˵�ԽС˵�����Խ��
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        //����ĺ���Ҳ̫��д�ˡ�����
        sort(points.begin(),points.end(),cmp);
        int ans=1,coor=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>coor){
                coor=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
/*
 * 1.�ύʱ��Ϊcmp����static�ģ����Գ�����һ�����⡣
 * 2.ʱ����O(nlogn)����ģ��ռ�O(logn)���������ջ�ռ䡣���������Ǻ����������Ĺ��̣��ܾ�������
 *   O(n),O(1)�������ǹ��ˡ�
 * 3.�����������������ʵֻ��ע�ұ߽缴�ɣ�����[1,2],[3,4],[1,4]�����Ų��ŵ�һ���𰸶���2.
 *   ����ȥ��֮���ύ��Ҳû����١�
 * 4.˼·��̰���㷨���ֲ����Ž����ȫ�����Ž⡣
 * */

//12-19
/*
 * 1.�Ҿ��ˣ�����25��Ÿ�ϰ����ȫ�����˵�ʱ����ôд���ˡ�
 * https://www.cnblogs.com/grandyang/p/6050562.html��grand�����̰��˼·�͹ٷ��Ĳ�һ��������Ҳ�ܲ���
 * */

//12-20
class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //����ǵ�ѧϰһ������������ôд
        if(points.size()==0)return 0;
        sort(points.begin(),points.end());//�����ǲ��ǲ���д���Ҽǵ��ǻ��Զ��й��������
        int end=points[0][1];
        int ans=1;
        for(auto p:points){
            if(p[0]>end){
                end=p[1];
                ans++;
            }else end=min(end,p[1]);//����ͱ�ʾҪ���ð������Ծ͵�ȡ��Сֵ
            //����������[[10,16],[2,8],[1,6],[7,12]]
            //�����[7,12] [10,16] .����Ҫ��12���������еĽ�Сֵ��
        }
        return ans;
    }
};//ohyes��AC�ˣ����ģ������grand��˼·
//���Ӷȣ�O(nlogn)���ģ�������Ϊ��O(n)���������ֺ��������򣡿ռ�O(logn)
/*
 * 1.sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
	����������ôд��
	[]��Ҫ�����洫������
	()�����β�
	{}�����壬���Ҳ��Ҫ�Ӹ��ֺ�
 * */
int main(){

    return 0;
}
