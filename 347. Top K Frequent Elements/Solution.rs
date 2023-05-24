use std::collections::HashMap;
use std::collections::BinaryHeap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let counts = nums.iter().fold(HashMap::new(), |mut dict, curr| {
            *dict.entry(curr).or_insert(0) += 1;
            dict
        });
        let alpha: Vec<(i32, i32)> = counts.into_iter().map(|(a, b)| (b, *a)).collect();
        let heap = BinaryHeap::from(alpha);
        heap.into_sorted_vec().into_iter().rev().take(k as usize).map(|(_a, b)| b).collect()
    }
}
