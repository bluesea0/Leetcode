#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��6������3:09:23
class Solution {
public:
    bool validPalindrome(string s) {
        //�����˰���û��ϸ���⣬��Ϊ����easy�ģ����Ծ͹��������˰���
        //�ڲ���ȵ�ʱ��ֱ�ȥ�жϼ�ȥi��j
        return palin(s,0,s.size()-1,1);
    }
    bool palin(string & s,int fr,int to,int flag){
        while(fr<to){
            if(s[fr]==s[to]){fr++;to--;}
            else if(flag){
                return (palin(s,fr+1,to,0) || palin(s,fr,to-1,0));
            }else return false;
        }
        return true;
    }
};
/*
 * 1.AC�ˡ�ʱ����O(n)���ռ䣿�����˺���O(1)�ɡ�
 *
 *public boolean validPalindrome(String s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (s.charAt(i) != s.charAt(j)) {
            return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
        }
    }
    return true;
}

private boolean isPalindrome(String s, int i, int j) {
    while (i < j) {
        if (s.charAt(i++) != s.charAt(j--)) {
            return false;
        }
    }
    return true;
}//���ʵ�ֱ��Ҽ����ˣ��´θ�ϰ��
 * */

//12-22
/*
 * 1.���츴ϰ�������˼ҵĴ�����ô����д����ô�����أ����Ŵ��룡
 * */
int main(){

    return 0;
}
