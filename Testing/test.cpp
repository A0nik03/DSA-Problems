#include <bits/stdc++.h>
using namespace std;
int peek(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    cout << "Start: " << endl;
    if (n == 1)
        return 0;
    cout << "Start: " << endl;
    if (arr[0] > arr[1])
        return 0;
            cout << "Start: " << endl;
    if (arr[n - 1] < arr[n - 2])
        return n - 2;


    cout << "bjb;" << endl;
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            cout << mid << endl;
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        cout << "out: " << mid << endl;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 13, 5, 6, 7, 8};
    cout << "Size: " << arr.size() << endl;
    int ans = peek(arr);

    cout << ans << endl;
}
