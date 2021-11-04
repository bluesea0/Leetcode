#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	 int n, e;//成员总个数，能量总数
	 cin >> n >> e;
	 vector<int> a(n);//每个成员能量初始值
	 for (int i = 0;i < n;i++) {
	 	cin >> a[i];
	 }
	 sort(a.begin(), a.end());
	 int res1 = 0;
	 int left = 0;
	 int res2 = 0;
	 for (int j = n - 1;j > 0;j++) {
	  int sum = 0;
	  int temp = 0;
	  for (int i = j - 1;i >= 0;i--) {
		  sum += a[j] - a[i];
		   if (sum > e) {
			temp = j - i;
			left = i;
			break;
		   }
	   }
	  if (temp > res1) {
		   res1 = temp;
		   res2 = sum - (a[j] - a[left]);
		}
	 }
	 return 0;
}
