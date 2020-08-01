/**
 * @param {number[]} digits
 * @return {number[]}
 */
const plusOne = function(digits) {
    let now = 0;
    digits.forEach(digit => {
        now = BigInt(BigInt(now) * BigInt(10));
        now = BigInt(BigInt(now) + BigInt(digit));
    });
    now++;
    const ans = [];
    while(now>0){
        ans.push(BigInt(now)%BigInt(10));
        now = BigInt(BigInt(now)/BigInt(10));
        if(now===0)break;
    }
    return ans.reverse();
};
