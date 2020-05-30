/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let mx = 0 , now = 10000000;
    for(const price of prices){
        if(price>now){
            mx = Math.max(mx , price-now);
        }
        now = Math.min(now , price);
    }
    return mx;
};