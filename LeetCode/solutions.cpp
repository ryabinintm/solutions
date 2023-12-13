#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <vector>

std::vector<int> two_sum(const std::vector<int> &nums, int target) {
  std::unordered_map<int, int> num_index;
  int complement;
  for (int i = 0; i < nums.size(); i++) {
    complement = target - nums[i];
    if (num_index.find(complement) != num_index.end()) {
      return {num_index[complement], i};
    }
    num_index[nums[i]] = i;
  }
  return {};
}

int max_profit(std::vector<int>& prices) {
  int min_price = prices[0];
  int maxprof = 0;
  for (int i = 1; i < prices.size(); i++) {
    maxprof = std::max(maxprof, prices[i]-min_price);
    min_price = std::min(prices[i], min_price);
  }
  return maxprof;
}

std::vector<int> product_except_self(std::vector<int> &nums) {
  std::vector<int>res(nums.size(), 1);
  for(int i = 1; i < nums.size(); i++)
    res[i] = res[i-1] * nums[i-1];
  int right = 1;
  for(int i = nums.size() - 1; i >= 0; i--){
    res[i] *= right;
    right *= nums[i];
  }
  return res;
}

int max_sub_array(std::vector<int>& nums) {
  int maxSum = nums[0];
  int currentSum = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    currentSum = std::max(nums[i], currentSum + nums[i]);
    maxSum = std::max(maxSum, currentSum);
  }
  return maxSum;
}
