#include <iostream>
using namespace std;

class graph
{
    bool **matrix;
    int N;

public:
    graph(int _N = 0)
    {
        N=_N;
        matrix = new bool *[N];
        for (int i = 0; i < N; i++)
        {
            matrix[i] = new bool[N];
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                matrix[i][j] = false;
        }
    }
    void addEdge(int start, int end)
    {
        start--;end--;
        if (matrix[start][end] == 0)
        {
            matrix[start][end] = true;
        }
        else if (matrix[end][start] == 0)
        {
            matrix[end][start] = true;
        }
        else
        {
            cout << "Connection already established!\n";
        }
    }
    void removeEdge(int start, int end)
    { start--;end--;
        if (matrix[start][end])
        {
            matrix[start][end] = false;
        }
        else if (matrix[end][start])
        {
            matrix[end][start] = false;
        }
        else
        {
            cout << "Connection doesn't exist!\n";
        }
    }

    void print()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i + 1 << " : ";
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j])
                    cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.print();
    g.removeEdge(4,5);
    g.print();
    return 0;
}