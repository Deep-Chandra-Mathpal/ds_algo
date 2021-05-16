#include <iostream>
int nv = 9, ne = 14;
int cal_w = 0;
int v[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
int mst_e[8];
class edges
{
public:
    int u, v, w;
    void edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    void display()
    {
        std::cout << "  u : " << this->u << ",  v : " << this->v << ",  w : " << this->w << "\n";
    }
};
edges e[14];
int main()
{
    void kruskal(edges d[]);
    void quick_sort(edges e[], int st, int en);
    e[0].edge(0, 1, 4);
    e[1].edge(0, 7, 8);
    e[2].edge(1, 2, 8);
    e[3].edge(1, 7, 11);
    e[4].edge(2, 3, 7);
    e[5].edge(2, 8, 2);
    e[6].edge(2, 5, 4);
    e[7].edge(3, 4, 9);
    e[8].edge(3, 5, 14);
    e[9].edge(4, 5, 10);
    e[10].edge(5, 6, 2);
    e[11].edge(6, 8, 6);
    e[12].edge(6, 7, 1);
    e[13].edge(7, 8, 7);
    quick_sort(e, 0, 13);
    kruskal(e);
    std::cout << "\n total minimum weight is " << cal_w<<"\n\n";
    std::cout << " edges of minimum spanning tree are - \n\n";
    for (int i = 0; i < 8; i++)
        e[mst_e[i]].display();
    std::cout << "\n";
    return 0;
}

int e_partition(edges e[], int st, int en)
{
    int pivot = e[en].w;
    int partition_index = st;
    for (int i = st; i <= en; i++)
    {
        if (e[i].w <= pivot)
        {
            edges temp = e[partition_index];
            e[partition_index] = e[i];
            e[i] = temp;
            partition_index++;
        }
    }
    return --partition_index;
}
void quick_sort(edges e[], int st, int en)
{
    if (st >= en) return;
    int pi = e_partition(e, st, en);
    quick_sort(e, st, pi - 1);
    quick_sort(e, pi + 1, en);
}
int parent(int x)
{
    while (v[x] >= 0)
    {
        x = v[x];
    }
    return x;
}
void kruskal(edges e[])
{
    int t = 7, i = 0;
    while (t >= 0)
    {
        int p1 = parent(e[i].u);
        int p2 = parent(e[i].v);
        if (p1 != p2)
        {
            if (v[p1] <= v[p2])
            {
                v[p1] = v[p1] + v[p2];
                v[p2] = p1;
            }
            else
            {
                v[p2] = v[p2] + v[p1];
                v[p1] = p2;
            }
            mst_e[7 - t] = i;
            cal_w += e[i].w;
            t--;
        }
        i++;
    }
}
