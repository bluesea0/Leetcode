#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int key, value;
  int time, count;
  Node(int k, int v, int t) : key(k), value(v), time(t), count(1) {}
  // bool operator<(const Node *r) const
  // { //为什么参数不是指针类型的呢？
  //   // if(this->count<r.count)return true;
  //   // else if(this->count==r.count&&this->time<r.time)return true;
  //   // return false;//这样写确实挺麻烦的。
  //   return this->count == r->count ? this->time < r->time : this->count < r->count;
  // }
};
struct cmp
{
  bool operator()(const Node *a, const Node *b) const
  {
    return a->count == b->count ? a->time < b->time : a->count < b->count;
  }
};
static bool cmp2(const Node *a, const Node *b)
{
  return a->count == b->count ? a->time < b->time : a->count < b->count;
}
class LFUCache
{
public:
  int k, time;
  unordered_map<int, Node *> mp;
  set<Node *, deltype(cmp2)> st(cmp2);
  LFUCache(int capacity)
  {
    k = capacity;
    time = 0;
  }
  int get(int key)
  {
    if (mp.count(key) == 0)
      return -1;
    Node *node = mp[key];

    st.erase(node); //必须要删掉，因为根本无法从集合中获取到对应的节点，然后引用改变？
    //只能是删掉了。
    //node->time++;
    node->time = ++time;
    node->count++;
    st.insert(node);
    return node->value;
  }
  void put(int key, int value)
  {
    if (mp.count(key))
    {
      Node *node = mp[key];
      st.erase(node);
      node->value = value;
      node->count++;
      //node->time++;//时间不是这么计算的
      node->time = ++time;
      st.insert(node);
    }
    else
    {
      if ((int)mp.size() == k)
      {                           //先删除一个节点
        Node *node = *st.begin(); //这里获取到的是迭代器类型？
        mp.erase(node->key);      //set的迭代器如何操作需要理解一下。
        st.erase(node);
        //如何delte？
        cout << "node->key " << node->key << node->count << node->time << "\n";
        delete node;
      }
      Node *node = new Node(key, value, ++time);
      mp[key] = node;
      st.insert(node);
    }
  }
};
int main()
{
  LFUCache lfu(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  cout << lfu.get(1) << "\n";
  lfu.put(3, 3);
  cout << lfu.get(2) << "\n";
}