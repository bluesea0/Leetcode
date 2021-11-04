#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��12������3:01:14
//class Solution {
//public:
//    int openLock(vector<string>& deadends, string target) {
//        //˼·��BFS����0000��ʼ������У�����¼������
//        queue<string> q;
//        unordered_set<string> set;
//        for(auto d:deadends)
//            set.insert(d);//����insert��
//        int ret=0;
//        q.push("0000");//����д��ʱ����ô�죿�ڶ��������ͳ�ʱ�ˡ����������������ˡ�
//        while(!q.empty()){
//            int len=q.size();
//            while(len--){
//                string top=q.front();q.pop();
//                if(top==target) return ret;
//                //��ÿһλ���ϵ��µ�
//                for(int i=0;i<4;i++){
//                    string u=up(top,i);
//                    if(set.count(u)==0)q.push(u);
//                    string d=down(top,i);
//                    if(set.count(d)==0)q.push(d);
//                }
//            }
//            ret++;
//        }
//        return -1;
//    }
//    string up(string s,int index){
//        if(s[index]=='9')
//            s[index]='0';
//        else
//            s[index]=(s[index]-'0'+1)+'0';
//        return s;
//    }
//    string down(string s,int index){
//        if(s[index]=='0')
//            s[index]='9';
//        else
//            s[index]=(s[index]-'0'-1)+'0';
//        return s;
//    }
//};//��ʱ�ˣ�������
/*
 * 1.oh�ҵ��죬�ֲ����ҵڶ���������ûͨ������Ϊ���᷵�صİ���0000->1000�������ڴ���1000��ʱ��down
 *   ���Ϊ0000�������ظ��ˡ�������ɵ�˰ɡ�
 * */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //˼·��BFS����0000��ʼ������У�����¼������
        queue<string> q;
        unordered_set<string> set;
        unordered_set<string> visit;
        for(auto d:deadends)
            set.insert(d);//����insert��
        int ret=0;
        q.push("0000");//
        if(set.count("0000"))return -1;
        visit.insert("0000");//�����ͺ�����0000������deadends�а�������
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string top=q.front();q.pop();
                if(top==target) return ret;
                //��ÿһλ���ϵ��µ�
                for(int i=0;i<4;i++){
                    string u=up(top,i);
                    if(set.count(u)==0&&visit.count(u)==0){
                        q.push(u);
                        visit.insert(u);
                    }
                    string d=down(top,i);
                    if(set.count(d)==0&&visit.count(d)==0){
                        q.push(d);
                        visit.insert(d);
                    };
                }
            }
            ret++;
        }
        return -1;
    }
    string up(string s,int index){
        if(s[index]=='9')
            s[index]='0';
        else
            s[index]=(s[index]-'0'+1)+'0';
        return s;
    }
    string down(string s,int index){
        if(s[index]=='0')
            s[index]='9';
        else
            s[index]=(s[index]-'0'-1)+'0';
        return s;
    }
};
/*
 * 2.�ҵ��죬AC�ˣ������װ�������
 * 3.����˫��BFS�������û�а취�ðɣ��Բۣ���Ȼ���ԣ��Ǵ�targetҲת������������ô֪�����߲���Խת
 *   ����ԽԶ�أ�
 * 4.�������ģ���Ҫ�õ��������ϣ����жϵ�ǰ��ɢ���Ƿ��ڶԷ��ļ���������˵��������չ����
 * */

//11-18
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //˼·��BFS����0000��ʼ������У�����¼������
        unordered_set<string> dead,visit;
        unordered_set<string> us1({"0000"}),us2({target});
        for(auto d:deadends)
            dead.insert(d);
        if(dead.count("0000"))return -1;
        if(target=="0000") return 0;//����ôд����Ҫ������жϣ���Ϊһ��forѭ���ͻ�ֱ�Ӳ���������
        int ans=0;
        while(!us1.empty()){
            if(us1.size()>us2.size()){
                auto t=us1;
                us1=us2;
                us2=t;
            }
            unordered_set<string> us3;
            for(string pwd:us1){
                for(int i=0;i<4;i++){
                    string u=up(pwd,i);
                    if(dead.count(u)==0){
                        if(us2.count(u)) return ans+1;
                        if(visit.count(u)==0){
                            us3.insert(u);
                            visit.insert(u);
                        }
                    }
                    string d=down(pwd,i);
                    if(dead.count(d)==0){
                        if(us2.count(d)) return ans+1;
                        if(visit.count(d)==0){
                            us3.insert(d);
                            visit.insert(d);
                        }
                    }
                }
            }
            us1=us3;
            ans++;
        }
        return -1;
    }
};
/*
 * 1.˫��BFS������ô��ɵģ��ͽ̳��ﲻһ�����̳����Ǳ�����ʱ��ͻ��ж��Ƿ��غϣ��������Ƿ���dead��
 *   �Ķ���Ž�set�������������ƿռ��ʹ�ô�С����Ϊdead����500��Χ�ڣ���Ҳ���ࣿ���ԾͶ��˲���
 *   �ظ��Ĵ��롣
 *   https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bfs-kuang-jia
 *   ��������̳�д��������ģ��Ȳ��ż�����dead���룬���Ӽ�ࡣ
 * 2.��127�⣬Ӧ�ò����������жϣ���Ϊ�������ĸ���ٵģ�����26����ĸ�任��ռ�ø���Ŀռ䣬�����㣿
 * */
int main(){

    return 0;
}
