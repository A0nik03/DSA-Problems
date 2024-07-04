#include <bits/stdc++.h>
using namespace std;

bool canEscape(int i, int j, int h, int k)
{
    int step = 0;
    for (int m = 0;m < k; ++m)
    {
        step += i;
        if (step >= h)
        {
            return true;
        }
        step -= j;
        if (step < 0)
        {
            step = 0;
        }
    }
    return step >= h;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, h;
        cin >> n >> k >> h;

        vector<pair<int, int>> arr;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(canEscape(i,j,h,k))
                {

                    arr.push_back({i ,j});
                }
            }
        }
        
        for (auto it : arr)
        {
            cout << "{" << it.first << "," << it.second << "} ,";
        }
        cout << arr.size() << endl;
    }
}
