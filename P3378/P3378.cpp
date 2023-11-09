#include <iostream>
#include <algorithm>

const int N = 1e6 + 5;

int heap[N];
int cnt = 0;

void put(int x);
void del();
int get();

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int op;
        std::cin >> op;
        switch (op)
        {
        case 1:
            int x;
            std::cin >> x;
            put(x);
            break;
        case 2:
            std::cout << get() << std::endl;
            break;
        case 3:
            del();
            break;
        }
    }
    system("pause");
    return 0;
}

void put(int x)
{
    int now, nex;
    heap[++cnt] = x;
    now = cnt;
    while (now > 1)
    {
        nex = now >> 1;
        if (heap[now] >= heap[nex])
            return;
        std::swap(heap[now], heap[nex]);
        now = nex;
    }
    return;
}
void del()
{
    int now, nex;
    heap[1] = heap[cnt--];
    now = 1;
    while (now * 2 <= cnt)
    {
        nex = now * 2;
        if (nex < cnt && heap[nex + 1] < heap[nex])
            nex++;
        if (heap[now] <= heap[nex])
            return;
        std::swap(heap[now], heap[nex]);
        now = nex;
    }
    return;
}
int get()
{
    return heap[1];
}