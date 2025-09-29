#include <iostream>
using namespace std;

int grid[20][20];
int n;

bool safe(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (grid[i][c] == 1)
        {
            return false;
        }
    }
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void show()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int r)
{
    if (r == n)
    {
        show();
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (safe(r, c))
        {
            grid[r][c] = 1;
            solve(r + 1);
            grid[r][c] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }
    solve(0);
    return 0;
}
