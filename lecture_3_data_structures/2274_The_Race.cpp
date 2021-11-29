#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int bit[100001], a[100001];//bit -- binary indexed tree
int lowBit(int x){
    return x & (-x);
}
void add(int idx, int size, int val){
    while (idx <= size){
        bit[idx] += val;
        idx += lowBit(idx);
    }
}
int sum(int idx){
    int ret = 0;
    while (idx > 0){
        ret += bit[idx];
        idx -= lowBit(idx);
    }
    return ret;
}
struct Edge{
    int v, next;
}edge[200001];
int edgeNum, head[100001];
void addEdge(int u, int v){
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}
int posMap[100001][2], counter;
void dfs(int u){
    posMap[u][0] = ++counter;
    for (int i = head[u]; i != -1; i = edge[i].next){
        if (posMap[edge[i].v][0] == -1){
            dfs(edge[i].v);
        }
    }
    posMap[u][1] = counter;
}
int main(){
    int n, m;
    while (~scanf("%d", &n)){
        int u, v;
        edgeNum = 0;
        fill(head + 1, head + 1 + n, -1);
        for (int i = 1; i <= n; i++){
            bit[i] = lowBit(i);
            a[i] = 1;
        }
        for (int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        for (int i = 1; i <= n; i++){
            posMap[i][0] = -1;
        }
        counter = 0;
        dfs(1);
        scanf("%d", &m);
        char op;
        int k;
        for (int i = 0; i < m; i++){
            scanf("%*c%c%d", &op, &k);
            if (op == 'Q'){
                printf("%d\n", sum(posMap[k][1]) - sum(posMap[k][0] - 1));
            }
            else{
                if (a[posMap[k][0]]){
                    add(posMap[k][0], n, -1);
                }
                else{
                    add(posMap[k][0], n, 1);
                }
                a[posMap[k][0]] = 1 - a[posMap[k][0]];
            }
        }
    }
    return 0;
}