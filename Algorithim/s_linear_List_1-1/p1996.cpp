#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    node *head = nullptr;
    node *p = nullptr;

    // 创建循环链表
    for (int i = 1; i <= n; i++) {
        node *temp = new node();
        temp->data = i;
        if (head == nullptr) {
            head = temp;
            p = temp;
        } else {
            p->next = temp;
            p = temp;
        }
    }
    p->next = head; // 将链表变成循环链表

    // 开始做约瑟夫问题
    node *q = head;
    node *prev = nullptr;
    while (q->next != q) {
        for (int i = 1; i < m; i++) {
            prev = q;
            q = q->next;
        }
        cout << q->data << ' ';
        prev->next = q->next;
        delete q;
        q = prev->next;
    }
    cout << q->data << endl;
    delete q;

    return 0;
}