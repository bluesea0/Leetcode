#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��6������3:26:13
class Solution {
public:
    //vector<int> fa(26,0);//����Char 20: error: expected parameter declarator
    //�������޷����ָ�����ǳ�Ա�����������ǳ�Ա��������
    vector<int> fa;
    bool equationsPossible(vector<string>& equations) {
        //��������дһ��
        //��ʼ��
        fa.resize(26);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(auto e:equations)
            if(e[1]=='=')//�������첢�鼯
                merge(e[0]-'a',e[3]-'a');

        for(auto e:equations){
            if(e[1]=='!'){
                if(find(e[0]-'a')==find(e[3]-'a'))
                    return false;
            }
        }
        return true;
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);
    }
};
/*
 * 1.Yes AC�ˣ���ע�⵽���ﶨ���ʼ����Ա�����Ĳ��������Ĵ��󣬻�����ͷһ����������
 *   ���ģ����ʱ�临�Ӷȵķ�����O(n+ClogC)��n�Ƿ�����Ŀ��C �Ǳ������������ڱ����б�������Сд��ĸ��
 *   �� C��26������Ĳ��鼯������ʹ����·��ѹ���Ż���
 *   ����ÿ�����̵ĺϲ��Ͳ��ҵľ�̯ʱ�临�Ӷȶ��� O(logC)��
 *   ������Ҫ����ÿ�����̣������ʱ�临�Ӷ��� O(n+ClogC)��
	��ʵ�Ҳ�̫���Ϊʲô��ʱ�临�Ӷ�������أ� ���ٷ�������Ƶ��˵�����鼯�ռ临�Ӷȷ����������Ե㣬���Ҿ�
	���ͽ��ˡ�
	�ռ���O(C)
 * */
int main(){

    return 0;
}
