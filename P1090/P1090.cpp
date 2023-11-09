#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4 + 5;

template <typename T>
class smallestHeap
{
private:
    T heap[N];
    int len;

public:
    smallestHeap();
    void push(T const &n);
    void pop();
    T top();
    int size();
    bool empty();
};

template <typename T>
smallestHeap<T>::smallestHeap()
{
    len = 0;
    memset(heap, 0, sizeof heap);
}

template <typename T>
void smallestHeap<T>::push(T const &n)
{
    heap[++len] = n;
    int son = len, father = son >> 1;
    while (heap[son] < heap[father] && father >= 1)
    {
        swap(heap[son], heap[father]);
        son = father, father = son >> 1;
    }
}

template <typename T>
void smallestHeap<T>::pop()
{
    swap(heap[1], heap[len]);
    heap[len--] = 0;
    int father = 1, son = 2;
    while (son <= len)
    {
        if (son < len && heap[son] > heap[son + 1])
            son++;
        if (heap[father] > heap[son])
        {
            swap(heap[father], heap[son]);
            father = son,
            son = father << 1;
        }
        else
            break;
    }
}

template <typename T>
T smallestHeap<T>::top()
{
    return heap[1];
}

template <typename T>
int smallestHeap<T>::size()
{
    return len;
}

template <typename T>
bool smallestHeap<T>::empty()
{
    return !len;
}

smallestHeap<int> h;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        h.push(x);
    }
    while (h.size() > 1)
    {
        int x = h.top();
        h.pop();
        int y = h.top();
        h.pop();
        h.push(x + y);
        ans += x + y;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
