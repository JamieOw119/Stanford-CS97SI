#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 10100;
struct Point
{
    int x;
    int y1;
    int y2;
    int flag;
    bool operator<(const Point &a) const
    {
        return x < a.x;
    }
} p[maxn];
struct Tree
{
    int l;      //记录左边
    int r;      //记录右边
    int len;    //区间长度
    int segnum; //区间被分成的段数
    int cover;  //区间覆盖总数
    int sum;    //区间覆盖总长
    bool lcover, rcover;
    void Clear()
    {
        len = segnum = cover = sum = lcover = rcover = 0;
    }
} t[maxn * 3];
int n, m, len, py[maxn], y[maxn];
int Search(int val)
{
    int l = 1, r = len;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (y[mid] == val)
            return mid;
        if (y[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
}
void Build(int l, int r, int index)
{
    t[index].Clear();
    t[index].l = l;
    t[index].r = r;
    t[index].len = y[r] - y[l];
    if (l + 1 == r)
        return;
    int mid = (l + r) >> 1;
    Build(l, mid, index << 1);
    Build(mid, r, index << 1 | 1);
}
void UpdateNode(int index)
{
    if (t[index].cover > 0)
    {
        t[index].sum = t[index].len;
        t[index].lcover = t[index].rcover = true;
        t[index].segnum = 1;
    }
    else if (t[index].r - t[index].l > 1)
    {
        t[index].sum = t[index << 1].sum + t[index << 1 | 1].sum;
        t[index].lcover = t[index << 1].lcover;
        t[index].rcover = t[index << 1 | 1].rcover;
        t[index].segnum = t[index << 1].segnum + t[index << 1 | 1].segnum - t[index << 1].rcover * t[index << 1 | 1].lcover; //最后减去的是中间可能的重复计算边
    }
    else
    {
        t[index].lcover = t[index].rcover = 0;
        t[index].segnum = 0;
        t[index].sum = 0;
    }
}
void Update(int l, int r, int val, int index)
{
    if (t[index].l == l && t[index].r == r)
    {
        t[index].cover += val;
        UpdateNode(index);
        return;
    }
    int mid = (t[index].l + t[index].r) >> 1;
    if (r <= mid)
        Update(l, r, val, index << 1);
    else if (l >= mid)
        Update(l, r, val, index << 1 | 1);
    else
    {
        Update(l, mid, val, index << 1);
        Update(mid, r, val, index << 1 | 1);
    }
    UpdateNode(index);
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        m = 1;
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            p[m].x = x1;
            p[m].y1 = y1;
            p[m].y2 = y2;
            p[m].flag = 1;
            py[m++] = y1;
            p[m].x = x2;
            p[m].y1 = y1;
            p[m].y2 = y2;
            p[m].flag = -1;
            py[m++] = y2;
        }
        sort(py + 1, py + m);
        sort(p + 1, p + m);
        len = 1;
        y[1] = py[1];
        for (int i = 2; i < m; i++)
            if (py[i] != py[i - 1])
                y[++len] = py[i];
        Build(1, len, 1);
        int ans = 0, last = 0;
        for (int i = 1; i < m - 1; i++)
        {
            int a = Search(p[i].y1);
            int b = Search(p[i].y2);
            if (p[i].flag == 1)
                Update(a, b, 1, 1);
            else
                Update(a, b, -1, 1);
            ans += t[1].segnum * (p[i + 1].x - p[i].x) * 2;
            ans += abs(t[1].sum - last);
            last = t[1].sum;
        }
        int a = Search(p[m - 1].y1);
        int b = Search(p[m - 1].y2);
        Update(a, b, -1, 1);
        ans += abs(t[1].sum - last);
        printf("%d\n", ans);
    }
    return 0;
}