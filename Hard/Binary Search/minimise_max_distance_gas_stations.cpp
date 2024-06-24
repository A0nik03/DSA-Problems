// Minimize Max Distance to Gas Station

/*
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // Brute
    long double findSmallestMaxDist_Brute(vector<int> &stations, int k) {
        vector<int> howMany(stations.size() - 1,0);
        
        for(int i = 1; i <= k; i++){
            long double max_section = -1;
            int maxInd = -1;
            for(int i = 0; i < stations.size() - 1; i++){
                long double diff = stations[i + 1] - stations[i];
                long double sectionLength = diff/(long double)(howMany[i] + 1);
                if(sectionLength > max_section){
                    max_section = sectionLength;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        long double maxAns = 0;
        
        for(int i = 0 ; i < stations.size() - 1; i++){
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff/(long double)(howMany[i] + 1);
            maxAns = max(maxAns,sectionLength);
        }
        return maxAns;
    }
    
    // Better(Hashing --> Priority Queue)
    long double findSmallestMaxDist_Better(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n - 1,0);
        priority_queue<pair<long double,int>> pq;
        
        for(int i = 0; i < n - 1; i++){
            pq.push({stations[i + 1] - stations[i],i});
        }
        
        for(int i = 1; i <= k; i++){
            
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            
            howMany[secInd]++;
            
            long double inidiff = stations[secInd + 1] - stations[secInd];
            long double sectionLength = inidiff/(long double)(howMany[secInd] + 1);
            pq.push({sectionLength,secInd});
             
        }
        
        
    return pq.top().first;
    }
    
    // Optimal
    
    int check(vector<int> &v,double dist) {
        int cnt = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            cnt += ceil((v[i + 1] - v[i]) / dist) - 1;
        }
        return cnt;
    }

    double findSmallestMaxDist(vector<int> &stations, int K) {
        double low = 0;
        double high = stations.back() - stations.front();
        
        
        
        while(high - low > 1e-6){
            double mid = low + (high - low)/2.0;
            int cnt = check(stations,mid);
            if(cnt > K){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends