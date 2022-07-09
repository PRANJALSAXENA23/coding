410. Split Array Largest Sum
// Hard

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.
Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
    int low=0, high=0;
        
        for(int i=0; i<nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        
        while(low <= high){
            int mid = (low+high)/2, count = 1, temp_sum=nums[0];
            for(int i=1; i<nums.size(); i++){
                if(temp_sum + nums[i] > mid){
                    count++;
                    temp_sum = nums[i];
                }
                else
                    temp_sum += nums[i];
            }
            
            if(count> m)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return low;
        
    }
};