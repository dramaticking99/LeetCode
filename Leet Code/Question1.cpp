class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>value;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            if(value[nums[i]] != 0 ){
                result.push_back(value[nums[i]]-1);

                result.push_back(i);
                break;
            } 
            value[target-nums[i]] = i+1 ; 

        }

        return result;
    }
};
