#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��5������12:29:38
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //ֻ���뵽�����ⷨ
        if(s=="")return true;//��Ҫ���ǵ��߽����ӣ�
        int k=0;
        for(int i=0;i<t.size();i++){
            //�ж�ÿ��s[k]==t[i]
            if(k<s.size()&&s[k]==t[i])k++;
            if(k==s.size())return true;
        }
        return false;
    }
};//AC�ˣ�ʱ��O(n)
/*
 * 1.����̳���˵���ö��֣�����left��right���ȥ��Ӧ�أ�ָ��t��������Ҳ��������İ���������Ҳ����
 *   �Ƚϴ�С�ɣ�С�����󣿴������ң�Ӧ���ǲ������ģ����Ǻ������⣬�д���S���ȥ�ж��أ��Ҳ�֪��������
 * 2.������⣬ԭ���˼Ҷ���˫ָ��д�İ�������д��Ҳ̫��ª�ˡ�����
 * 3.�ٷ���������˫ָ�루һ��ָ��s��һ��ָ��t������dp���̳�����ĺ����ⷨ�Ƕ��ַ���
 *   �ٷ�����dp�ⷨ���ţ�����´θ�ϰ���Ҷ���Ĳ�һ����д��������Ҫ֪������˼�롣
 * */

//11-18
/*
 * 1.��ʵ������д��Ҳ��˫ָ���˼�롣
 * 2.�ٷ���dp�ⷨ��https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/4.2-qi-ta-jing-dian-wen-ti/er-fen-cha-zhao-pan-ding-zi-xu-lie
 *   �̳��еĶ��ֽⷨ�����ܺã�dp�ǽ�����ά����dp[i][j]��ʾ��λ��i��ʼ��һ���ַ�j���ֵ�λ�ã����û��
 *   ���Ϊt�ַ����ĳ��ȣ�����ȥ����һ����ϣ�����Ӷ���ҪΪO(kn)��kΪ��ѯ�ַ���s�ĸ�������nΪs�ĳ���
 *   ���ֽⷨ����ͨ����ϣ����¼ÿ���ַ����ֵ�λ�ã���s��ÿ���ַ������ҵ����Ƿ�����±꣬��!
 *   �����������ܸ�Ч�ؽ������s��ѯ�����⣬ѧ���ˣ�
 * */

class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        //��t��Ԥ�����Ӻ���ǰ�ظ���
        if(s=="")return true;
        int m=t.size();
        if(m==0)return false;
        //��û��ע��base case���ύ�ˣ�ɵ��
        //""    ""
        vector<vector<int>> dp(m,vector<int>(26,m));
        dp[m-1][t[m-1]-'a']=m-1;
        for(int i=m-2;i>=0;i--){
            //����ô���°������Ѱ�
            for(int j=0;j<26;j++){
                if(j==t[i]-'a')dp[i][j]=i;
                else dp[i][j]=dp[i+1][j];
            }
        }
        int p=0;
        for(int i=0;i<s.size();i++){
        	if(p==m||dp[p][s[i]-'a']==m)return false;
            p=dp[p][s[i]-'a']+1;//�����+1���У���ΪҪ������ʼ�����ң�֮ǰ���ҵ�����˵���Ѿ��������ˣ�����
            //�ٴӱ�λ�ÿ�ʼ���ˡ�
            //����p��õ�6����ʲô��˼�أ�
        }
        return true;
    }
};
/*
 * 1.AC�ˣ����ǱȽϿ��ĵġ�
 * */
int main(){
	Solution2 s;
	cout<<s.isSubsequence("aaaaaa", "bbaaaa");//��Ҫ+1����Ȼһֱ����t�ĵ�һ��a�ǲ���ǰ�ߡ�
    return 0;
}
