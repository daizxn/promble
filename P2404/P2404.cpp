#include <iostream>

using namespace std;

int a[100005],n;

void dfs(int x, int size);
void print(int size);

int main()
{
    cin >> n;
    a[0] = 1;
    dfs(n, 1);
    return 0;
}

void dfs(int x, int size)
{
    for (int i = a[size - 1]; i <= x; i++)
    {
        if(i<n){
            x -= i;
            a[size] = i;
            if (x == 0)
                print(size);
            else
                dfs(x, size + 1);
            x += i;
        }
    }
    return;
}
void print(int size)
{
    for (int i = 1; i < size; i++)
        cout << a[i] << '+';
    cout << a[size] << endl;
    return;
}