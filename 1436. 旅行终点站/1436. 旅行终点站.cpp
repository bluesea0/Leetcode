#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��1������8:32:00
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> setA;
        for(auto& p:paths){
            setA.insert(p[0]);
        }
        for(auto& p:paths){
            if(setA.count(p[1])==0)
                return p[1];
        }
        return "";
    }
};
/*
 * 1.�������һ��ʼ������ʱ��û��Ӧ����������Ϊ��ͼ����Ŀ���Ƿ�Ҫ����ͼ��Ȼ����������û�ͦ�鷳��
 *   ���ǿ��˹ٷ����֮��ԭ�������������������Լ�����������
 * */
int main(){

    return 0;
}
