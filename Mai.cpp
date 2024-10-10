#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& current, int index) {
    subsets.push_back(current);
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        findSubsets(nums, subsets, current, i + 1);
        current.pop_back();
    }
}

vector<vector<int>> getSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current;
    findSubsets(nums, subsets, current, 0);
    return subsets;
}

int sumOfSubsets(vector<vector<int>>& subsets) {
    int sum = 0;
    for (const auto& subset : subsets) {
        for (int num : subset) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3}; // input set of integers
    vector<vector<int>> subsets = getSubsets(nums);
    int sum = sumOfSubsets(subsets);
    cout << "Sum of all subsets: " << sum << endl;
    return 0;
}
