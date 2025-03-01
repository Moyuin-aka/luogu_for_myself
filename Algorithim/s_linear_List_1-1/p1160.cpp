#include <iostream>
using namespace std;
//面对大数据来写直接插入排序，时间复杂度为O(n^2)。
//插入排序与删除的优点是不需要额外的空间，缺点是查找时间复杂度较高。
//优化的话可以考虑利用哈希表，查找时间复杂度为O(1)，空间复杂度为O(n)
//另外一种方法是利用二叉搜索树，查找时间复杂度为O(nlogn)，空间复杂度为O(n)
struct node
{
    int id;
    node *prev;
    node *next;
};

void insert(node *&head, int k, int i, bool left)
{
    node *newNode = new node();
    newNode->id = i + 1;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    node *temp = head;
    if (!left)
    {
        while (temp->id != k)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        while (temp->id != k)
        {
            temp = temp->next;
        }
        if (temp->prev == nullptr)
        {
            head = newNode;
        }
        else
        {
            temp->prev->next = newNode;
        }
        newNode->prev = temp->prev;
        temp->prev = newNode;
        newNode->next = temp;
    }
}

void deleteValue(node *&head, int id)
{
    node *temp = head;
    node *prior = nullptr;
    if (temp != nullptr && temp->id == id)
    {
        head = temp->next;
        head->prev = nullptr; // 这里可要可不要
        delete temp;
        return;
    } // 删除头节点
    while (temp != nullptr && temp->id != id)
    {
        prior = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        return;
    }
    prior->next = temp->next;
    prior->prev = temp->prev;
    if (temp->next != nullptr)
        temp->next->prev = prior;
    delete temp;
}

void printList(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->id << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    node *head = new node();
    head->id = 1;
    head->next = nullptr;
    head->prev = nullptr;
    // 重整顺序
    for (int i = 1; i < n; i++)
    {
        int k, p;
        cin >> k >> p;
        bool left = (p == 0 ? true : false);
        insert(head, k, i, left);
        // printList(head);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int id;
        cin >> id;
        deleteValue(head, id);
        // printList(head);
    }
    printList(head);
} // 链表手写数据结构版本

/* deepseek优化版本
#include <iostream>
#include <unordered_map>
using namespace std;

struct node {
    int id;
    node *prev;
    node *next;
};

void insert(node *&head, int k_id, int new_id, bool left, unordered_map<int, node*> &nodes) {
    node *target = nodes[k_id];
    node *newNode = new node();
    newNode->id = new_id;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    nodes[new_id] = newNode;

    if (!left) { // 插入到右侧
        newNode->prev = target;
        newNode->next = target->next;
        if (target->next != nullptr) {
            target->next->prev = newNode;
        }
        target->next = newNode;
    } else { // 插入到左侧
        newNode->next = target;
        newNode->prev = target->prev;
        if (target->prev != nullptr) {
            target->prev->next = newNode;
        } else {
            head = newNode; // 更新头节点
        }
        target->prev = newNode;
    }
}

void deleteNode(node *&head, int id, unordered_map<int, node*> &nodes) {
    if (nodes.find(id) == nodes.end()) return;
    node *target = nodes[id];

    // 更新前驱节点
    if (target->prev != nullptr) {
        target->prev->next = target->next;
    } else {
        head = target->next; // 删除的是头节点
    }

    // 更新后继节点
    if (target->next != nullptr) {
        target->next->prev = target->prev;
    }

    nodes.erase(id);
    delete target;
}

void printList(node *head) {
    node *temp = head;
    while (temp != nullptr) {
        cout << temp->id << " ";
        cout << temp->id << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    node *head = new node();
    head->id = 1;
    head->prev = head->next = nullptr;
    unordered_map<int, node*> nodes;
    nodes[1] = head;

    for (int i = 1; i < n; ++i) {
        int k, p;
        cin >> k >> p;
        insert(head, k, i + 1, p == 0, nodes);
    }

    cin >> m;
    while (m--) {
        int id;
        cin >> id;
        deleteNode(head, id, nodes);
    }

    printList(head);

    // 释放内存
    node *current = head;
    while (current) {
        node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
*/