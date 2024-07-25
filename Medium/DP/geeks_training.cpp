// Geek's Training

/*
Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f_memo(vector<vector<int>>& points,int day,int last,vector<vector<int>> &dp){
        if(day == 0){
            int maxi = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    maxi = max(maxi,points[0][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                int point = points[day][task] + f_memo(points,day - 1,task,dp);
                maxi = max(maxi,point);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int f_tabu(vector<vector<int>>& points,int n){
        vector<vector<int>> dp(n , vector<int> (4, - 1));
        
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][2], points[0][0]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));
        
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        int point = points[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last],point);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
       return f_tabu(points,n);
    }
};