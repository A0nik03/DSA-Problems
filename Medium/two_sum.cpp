#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> brute_loops(vector<int> &nums, int target)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }

    vector<int> better_hash(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int more = target - nums[i];
            if (mpp.find(more) != mpp.end())
            {
                ans.push_back(i);
                ans.push_back(mpp[more]);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }

    bool optimal_twopoint(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                return true;
            }
            else if (nums[i] + nums[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        return better_hash(nums, target);
    }
};