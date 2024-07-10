//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        int largest = 0, secondLargest = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[largest])
            {
                secondLargest = largest;
                largest = i;
            }
            else if (arr[i] < arr[largest] && (secondLargest == -1 || arr[i] > arr[secondLargest]))
            {
                secondLargest = i;
            }
        }
        return largest;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends