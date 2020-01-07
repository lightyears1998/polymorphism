// 月饼

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int N, D;

struct Cake
{
  int stock, price;
  bool operator < (const Cake & cake) const
  {
    return double(price) / stock > double(cake.price) / cake.stock;
  }
} cakes[MAXN];

signed main()
{
  cin >> N >> D;

  for (int i = 0; i < N; ++i)
  {
    cin >> cakes[i].stock;
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> cakes[i].price;
  }
  sort(cakes, cakes+N);

  double tot = 0;
  for (int cur = 0; cur < N && D; ++cur)
  {
    int sold = min(D, cakes[cur].stock);
    if (sold == cakes[cur].stock) {
      tot += cakes[cur].price;
    }
    else tot += cakes[cur].price * (double(sold) / cakes[cur].stock);
    D -= sold;
  }
  printf("%.2f\n", tot);
}
