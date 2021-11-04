#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-13
/*
1.��Ӧ��ָoffer�е�44�⣬��������������Ĵ𰸱ȽϺá�
https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/

*/
class Solution {
public:
    int findNthDigit(int n) {
        long int start=1,len=1;//�����ʱ����Ҫ������ȫ����Ϊlong int��
        long int ct=9;//ע��ct����һ���ۻ������������len���ж���λ��
        while(n>ct){
            n-=ct;
            start*=10;
            len++;
            ct=9*start*len;
        }
        string num=to_string(start+(n-1)/len);//�Բۣ�����±�Ҫ���Ҹ�����!
        //���Ե���n-1�������������˾��ˡ�
        return num[(n-1)%len]-'0';//�������ôд�أ��Һ�Ȼ�Ի��ˡ�
    }
};
//10-17
/*
1.�ؼ��ĵ��ǣ�ct��θ��¡����ó���Ӧ�����ת��Ϊ��nλ�����֡�
*/
class Solution {
public:
    int findNthDigit(int n) {
        //int nums=10,digit=1,start=0;
        long long nums=10,digit=1,start=0;
        while(n>=nums){
            n-=nums;
            //start=10*digit;//���������˰���Ӧ����*10����
            //start*=10;
            start=(start==0?10:start*10);
            digit++;
            nums=9*start*digit;
            //nums=9*start;//����ط�Ҳ�����ˣ���������������������λ��������������
            //���ģ�������ô���°���������������Ļ��㲻�ͣ����������ӡ�ʲô˼·����
        }
        //int s=start+n/digit;
        long long s=start+n/digit;
        return to_string(s)[n%digit]-'0';
    }
};//1000000000����ˣ����Ը�Ϊlong long�ɡ�
/*
 * 1.Yes!��ҲAC�ˣ��Һÿ��ģ����������50���Ӳ��Լ��������
 * 2.nums��¼������λ���ַ������������ǵ�ǰ�������ж��ٸ�������Ҫ����digit���У�digit���ں���ļ�������
 *   λ�õģ�start��ÿ��*10����Ϊ����и����Ǵ�1��ʼ������Ȼ����������ʱ��Ҫn-1�������Ҵ�0��ʼ�Ͷ�
 *   ����һ��������whileѭ���ж�ʱ��=�ţ����Դ��ڲ�ͬ���ҾͲ����ڽ��������-1�ˡ�
 *   ����start�ĸ���Ҫע�⣬��Ϊ�ҳ�ʼ��Ϊ��0�������ڲ�Ҫ�жϣ����ܼ򵥵�=*10�ˣ�����ѭ���ˡ�
 * */
int main(){
    Solution2 s;
    cout<<s.findNthDigit(1000);
    return 0;
}
