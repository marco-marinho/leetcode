impl Solution {
    pub fn reverse_bits(x: u32) -> u32{
        let mut output = 0;
        let mut cur_x = x;
        for bit in 0..32 {
            let temp: u32 = if cur_x % 2 == 1 {1} else {0};
            output |= temp << (31 - bit);
            cur_x /= 2;
        }
        output
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::reverse_bits(0b00000010100101000001111010011100u32), 964176192);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::reverse_bits(0b11111111111111111111111111111101u32), 3221225471);
    }
}