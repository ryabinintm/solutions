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

int max_profit(vector<int>& prices) {
  int min_price = prices[0];
  int maxprof = 0;
  for (int i = 1; i < prices.size(); i++) {
    maxprof = max(maxprof, prices[i]-min_price);
    min_price = min(prices[i], min_price);
  }
  return maxprof;
}
