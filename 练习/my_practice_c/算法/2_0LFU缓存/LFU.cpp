#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct Node
{
    int key;
    int value;
    Node() {}
    Node(int key, int value) : key(key), value(value) {}
};

class LFUCache {
public:
    int capacity;
    int size;
    unordered_map<int, list<Node>> mNode;   //first为计数器  second为链表
    unordered_map<int, unordered_map<int, list<Node>>::iterator> mit;//first为key  second为mNode的迭代器
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        if (mit.find(key) == mit.end())
        {
            return -1;
        }
        else
        {
            //如果没有找到该key的次数+1 的节点//则新建一个计数器比此时key的计数+1的节点
            int num = mit.find(key)->first;
            int value = mNode.find()
            if (mNode.find(num + 1) == mNode.end())
            {

            }
        }
    }

    void put(int key, int value) {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
    LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu.get(1)<< endl;      // 返回 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu.get(2) << endl;      // 返回 -1（未找到）
    cout << lfu.get(3) << endl;      // 返回 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu.get(1) << endl;      // 返回 -1（未找到）
    cout << lfu.get(3) << endl;      // 返回 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu.get(4) << endl;      // 返回 4
    // cache=[3,4], cnt(4)=2, cnt(3)=3

    return 0;
}