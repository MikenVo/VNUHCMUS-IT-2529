#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{

    int s = 0;

    sort(nums.begin(), nums.end());

    int c = 0;

    while (c < nums.size()) {
        if (nums[c] == nums[c + 1])
        {
            s = c+1;
            nums.erase(nums.begin() + s);
            c--;
        }
        
        c++;
    }

    return nums.size();
}

int main() {
    vector<int> nums;
    int n; cin >> n;
    int val;

    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    int newn = removeDuplicates(nums);
    
    for (int i = 0; i < newn; i++) {
        cout << nums[i];
    }

    return 0;
}