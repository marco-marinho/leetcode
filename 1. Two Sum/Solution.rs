impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for idx in 0..nums.len(){
            let better_half = target - nums[idx];
            for idx_2 in idx+1..nums.len(){
                if nums[idx_2] == better_half{
                    return vec![idx as i32, idx_2 as i32];
                }
            }
        }
        return vec![-1, -1];
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::two_sum(vec![2,7,11,15], 9), vec![0,1]);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::two_sum(vec![3,2,4], 6), vec![1,2]);
    }
    #[test]
    fn exp3() {
        assert_eq!(Solution::two_sum(vec![3,3], 6), vec![0,1]);
    }
}