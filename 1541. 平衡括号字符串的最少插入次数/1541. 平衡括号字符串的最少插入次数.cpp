#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//10-19
//class Solution {
//public:
//    int minInsertions(string s) {
//        int left=0,right=0,t=0;
//        for(auto ss:s){
//            if(ss=='(')
//                left++;
//            else{
//                t++;
//                if(t==2){
//                    if(left)left--;
//                    else right++;
//                    t=0;
//                }else{
//                    t++;
//                }
//            }
//        }
//        right=right*2+t;
//        //我的天，写到这里我才发现我的思路是错的。。。
//        //比如这个 "))())(" 样本我就已经凉凉了，因为我上面是没有考虑到顺序的，就很麻烦了。
//        //本来以为不需要用到栈的，但是原来应该是需要用到的啊。
//    }
//};
/*
1.但是这个用栈的话，好像也蛮有难度的，右括号需要入栈吗，就像这个"))())("，一开始有右括号
  怎么办？有点难啊。
*/
//class Solution {
//public:
//    int minInsertions(string s) {
//        stack<char> st;
//        int k=0,t=0;//记录未匹配上左括号的右括号有多少个
//        for(auto ss:s){
//            if(ss='(')
//                st.push(ss);
//            else{
//                t++;
//                if(t==2){
//                    if(!st.empty())
//                        st.pop();
//                    else
//                        k+=t;
//                    t=0;
//                }
//            }
//        }
//        if(t!=0)t=2;
//        return st.size()*2+k/2+t;
//    }
//};
/*
2.太难了，这个逻辑我根本想不出来啊。。。
3.看了题解，我发现，我有个地方理解错了，需要是连续的两个右括号！
*/

//10-20
class Solution {
public:
    int minInsertions(string s) {
        int index=0,left=0,right=0;
        while(index<(int)s.size()){
            if(s[index]=='('){
                left++;
                index++;
            }else{//下面判断的逻辑我还是搞不懂。
                if(left){//表示此时来了一个右括号，那么只需要再添加一个右括号就可以了。
                    left--;
                    //index++;//这里right值要改变吗？
                }else right++;
                //下面这个判断怎么没有放到left里面呢？反正我懵了，逻辑还是搞不懂。
                if(index+1!=(int)s.size()&&s[index+1]==')'){//出现了两个右括号，可以匹配了
                    index+=2;
                }else{
                    right++;index++;
                }
            }
        }
        return left*2+right;//返回结果的值也是一个知识点啊！
    }
};
/*
1.我还是搞不懂这个逻辑，昨天也是迷迷糊糊没有进行实例分析，所以今天写不出来也是理所应当的。
2.Yes！AC了！看了它的逻辑之后我明白了：
  如果当前是左括号，则计数+1
  如果当前是右括号，如果存在左括号，那么左括号-1，并且要判断是否有两个连续的右括号，
      如果有两个连续的右括号，那么index+=2；
      否则计数+1，说明要插入另一个右括号；
  如果当前是右括号，如果不存在左括号，那么计数+1，说明要插入一个左括号。
3.其实我这里的right就是它的insertion数目啊，还是有点理解问题，之后要复习的。
4.卧槽，我看视频，人家模拟面试，还要倒着遍历？我听到之后一片空白。。。我只会记住这个套路。。
  如果一变那不就emmmm。。。。怪难的，今天晚上回去搞！
*/
//10-21
/*
1.清华大佬是用栈的思想来解的，但是上面给的好像不是栈的思想啊。
*/
class Solution1 {
public:
    int minInsertions(string s) {
        int m=s.size(),res=0,i=m-1,ct=0;//ct这里表示的是栈
        while(i>=0){
            if(s[i]==')'){
                ct++;
            }else{//只要出现了左括号，右括号就是不连续的了。
                if(ct>=2){
                    ct-=2;
                }else{
                    if(ct==1){
                        res+=1;
                        ct--;
                    }else
                        res+=2;
                }

            }
            i--;
        }
        res+=(ct%2==0?ct/2:ct/2+2);
        return res;
}};
/*
2."(()))(()))()())))" 应该是4，上面这种解法没有考虑到))是要连续的！
  也不对啊，“())(())))”这个它就是连续的啊，好想没什么办法判断了？
  我不会了，脑袋一窝乱粥，如果是(判断下一个是否是)?如果是则断开？如果是(则继续？ct不清0?
3.这个是从后往前遍历，人家也没写出来。
*/

//11-24
class Solution2 {
public:
    int minInsertions(string s) {
        //思路：用栈遍历字符串
        int i=0,insert=0,left=0;//其实没有用到right
        while(i<s.size()){
            if(s[i]=='(')
                left++;
            else{
                if(left!=0)
                    left--;
                else insert++;//表示要插入一个左括号
                //判断i+1是否是)
                if(i==s.size()-1)insert++;//表示到末尾但缺少一个有括号
                else if(s[i+1]!=')') insert++;
                else i++;
            }
            i++;
        }
        return insert+left*2;
    }
};
/*
 * 1.今天复习也能AC了，还比较顺滑。
 * */
int main(){
    Solution s;
    cout<<s.minInsertions("()()))");
    return 0;
}
