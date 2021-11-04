#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
////2021��2��13������9:52:14
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        //ûʲô˼·������ջ��������ε����أ������ݼ�ջ�����ǿ��ܻ�����ظ���������⡣
//        //������ռ��뵯�����Ϳ��ܻ�����������ġ�
//    }
//};
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        //����ջ����ÿ��Ԫ�������ұ��ҵ�>=�������ӣ�Ȼ��˳����㡣
//        //�����ݼ�ջ
//        //���ǻ��ǻ������ظ���������Ⱑ����ô���ܲ��ظ������أ�
//        //������ǩ�ﻹ�ж�̬�滮�������룬��Ҳ��������������ӡ�
//        vector<int> stack;
//        for(int i=0;i<height.size();i++){
//            if(height[i]==0)continue;
//            if(stack.empty()||height[stack.back()]>)
//        }
//    }
//};
class Solution {
public:
    int trap(vector<int>& height) {
        //��дһ����򵥵�
        //�����ǣ���ÿһ�������ҵ����������ֵ�Ľ�Сֵ������ÿ�����Ӷ����������ʢˮ�Ĵ�С
        //���α�����һ���ҵ���ߵ����ֵ��һ���ҵ��ұߵ����ֵ
        int n=height.size(),max_left=0,max_right=0;
        vector<int> left(n,0);
        for(int i=0;i<n;i++){
            left[i]=max_left;
            max_left=max(height[i],max_left);
        }
        vector<int> right(n,0);
        for(int i=n-1;i>=0;i--){
            right[i]=max_right;
            max_right=max(max_right,height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(right[i],left[i]);//������ȡ��Сֵ
            if(x>height[i])ans+=(x-height[i]);
        }
        return ans;
    }
};
/*
[0,1,0,2,1,0,1,3,2,1,2,1]

[0,0,1,1,2,2,2,2,3,3,3,3] left
[3,3,3,3,3,3,3,2,2,2,1,0] right
[0,0,1,0,1,2,1,0,0,1,0,0] res
1.����ⷨ�ٷ���д�ı��Һã�����ֱ�Ӽ���i��ߣ�����i�������ֵ��i�ұߣ�����i�������ֵ�������ڼ�����
  ��ʱ��͸��Ӽ��ˡ�
2.����ջ�Ľⷨ�������ͬ���Ǽ�����ŵĳ�������������������ÿ����������������ġ�
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        vector<int> stack;
        //��Ȼ˵�����õ���ջ��������ǵ����أ�����ô����
        int ans=0;
        for(int i=0;i<height.size();i++){
            while(!stack.empty()&&height[stack.back()]<height[i]){
                int top=stack.back();
                stack.pop_back();
                if(!stack.empty()){//��Ҫ���㳤�Ϳ���ȡ��˻���Ϊ���
                    int h=min(height[stack.back()],height[i])-height[top];
                    //��ȵģ���������h��Ϊ0
                    ans+=h*(i-stack.back()-1);
                }
            }
            stack.push_back(i);
        }
        return ans;
    }
};//����˫ָ��Ľⷨ�´θ�ϰд��
/*
 * 1.�ٷ�������д�Ĳ�࣬Ҳ�ǽ���ȵ�ֵ�Ž�ȥ��Ҫע�����ջΪ��ʱ���ж�
 * */

//2-15
class Solution3 {
public:
    int trap(vector<int>& height) {
        //˫ָ�룬�ֱ�������ң������������
        int left=0,right=height.size()-1,max_left=-1,max_right=-1;//������max��ô��ʼ����
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){//�����������ⶼ�ᱻ��ȵ����������
                if(height[left]>max_left)max_left=height[left];
                else{
                    ans+=(max_left-height[left]);//�������Ǿ���0������ν��
                }
                left++;
            }else{//������Ľ϶�ֵ��ȵĻ����Ǿ����Ҷ�������
                if(height[right]>max_right)max_right=height[right];//���һֱ�����Ļ���ʢ����ˮ
                else ans+=(max_right-height[right]);
                right--;
            }
            cout<<ans;
        }
        cout<<endl;
        return ans;
    }
};//˫ָ���ҲAC�ˣ�̫���˰ɣ�

//3-6��ϰ
/*
 * 1.�ܹ�˳���뵽��һ�ַ��������α���������Ϊ��Ҫ��ÿ�������ҵ�������ֵ���ұ����ֵ��ͨ������minֵ����
 * 2.����ջ�ķ����е��Ժ������ϸ�ݼ�ջ����ջ֮�����һ��Ԫ�ؾ���������߽磬��ջ�������ǵ�ǰԪ�ر���С����
 *   ջ��Ԫ�ص���ʱ���㣬��߽�Ϊ��һ��Ԫ�أ��ұ߽�Ϊ��С��Ԫ��
 * 3.˫ָ��Ľⷨû���뵽�����Ǵӵ�һ�������Ż���������ʵ����βָ�룬���left<right����ô����ض���left������
 *   ��֮��right��ͦ�����ġ�
 * */

//9-19
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        stack<int> stk;
        int ans=0;
        for(int i=0;i<height.size();i++){
//            if(stk.empty()||height[i]<=height[stk.top()]){
//                stk.push(i);continue;
//            }//��ʵ����ط������У��������ջ�Ļ�����ôֱ�����push��ȥ���С�
            while(!stk.empty()&&height[stk.top()]<height[i]){
                int k=stk.top();
                stk.pop();
                if(stk.empty())break;
                int h=min(height[stk.top()],height[i])-height[k];
                ans+=(h*(i-stk.top()-1));
            }
            stk.push(i);
        }
        return ans;
    }
};
int main(){
	vector<int> a={0,1,2,1};
	Solution2 s2;
	Solution3 s3;
	cout<<s2.trap(a)<<endl;
	cout<<s3.trap(a);
    return 0;
}
