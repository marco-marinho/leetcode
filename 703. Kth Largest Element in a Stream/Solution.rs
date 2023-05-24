use std::collections::BinaryHeap;
use std::cmp::Reverse;

struct KthLargest {
    heap: BinaryHeap<Reverse<i32>>,
    k: usize
}

impl KthLargest {

    fn new(k: i32, nums: Vec<i32>) -> Self {
        let alpha = nums.iter().map(|&x| Reverse(x)).collect();
        Self{heap: alpha, k: k as usize}
    }

    fn add(&mut self, val: i32) -> i32 {
        self.heap.push(Reverse(val));
        while self.heap.len() > self.k {
            self.heap.pop();
        }
        self.heap.peek().unwrap().0
    }
}
