// 反转链表

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

struct Node
{
  int address, data, next;
} nodes[MAXN];  // 数组下标为address

int head, N, K;  // 头节点的指针
int ordered[MAXN];  // 按地址排好序的节点

signed main()
{
  cin >> head >> N >> K;

  int address, data, next;
  while (N--)
  {
    cin >> address >> data >> next;
    Node & node = nodes[address];
    node.address = address;
    node.data = data;
    node.next = next;
  }

  int pos = 0, cur = head;
  while (cur != -1)
  {
    ordered[pos++] = cur;
    cur = nodes[cur].next;
  }

  for (int i = 0; i < pos; i += K)
  {
    if (i + K <= pos)  // 逆转链表
      reverse(ordered+i, ordered+i+K);
    else break;
  }

  for (int i = 0; i < pos; ++i)
  {
    printf("%05d %d ", nodes[ordered[i]].address, nodes[ordered[i]].data);
    if (i + 1 < pos) {
      printf("%05d\n", nodes[ordered[i+1]].address);
    }
    else printf("-1\n");
  }
}
