/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = function(nums) {
    let ans = 0;
    nums.forEach(num => {
       ans^=num; 
    });
    return ans;
};
