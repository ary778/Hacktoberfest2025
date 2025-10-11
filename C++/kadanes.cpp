/*
    Problem: Maximum Subarray Sum (Kadane’s Algorithm)
    Difficulty: Medium
    Topic: Dynamic Programming, Greedy

    --------------------------------------------
    Problem Statement:
    Given an integer array nums, find the contiguous subarray 
    (containing at least one number) which has the largest sum.

    --------------------------------------------
    Input:
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

    Output:
    6
    Explanation:
    [4, -1, 2, 1] has the largest sum = 6.

    --------------------------------------------
    Approach:
    - Use Kadane’s algorithm.
    - Keep track of current_sum and max_sum.
    - Reset current_sum when it becomes negative.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int curr_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        curr_sum = max(nums[i], curr_sum + nums[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}
