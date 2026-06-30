/*
 * LC 146. LRU 缓存
 *
 * 设计一个 LRU (最近最少使用) 缓存：
 *   - LRUCache(int capacity)    以正整数作为容量初始化
 *   - int get(int key)          如果 key 存在返回 value，否则 -1
 *   - void put(int key, int value)
 *       如果 key 存在就更新 value；
 *       如果不存在就插入；
 *       如果插入后超出容量，删除最久未使用的 key-value
 *
 * get 和 put 都算作一次"使用"。
 *
 * 要求：get 和 put 的时间复杂度 O(1)
 *
 * 提示：哈希表 + 双向链表。
 *       哈希表能在 O(1) 找到节点，双向链表能在 O(1)
 *       做删除和移动（把刚用过的节点移到头部）。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        // TODO
    }

    int get(int key) {
        // TODO
        return -1;
    }

    void put(int key, int value) {
        // TODO
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;   // 返回 1
    cache.put(3, 3);                // 淘汰 key 2
    cout << cache.get(2) << endl;   // 返回 -1
    cache.put(4, 4);                // 淘汰 key 1
    cout << cache.get(1) << endl;   // 返回 -1
    cout << cache.get(3) << endl;   // 返回 3
    cout << cache.get(4) << endl;   // 返回 4
    return 0;
}
