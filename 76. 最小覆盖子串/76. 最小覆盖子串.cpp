#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��16������3:39:55
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //˼·��ʹ��˫ָ�뻬�����ڣ�һ��map��¼s�����е���ĸ��������map��¼t����Ҫ����ĸ����
//        //�������жϣ�O(n)��O(k)��kΪt�е��ַ�����С��
//        //�о��Լ�������ô����һͨ����ͦ���㷨��ζ�أ�
//        unordered_map<char,int> needed;
//        unordered_map<char,int> win;
//        for(auto s:t)
//            needed[s]++;
//        int left=0,right=0,ct=0;
//        int start=-1,len=s.size()+1;
//        while(right<s.size()){
//            win[s[right]]++;
//            if(needed.count(s[right])){
//                if(++win[s[right]]==needed[s[right]]){
//                    //����+1�������������������أ�ct�Ǻ�needed�Ĵ�С�����ģ�
//                    if(++ct==needed.size()){//˵������������ڡ�
//                        if(right-left<len)
//                            len=min(len,right-left);//�ǻ���Ҫ��һ��
//                            start=left;
//                    }
//                }//�ܸо�������д�������������ʶ�ĸо���
//            }
//            //Ȼ����ͼ��Сleft����ô����С�������ˡ�
//        }
//    }
//};
/*
 * 1.�Լ�д��д�Ż��ǿ�ס�ˣ�
 *   https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 * 2.���裬����������right���������ݸ��£��ж��Ƿ�Ҫ��С�󴰿ڣ����д��ڼ�¼�����ݸ��¡�
 * */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needed;
        unordered_map<char,int> win;
        for(auto c:t)
            needed[c]++;
        int left=0,right=0,ct=0;
        int start=-1,len=s.size()+1;
        while(right<s.size()){
            char c=s[right++];
//            cout<<c<<" ";
            if(needed.count(c)){//���ݸ���
                win[c]++;//ע�⣬ֻ���ڴ����ڵĲżӰ�
                if(win[c]==needed[c]){
                    ct++;
//                    if(ct==needed.size()&&right-left<len){//�������������жϣ����������
//                        len=right-left;
//                        start=left;
//                    }
                }
            }
            //�ж��Ƿ���Сleft����ô��С�������ֳ����ˡ�����
            while(ct==needed.size()){//������������ֵ����Ⱑ������
            	if(right-left<len){//��Ҫ�������жϰ���磡��Ϊ�������ʱ��ֻҪ����ѭ����������
            		len=right-left;//ct==��Ҫ�ģ�
            		start=left;
            	}
                c=s[left++];
//                cout<<" left "<<c<<" ";
                if(needed.count(c)){
                    if(win[c]==needed[c])
                        ct--;
                    win[c]--;
                }
            }
//            cout<<endl;
        }
        return start==-1?"":s.substr(start,len);
    }
};
/*
 * 1.Yes,���������AC�ˡ���
 * */

//12-7��ϰ
/*
 * 1.����Ҫע�ⴰ����С����������ct����¼����������t��ĸ��Ŀ�ĸ�������С����ʱҪ���¡�
 * */

//12-22
/*
 * 1.��Ҫע������С����ʱ������ֻ���ж��Ƿ���ȣ�������-���ж��Ƿ�<��
 *   ��������ct���μ����ͳ����ˣ�ֻ���еȡ�
 * */
int main(){
	Solution s;
	cout<<s.minWindow("a", "a");
    return 0;
}
