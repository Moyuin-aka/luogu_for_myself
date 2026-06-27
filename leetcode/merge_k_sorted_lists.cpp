/*
 * LC 23. 合并 K 个升序链表
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 * 示例：
 *   输入：[[1,4,5],[1,3,4],[2,6]]
 *   输出：1->1->2->3->4->4->5->6
 *
 * 要求：O(N log K) 时间，N 为所有节点总数，K 为链表数量
 * 提示：用 priority_queue 维护一个最小堆，
 *       每次从堆顶取最小节点，再把该节点的 next 压入堆。
 *       注意 priority_queue 默认是最大堆，怎么让它变成最小堆？
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // TODO
    struct cmp
    {
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b -> val;
        }
        //大的val优先级低，可以构成最小堆
    };
    priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
    for(int i=0;i<lists.size();i++){
        if(lists[i]) pq.push(lists[i]);
    }
    ListNode dummy(0);
    ListNode* cur=&dummy;
    while(!pq.empty()){
        ListNode* node=pq.top();
        pq.pop();
        cur->next=node;
        cur=cur->next;
        if(node->next) pq.push(node->next);
    }
    return dummy.next;
}

// 工具函数：从 vector 建链表
ListNode* build(vector<int> vals) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

// 工具函数：打印链表
void print(ListNode* head) {
    while (head) { cout << head->val << " "; head = head->next; }
    cout << endl;
}

int main() {
    vector<ListNode*> lists = {
        build({1, 4, 5}),
        build({1, 3, 4}),
        build({2, 6})
    };
    print(mergeKLists(lists)); // 期望: 1 1 2 3 4 4 5 6
    return 0;
}
