
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;
    map<T, int> bvisited;
    map<T, int> dvisited;
    queue<T> q;
    stack<T> s;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        // q.push(src);F
        bvisited[src] = true;
        if (bvisited[src])
        {
            cout << "," << src;
        }

        for (int nbr : l[src])
        {
            if (!bvisited[nbr])
            {
                q.push(nbr);
                bvisited[nbr] = true;
            }
        }

        q.pop();
        if (q.empty())
            return;

        bfs(q.front());
    }

    void bfsM(T src)
    {
        q.push(src);

        bfs(src);
    }

    void dfs(T src)
    {
        s.push(src);

        T node = s.top();
        s.pop();

        if (!dvisited[node])
        {
            cout << node << ",";
            dvisited[node] = true;
        }

        for (int nbr : l[node])
        {
            if (!dvisited[nbr])
            {
                s.push(nbr);
            }
        }

        if (s.empty())
            return;

        dfs(s.top());
    }
};

int main()
{
    // while (true)
    // {
    //     cout << "\n-----------BSF AND DFS----------" << endl;
    //     char doit;
    //     cout << "press 'y' to create new graph...else anything(char)" << endl;
    //     cin >> doit;
    //     if (doit == 'y')
    //     {
    //         Graph<int> g;
    //         while (true)
    //         {
    //             char yes;
    //             int i, j;
    //             cout << "want to add edge?" << endl;
    //             cin >> yes;
    //             if (yes == 'y')
    //             {
    //                 cout << "enter edge:";
    //                 cin >> i >> j;
    //                 g.addEdge(i, j);
    //             }
    //             if (yes != 'y')
    //             {
    //                 break;
    //             }
    //         }
    //         int startNode;
    //         cout << "Enter start node: ";
    //         cin >> startNode;
    //         cout << "BFS: ";
    //         g.bfsM(startNode);
    //         cout << "\n"
    //              << endl;
    //         cout << "DFS: ";
    //         g.dfs(startNode);
    //     }else{
    //         break;
    //     }
    // }

    Graph<int> g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 5);

    g.bfsM(1);
    cout << '\n';

    g.dfs(1);

    return 0;
}