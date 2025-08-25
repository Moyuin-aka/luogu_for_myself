/*P1185 绘制二叉树
 * 
 * 题解：https://www.luogu.com.cn/problem/P1185
 * 
 * 这个题解的思路是使用递归来绘制二叉树，删除节点时只标记为不存在，而不是实际删除。
 * 
 * 注意：这个代码是基于原题解的思路进行改写,依赖于 Gemini 和 deepseek，保持了与原题解一致的结构和逻辑。
 * 
 * 参考：
 * - 原题：https://www.luogu.com.cn/problem/P1185
 * - 题解：https://www.luogu.com.cn/article/bu6k10fo
 *
 * 这个代码的实现依赖于对二叉树的堆式编号和几何参数的预计算。
 *
 * 注意：这个代码没有处理实际删除子树的逻辑，只是标记了节点不存在。
 */
#include <iostream>
#include <vector>
#include <string>
#include <array> // For std::array
#include <numeric> // For std::iota if needed, though not for this problem's tr init

// 使用宏定义左右孩子，保持与原题解一致性
#define ls(x) ((x) << 1)      // 等价于 2*x
#define rs(x) (((x) << 1) | 1) // 等价于 2*x+1

using namespace std;

// 预计算的几何参数，与原题解保持一致
// a[k] 大致表示当一个节点之下还有k层分支时，其子节点相对于父节点的水平偏移量
// 同时也代表了连接父子节点的斜线的长度（段数）
const array<int, 12> a = {0, 1, 2, 5, 11, 23, 47, 95, 191, 383, 767, 1535};

// 全局画布和树结构
vector<vector<char>> pic;
vector<bool> tr;
int m_global; // 将m设为全局或通过参数传递给draw系列函数

// 函数声明 (因为draw, drawl, drawr相互调用)
void draw(int p, int n, int x, int y);

void drawl(int p_child, int n_branch_levels, int x_parent, int y_parent) {
    int i = x_parent, j = y_parent;
    int branch_len = a[n_branch_levels]; // 当前这段斜线的长度
    
    // 绘制左斜线 '/'
    for (int k = 0; k < branch_len; ++k) {
        i++; 
        j--;
        // 边界检查，确保不会画出画布
        if (i < pic.size() && j < pic[0].size() && i >=1 && j >=1) {
            pic[i][j] = '/';
        }
    }
    
    // 绘制左孩子节点 'o'
    i++; 
    j--;
    if (i < pic.size() && j < pic[0].size() && i >=1 && j >=1) {
        pic[i][j] = 'o';
    }
    
    // 递归绘制左孩子的子树，剩余分支层数减1
    draw(p_child, n_branch_levels - 1, i, j); 
}

void drawr(int p_child, int n_branch_levels, int x_parent, int y_parent) {
    int i = x_parent, j = y_parent;
    int branch_len = a[n_branch_levels]; // 当前这段斜线的长度

    // 绘制右斜线 '\'
    for (int k = 0; k < branch_len; ++k) {
        i++; 
        j++;
         // 边界检查
        if (i < pic.size() && j < pic[0].size() && i >=1 && j >=1) {
            pic[i][j] = '\\';
        }
    }
    
    // 绘制右孩子节点 'o'
    i++; 
    j++;
    if (i < pic.size() && j < pic[0].size() && i >=1 && j >=1) {
        pic[i][j] = 'o';
    }
    
    // 递归绘制右孩子的子树，剩余分支层数减1
    draw(p_child, n_branch_levels - 1, i, j);
}

void draw(int p_node_idx, int n_remaining_branch_levels, int x_curr_node, int y_curr_node) {
    // 如果没有剩余分支层数了，说明当前节点是叶子（或者其子树的叶子），结束这条路径的绘制
    if (n_remaining_branch_levels == 0) return;

    // 检查并绘制左子树
    if (ls(p_node_idx) < tr.size() && tr[ls(p_node_idx)]) { // 检查左孩子是否存在
        drawl(ls(p_node_idx), n_remaining_branch_levels, x_curr_node, y_curr_node);
    }

    // 检查并绘制右子树
    if (rs(p_node_idx) < tr.size() && tr[rs(p_node_idx)]) { // 检查右孩子是否存在
        drawr(rs(p_node_idx), n_remaining_branch_levels, x_curr_node, y_curr_node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n_deletions;
    cin >> m >> n_deletions;
    m_global = m; // 如果draw系列函数不传递m的话，需要全局m

    // 1. 初始化画布 pic
    // 根据题解的输出循环，行数最大为 a[m]+1，列数最大为 a[m+1]+1
    // 我们使用1-based索引，所以vector大小要+1，即 (a[m]+1)+1 和 (a[m+1]+1)+1
    int pic_rows = a[m] + 2; // Max row index is a[m]+1
    int pic_cols = a[m+1] + 2; // Max col index is a[m+1]+1
    pic.assign(pic_rows, vector<char>(pic_cols, ' '));

    // 2. 初始化树结构 tr (使用1-based索引)
    // 满m层二叉树最多有 2^m - 1 个节点
    // 为了使用堆式编号，tr数组大小至少要能容纳最后一个节点的编号
    // 最后一个节点的编号可能是 rs( (1<<(m-1)) -1 )，或者简单地开到 1<<m
    tr.assign(1 << m, true); // 大小为2^m，下标范围0到2^m-1。如果用1-based, 则tr[0]不用

    // 将tr[0]标记为不存在，因为我们用1-based编号
    if (!tr.empty()) tr[0] = false; 

    // 3. 处理删除操作
    for (int k = 0; k < n_deletions; ++k) {
        int level_del, idx_in_level_del; 
        cin >> level_del >> idx_in_level_del; 
        
        // 将 (level, idx_in_level) 转换为一维堆式编号
        // 前 level_del - 1 层共有 (1 << (level_del - 1)) - 1 个节点
        int node_1d_idx = (1 << (level_del - 1)) - 1 + idx_in_level_del;
        
        if (node_1d_idx < tr.size()) { // 检查编号是否在tr范围内
            tr[node_1d_idx] = false; 
            // 注意：这个题解的删除逻辑是“懒删除”，只标记节点不存在
            // draw函数在递归时会检查tr[child_idx]，如果为false就不画
            // 如果要严格删除子树，需要在这里加一个递归删除tr中子节点的函数
        }
    }

    // 4. 绘制根节点并开始递归绘制
    int root_col = a[m] + 1; // 根节点的列坐标 (1-based)
    if (tr[1]) { // 只有根节点存在才绘制
        pic[1][root_col] = 'o'; 
        draw(1, m - 1, 1, root_col); // p=1(根), n=m-1(剩余分支层数), x=1, y=root_col
    }
    
    // 5. 输出画布
    // 输出到实际绘制内容的最大行和最大列
    for (int i = 1; i <= a[m] + 1; ++i) {
        // 为了避免行末空格，找到该行最后一个非空字符 (可选优化，或者直接输出到a[m+1]+1)
        int last_char_col = 0;
        for (int j = 1; j <= a[m+1] + 1; ++j) {
            if (pic[i][j] != ' ') {
                last_char_col = j;
            }
        }
        for (int j = 1; j <= last_char_col; ++j) {
            cout << pic[i][j];
        } 
        cout << '\n'; // 使用'\n'比endl更快
    } 
    
    return 0;
}
/*# P1185 绘制二叉树

## 题目描述

二叉树是一种基本的数据结构，它要么为空，要么由根结点，左子树和右子树组成，同时左子树和右子树也分别是二叉树。

当一颗二叉树高度为 $m-1$ 时，共有 $m$ 层。若一棵二叉树除第 $m$ 层外，其他各层的结点数都达到最大，且叶子结点都在第 $m$ 层时，则其为一棵满二叉树。

现在，需要你用程序来绘制一棵二叉树，它由一棵满二叉树去掉若干结点而成。对于一棵满二叉树，我们需要按照以下要求绘制：

1. 结点用小写字母 `o` 表示，对于一个父亲结点，用 `/` 连接左子树，用 `\` 连接右子树。

2. 定义 $[i,j]$ 为位于第 $i$ 行第 $j$ 列的某个字符。若 $[i,j]$ 为 `/` ，那么 $[i-1,j+1]$ 与 $[i+1,j-1]$ 要么为 `o` ，要么为 `/`。若 $[i,j]$ 为 `\` ，那么 $[i-1,j-1]$ 与 $[i+1,j+1]$ 要么为 `o`，要么为 `\` 。同样，若 $[i,j]$ 为第 $1\sim m-1$ 层的某个结点 `o` ，那么 $[i+1,j-1]$ 为 `/`，$[i+1,j+1]$ 为 `\`。

3. 对于第 $m$ 层结点也就是叶子结点点，若两个属于同一个父亲，那么它们之间由 $3$ 个空格隔开；若两个结点相邻但不属于同一个父亲，那么它们之间由 $1$ 个空格隔开。第 $m$ 层左数第 $1$ 个结点之前没有空格。

最后需要在一棵绘制好的满二叉树上删除 $n$ 个结点（包括这个结点的左右子树，以及与父亲的连接），原有的字符用空格替换（空格为 `ASCII 32`，若输出 `ASCII 0` 会被算作错误答案）。

## 输入格式

第 $1$ 行包含 $2$ 个正整数 $m$ 和 $n$，为需要绘制的二叉树层数和需要删除的结点数。

接下来 $n$ 行，每行两个正整数，表示删除第 $i$ 层的第 $j$ 个结点。

## 输出格式

按照题目要求绘制的二叉树。

## 输入输出样例 #1

### 输入 #1

```
2 0
```

### 输出 #1

```
o  
 / \ 
o   o
```

## 输入输出样例 #2

### 输入 #2

```
4 0
```

### 输出 #2

```
o           
          / \          
         /   \         
        /     \        
       /       \       
      /         \      
     o           o     
    / \         / \    
   /   \       /   \   
  o     o     o     o  
 / \   / \   / \   / \ 
o   o o   o o   o o   o
```

## 输入输出样例 #3

### 输入 #3

```
4 3
3 2
4 1
3 4
```

### 输出 #3

```
o           
          / \          
         /   \         
        /     \        
       /       \       
      /         \      
     o           o     
    /           /      
   /           /       
  o           o        
   \         / \       
    o       o   o
```

## 说明/提示

$30\%$ 的数据满足：$n=0$；

$50\%$ 的数据满足：$2\le m\le 5$；

$100\%$ 的数据满足：$2\le m\le10,0\le n\le 10,1<i\le M,j\le 2^{i-1}$。*/