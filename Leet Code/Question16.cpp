class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = pow(10,5);
        int output;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int absDiff = abs(sum - target);

                if (absDiff < diff) {
                    diff = absDiff;
                    output = sum;
                }

                 if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return output;
    }
};
