/* POJ3251 Big Square */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200;
char b[N + 1][N + 1];

inline bool judge(int a, int b, int c, int d)
{
    return a >= 0 && b >= 0 && c >= 0 && d >= 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
        scanf("%s", b[i] + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != 'B')
                for (int k = n; k >= 1; k--)
                    for(int l = n; l >= j; l--) {
                        int p = k - i;
                        int q = l - j;
                        if (p * p + q * q <= ans) continue;
                        if (b[k][l] == 'B' || (b[k][l] == b[i][j] && b[i][j] != 'J'))
                            continue;
                        if ((b[i - q][j + p] == 'J' && b[k - q][l + p] == 'J' && judge(i - q, k - q, j + p, l + p)) ||
                                (b[i + q][j - p] == 'J' && b[k + q][l - p] == 'J' && judge(j - p, l - p, k + q, i + q)))
                            ans = p * p + q * q;
                    }

  printf("%d\n", ans);

  return 0;
}
