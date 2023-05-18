#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 5; // Максимальное число вершин в графе

int graph[MAXN][MAXN];

void findNeighbors(int curr, bool* visited, int currDist, vector<int>& result, int* dist);

vector<int> threeHandshakes(int src)
{
    vector<int> result; // Результат, список вершин, находящихся на расстоянии не более 3 от src
    bool visited[MAXN] = {false};
    int dist[MAXN] = {0};
    visited[src] = true;
    for(int i=0; i<MAXN; i++)
        dist[i] = 9999; // Расстояние до всех вершин из src обнуляется
    dist[src] = 0;
    for(int i=0; i<MAXN; i++)
        if(graph[src][i] && !visited[i])
            findNeighbors(i, visited, 1, result, dist); // Ищем соседние вершины на расстоянии 1 от src
    return result;
}

void findNeighbors(int curr, bool* visited, int currDist, vector<int>& result, int* dist)
{
    visited[curr] = true; // Помечаем текущую вершину, как посещенную
    if(currDist>3)
        return; // дошли до конца
    if(currDist<=3)
        result.push_back(curr); // Добавляем в результат
    for(int i=0; i<MAXN; i++)
        if(graph[curr][i] && !visited[i])
            if(dist[i]>currDist+1)
                findNeighbors(i, visited, currDist+1, result, dist); // Ищем соседние вершины на расстоянии currDist+1 от src
}

int main()
{
    // Заполняем матрицу смежности
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            graph[i][j]=0;
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;
   

    for(int i=0; i<MAXN; i++)
    {
        vector<int> list = threeHandshakes(i);
        cout<<"Vertice: "<<i<<". List of vertices with distance <= 3 from it: ";
        for(int j=0; j<list.size(); j++)
            cout<<list[j]<<" ";
        cout<<endl;
    }
    return 0;
}