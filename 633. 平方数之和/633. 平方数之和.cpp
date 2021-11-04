#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
//2020��12��3������3:48:09
//class Solution {
//public:
//    bool judgeSquareSum(int c) {
//        int i=0,j=int(sqrt(c));//�����������룬�ǽ�С���㲿�ֶ�ȥ��
//        //��math.hͷ�ļ���
//        while(i<=j){
//        	cout<<i<<" "<<j<<" ";
//            int s=i*i+j*j;//2147482647����������ˣ�
//            cout<<s<<endl;
//            //����c��������int��ʾ��Ϊʲôs����������أ�
//            if(s==c)return true;
//            else if(s<c) i++;
//            else j--;
//            if(i==5)break;
//        }
//        return false;
//    }
//};//���ۣ���Ϊeasy����Ŀ����ȽϺý���أ�û�뵽�����е������ˡ�
//����ʹ��˫ָ���˼�룬s�ĵط�����ˣ���������

//12-6
class Solution {
public:
    bool judgeSquareSum(int c) {
    	for(long long a=0;a*a<=c;a++){//ע������Ҫ��=�ŵİ�����㡣
    		double b=sqrt(c-a*a);
    		if(b==int(b))//��Ȼ������ô���ж�int��doubleʱ�Ƿ���ͬ����
    			return true;
    	}
    	return false;
    }
};
/*
 * 1.��Ҫע����ǣ�a��long long���͵ģ�forѭ����=�š�ʱ��O(n^2)��
 * 2.��������ͬ��Ҳ�ᵽ����Ϊ���������Ҫ�޸Ĵ�����������ô���޸�һ�¡�
 * */
class Solution2 {
public:
   bool judgeSquareSum(int c) {
       int i=0,j=sqrt(c);//�ڶ���j������ʱ���Ѿ�Ĭ��ǿ��ת���ˣ��Ͳ�������ʾ��ת����
       //��math.hͷ�ļ���
       while(i<=j){
           if(i*i==c-j*j)return true;
           else if(i*i<c-j*j) i++;
           else j--;
       }
       return false;
   }
};
//�޸���֮����AC�ˣ������ӡ�ʱ�临�Ӷ���ʵҲ��O(����c)��
int main(){
	Solution s;
	cout<<s.judgeSquareSum(2147482647);
    return 0;
}
