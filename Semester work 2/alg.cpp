#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// проверка графа на цикличность
bool cyclic(int v, int &cycle_st, vector<int> *graph, vector<int> &color)
{
    color[v] = 1;
    for (size_t i = 0; i < graph[v].size(); ++i)
    {
        int to = graph[v][i];
        if (color[to] == 0) // если в вершину не входили ни разу
        {
            if (cyclic(to, cycle_st, graph, color))
                return true;
        }
        else if (color[to] == 1) // если в указанную вершину ранее входили, то значит, что найден цикл
        {
            cycle_st = to; // меняем значение индикатора
            return true;
        }
    }
    color[v] = 2; // указываем, что в вершину больше ни разу входить не будем
    return false;
}

void dfs(int v, vector<int> *graph, vector<bool> &used, vector<int> &answer)
{
    used[v] = true; // указываем, что использовали данную вершину
    for (int i = 0; i < graph[v].size(); i++)
    {
        int to = graph[v][i]; // по списку проходим по всем вершинам, к которым можно пройти от вершины v
        if (!used[to])        // и если вершину не рассматривали, то применяем алгоритм поиска в глубину для неё
            dfs(to, graph, used, answer);
    }
    answer.push_back(v + 1); // заносим вершину в вектор, хранящий результат
}

void topologicalSort(int n, vector<int> *graph, vector<bool> &used, vector<int> &answer)
{
    for (int i = 0; i < n; i++) // указываем, что ни одна вершина не была использована
        used[i] = false;
    for (int i = 0; i < n; i++)
        if (!used[i])                    // если в ходе предыдущий операций вершина не использовалась
            dfs(i, graph, used, answer); // то вызываем для неё алгоритм поиска в глубину
    reverse(answer.begin(), answer.end());
}

int main()
{
    int n, m; // число вершин и ребер
    cin >> n >> m;
    vector<int> graph[n]; // граф
    vector<bool> used(n);
    vector<int> answer;
    vector<int> color(n, 0); // массив, хранящий кол-во посещений для данной вершины.

    int cycle_st = -1;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    cout << "----- GRAPH -----" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] + 1 << " ";
        cout << endl;
    }
    cout << "-----------------" << endl;

    for (int i = 0; i < n; i++)
    {
        if (cyclic(i, cycle_st, graph, color)) // проверка графа на ацикличность
            break;
    }
    if (cycle_st != -1)
    {
        cout << "-1";
    }
    else
    {
        topologicalSort(n, graph, used, answer);
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}