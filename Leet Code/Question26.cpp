class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int i = 0;

        while(i < nums.size()){
            if(nums[index] != nums[i]){
                index++;
                nums[index]= nums[i];
                i++;
            } else {
                i++;
            }
        }

        return (index + 1);
    }
};
