/*
* Tim kiem theo chieu sau
*   la mot dang thuat toan duyet hoac tim kiem tren cay do thi. Nam trong tim kiem mu.
*       (tim kiem khong co dinh huong, khong chu y den thong tin, gia tri duoc duyet)
*
*Thuat toan:
*    - Xuat phat tu 1 dinh va di mai cho den khi khong di tiep, sau do di ve lai dinh dau
*    Trong qua trinh quay lai:
*        - neu gap duong di khac thi di cho den khi khong di duoc nua
*        - neu khong tim thay duong di nao khac thi dung viec tim kiem
*/

#include <stdio.h>
#include <stack>

using namespace std;

class Graph
{
private:
    int n;
    int **edge;
public:
    Graph(int size = 2);
    ~Graph();

    bool isConnected(int, int);
    void addEdge(int x, int y);
    void depthFirstSearch(int, int);
};

Graph::Graph(int size)
{
    /* xac dinh so dinh cua do thi */
    if(size < 2)
    {
        n = 2
    }
    else 
    {
        n = size;
    }

    /* tao ra cac dinh trong do thi */
    edge = new int*[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    for(int i = 0; i < n; i++)
    {
        delete edge[i];
    }
    
    delete[] edge;
}

/* kiem tra 2 dinh co ke nhau hay khong */
bool Graph::isConnect(int x, int y)
{
    if (edge[x - 1][y - 1] == 1) {
        return true;
    }

    return false;    
}

/* them canh noi dinh x va y */
void Graph::addEdge(int x, int y)
{
    if ((x < 1) || (x > n) || (y < 1) || (y > n)) {
        printf("error x and y\n");
        return;
    }
    edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1; /* noi 2 dinh bang gia tri bang 1 */
}

void Graph::deptFirstSearch(int s, int g)
{
    if ((s > n) || (s < 0) || (g > n) || (g < 0))
    {
        printf("Could not traverse this graph with your request\n");
        return;
    }

    stack <int> open;
    bool *close = new bool[n];
    int n;
    int p;

    /* mac dinh cac dinh chua duoc duyet */
    for(int i = 0; i < n; i++)
    {
        close[i] = false;
    }

    /* dua dinh goc s vao stack open, chuan bi duyet */
    open.push(s);

    printf("With Depth first search, we have vertex(s): \n");

    while(!open.empty())
    {
        /* lay mot dinh ra khoi open tro thanh dinh dang xet p */
        do {
            if (open.empty())
            {
                return;
            }
            p = open.top();
            open.pop();
        } while(close[p - 1] == true);

        /* in dinh dang xet */
        printf("p: %d\n", p);

        /* p da duyet qua */
        close[p - 1] = true;

        /* ket thuc duyet khi tim ra ket qua can tim */
        if (p == g) {
            return;
        }
        
        /* tim dinh ke voi dinh dang xet, dinh nao chua duoc duyet dua vao open */
        for(int i = 1; i < n; i++)
        {
            if(isConnected(p,i) && close[i - 1])
            {
                open.push(i);
            }
        }
    }
    printf("\n");
    delete[] close;
}

int main(int argc, char ** argv)
{
    Graph initial_value(8);

    intial_value.addEdge(1, 2);
    intial_value.addEdge(1, 3);
    intial_value.addEdge(1, 4);
    intial_value.addEdge(1, 5);
    intial_value.addEdge(2, 6);
    intial_value.addEdge(3, 4);
    intial_value.addEdge(3, 8);
    intial_value.addEdge(4, 8);
    intial_value.addEdge(5, 8);
    intial_value.addEdge(6, 7);
    intial_value.addEdge(6, 8);

    initial_value.deptFirstSearch(1, 4);
}