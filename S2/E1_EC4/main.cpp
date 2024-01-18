#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        multiset<pair<int, int>, greater<pair<int, int>>> s;
        for (const auto& p : count) {
            s.insert({p.second, p.first});
            if (s.size() > k) {
                s.erase(prev(s.end()));
            }
        }

        vector<int> result;
        for (const auto& p : s) {
            result.push_back(p.second);
        }

        return result;
    }
};


void test(){
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = {1,2};
    assert(Solution().topKFrequent(nums, 2) == ans);

    nums = {1};
    ans = {1};
    assert(Solution().topKFrequent(nums, 1) == ans);

    nums = {1,1,4,4,2,4,3,3,3,3};
    ans = {3,4};
    assert(Solution().topKFrequent(nums, 2) == ans);

    nums = {1,7,4,4,1,4,3,7,3,3,1};
    ans = {3,4,1};
    assert(Solution().topKFrequent(nums, 3) == ans);
}

int main(){
    test();
    return 0;
}
