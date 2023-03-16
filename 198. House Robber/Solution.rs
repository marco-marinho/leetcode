use std::cmp;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut taps = [0, 0, 0];
        for num in &nums {
            let buff = cmp::max(taps[2], taps[1]) + num;
            taps[2]= taps[1];
            taps[1] = taps[0];
            taps[0] = buff;
        }
        return cmp::max(taps[0], taps[1]);
    }
}