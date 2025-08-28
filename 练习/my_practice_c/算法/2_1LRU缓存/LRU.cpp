#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class LRUCache {
private:
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> nodes;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        if (nodes.find(key) == nodes.end())
        {
            return -1;
        }
        else
        {
            list<pair<int, int>>::iterator cur = nodes.find(key)->second;
            int value = cur->second;
            lst.push_back(make_pair(key, value));
            nodes[key] = prev(lst.end());
            lst.erase(cur);
            return value;
        }

    }

    void put(int key, int value) {
        if (lst.empty())
        {
            lst.push_back(make_pair(key, value));
            nodes.insert(make_pair(key, lst.begin()));
            size++;
        }
        //找到了 （不用考虑容量，修改值就行了）
        else if (nodes.find(key) != nodes.end())
        {
            list<pair<int, int>>::iterator cur = nodes.find(key)->second;
            cur->second = value;

            if (next(cur) == lst.end())
            {
                return;
            }
            else
            {
                lst.push_back(make_pair(key, value));
                nodes[key] = prev(lst.end());
                lst.erase(cur);
            }
        }
        //没找到 且 未达到容量
        else if (nodes.find(key) == nodes.end() && size < capacity)
        {
            lst.push_back(make_pair(key, value));
            nodes.insert(make_pair(key, prev(lst.end())));
            size++;
        }
        //没找到 且 达到容量了
        else if (nodes.find(key) == nodes.end() && size >= capacity)
        {
            lst.push_back(make_pair(key, value));
            nodes.insert(make_pair(key, prev(lst.end())));
            list<pair<int, int>>::iterator cur = lst.begin();
            nodes.erase(cur->first);
            lst.erase(cur);
        }
        else {
            return;
        }
    }

};

int main()
{
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    cout << lru.get(1) << endl;
    lru.put(3,3);
    cout << lru.get(2) << endl;
    lru.put(4,4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;


}