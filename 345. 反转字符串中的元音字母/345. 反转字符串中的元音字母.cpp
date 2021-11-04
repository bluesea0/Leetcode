#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��6������2:47:43
class Solution {
public:
    string reverseVowels(string s) {
        //˼·��˫ָ��ֱ����������
        //���Ӷ�:O(n)��O(1)
        int i=0,j=s.size()-1;
        unordered_set st={'a','e','i','o','u','A','E','I','O','U'};//ֻ��Сд�𣿰�����д��
        while(i<j){
            while(i<j&&st.count(s[i])==0)i++;
            while(i<j&&st.count(s[j])==0)j--;
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};
/*
 * 1.ûʲô����������
 * */
int main(){

    return 0;
}
