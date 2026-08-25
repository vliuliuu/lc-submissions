class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> result(2);
        int left = 0;
        int right = numbers.size()-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                result[0] = left + 1;
                result[1] = right + 1;
                return result;
            }
            else if(sum < target){
                left++;
            }
            else {
                right--;
            }
        }
    }
};
