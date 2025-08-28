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
    unordered_map<int, list<Node>> mNode;   //firstΪ������  secondΪ����
    unordered_map<int, unordered_map<int, list<Node>>::iterator> mit;//firstΪkey  secondΪmNode�ĵ�����
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
            //���û���ҵ���key�Ĵ���+1 �Ľڵ�//���½�һ���������ȴ�ʱkey�ļ���+1�Ľڵ�
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
    // cnt(x) = �� x ��ʹ�ü���
// cache=[] ����ʾ���һ��ʹ�õ�˳������ߵ�Ԫ��������ģ�
    LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu.get(1)<< endl;      // ���� 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // ȥ���� 2 ����Ϊ cnt(2)=1 ��ʹ�ü�����С
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu.get(2) << endl;      // ���� -1��δ�ҵ���
    cout << lfu.get(3) << endl;      // ���� 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // ȥ���� 1 ��1 �� 3 �� cnt ��ͬ���� 1 ���δʹ��
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu.get(1) << endl;      // ���� -1��δ�ҵ���
    cout << lfu.get(3) << endl;      // ���� 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu.get(4) << endl;      // ���� 4
    // cache=[3,4], cnt(4)=2, cnt(3)=3

    return 0;
}