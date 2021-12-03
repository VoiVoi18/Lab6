#include<iostream>
#include<vector>
#include<queue>
#include <locale.h>
using namespace std;
int n, m;
int dist[100];
vector<int> adjList[100];
queue<int> q;

void dfs(int N)
{
    for (int i = 1; i <= n; i++)
    {
        if (n != 1)
        {
            dist[i] = -1;
        }
    }
    
   int v = adjList[N][N+1];
   dist[v] = dist[N] + 1;
   cout << v;
    for (int j = 0; j < adjList[N].size(); j++)
        {
          
         
          dfs(N);
                
        }
}
void DFS_rec(int num)//обход графа в глубину
{
    
    dist[num] = dist[num]+ 1;
    printf("%d ", num);
    for (int i = 0; i < adjList[num].size(); i++) {
        if (dist[i] == 0 ) {
            DFS_rec(i);
        }
    }
}

void bfs(int N) {
    for (int i = 0; i <= n; i++)
    {
        if (n != 1)
        {
            dist[i] = -1;
        }
    }
    dist[N] = 0;
    q.push(N);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x ;
        for (int j = 0; j < adjList[x].size(); j++)
        {
            int v = adjList[x][j];
            if (dist[v] == -1) {
                dist[v] = dist[x] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int N;
    srand(time(NULL));
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество ребер: ";
    cin >> m;
    int x, y;
    for (int i = 0; i <= m; i++)
    {
        cin >> x;
        cin >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << " -->";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    cout << "С какой вершины начать обход? ";
    cin >> N;
    for (int i = 0; i <= n; i++)
    {
        if (n != 1)
        {
            dist[i] = -1;
        }
    }

    dfs(N);
    for (int i = 0; i <= n; i++)
    {
        cout << "Вершина " << i;
        cout << " Расстояние " << dist[i];
        cout << endl;
    }
    bfs(N);
    for (int i = 0; i <= n; i++)
    {
        cout << "Вершина " << i;
        cout << " Расстояние " << dist[i];
        cout << endl;
    }
    return 0;
}