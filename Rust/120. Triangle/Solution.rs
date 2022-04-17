use std::cmp;
use serde_json;

struct Solution;

impl Solution {
    pub fn minimum_total(triangle: &Vec<Vec<i32>>) -> i32 {
        let mut cur_cost: Vec<i32> = vec![i32::MAX; triangle.len()];
        cur_cost[0] = 0;
        for row in triangle{
            for (idx, cost) in row.iter().enumerate().rev() {
                let buff = if idx == 0 { &cur_cost[idx] } else { cmp::min(&cur_cost[idx], &cur_cost[idx - 1]) };
                cur_cost[idx] = cost + *buff;
            }
        }
        match cur_cost.iter().min() {
            None => {0}
            Some(x) => {*x}
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn exp1() {
        assert_eq!(Solution::minimum_total(&serde_json::from_str("[[2],[3,4],[6,5,7],[4,1,8,3]]").unwrap()), 11);
    }
    #[test]
    fn exp2() {
        assert_eq!(Solution::minimum_total(&serde_json::from_str("[[-10]]").unwrap()), -10);
    }
}