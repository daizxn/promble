#include <iostream>
using namespace std;

struct peo
{
    int id;
    peo *front;
    peo *next;
    peo()
    {
        front = next = nullptr;
    }
    void cut()
    {
        front->next = next;
        next->front = front;
    }
};

peo n[105];

int main()
{
    std::ios::sync_with_stdio(false);
    int tot, out_num, now_num = 1;
    peo *now = n;
    cin >> tot >> out_num;
    for (int i = 1; i < tot - 1; i++)
    {
        n[i].front = n + i - 1;
        n[i].next = n + i + 1;
        n[i].id = i + 1;
    }
    n[0].front = n + tot - 1;
    n[0].next = n + 1;
    n[0].id = 1;
    n[tot - 1].front = n + tot - 2;
    n[tot - 1].next = n;
    n[tot - 1].id = tot;
    while (tot > 0)
    {
        if (now_num == out_num)
        {
            cout << now->id << ' ';
            now_num = 1;
            now->cut();
            tot--;
            now = now->next;
        }
        else
        {
            now_num++;
            now = now->next;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}