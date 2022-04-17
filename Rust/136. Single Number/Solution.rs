impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut output = 0;
        for num in &nums {
            output ^= num;
        }
        output
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::single_number(vec![2,2,1]), 1);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::single_number(vec![4,1,2,1,2]), 4);
    }
    #[test]
    fn exp3() {
        assert_eq!(Solution::single_number(vec![1]), 1);
    }
}