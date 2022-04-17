struct Solution;
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n < 0 {
            return false;
        }
        let alpha = n;
        let mut one_bits = 0;
        for bit in 0..31 {
            if alpha & (1 << bit) != 0 {
                one_bits += 1;
            }
        }
        one_bits == 1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::is_power_of_two(1), true);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::is_power_of_two(16), true);
    }
    #[test]
    fn exp3() {
        assert_eq!(Solution::is_power_of_two(3), false);
    }
}