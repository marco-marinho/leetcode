impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut one_bits = 0;
        for bit in 0..32 {
            if n & (1 << bit) != 0 {
                one_bits += 1;
            }
        }
        one_bits
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::hammingWeight(0b11111111111111111111111111111101u32), 31);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::hammingWeight(0b00000000000000000000000010000000u32), 1);
    }
    #[test]
    fn exp3() {
        assert_eq!(Solution::hammingWeight(0b00000000000000000000000000001011u32), 3);
    }
}