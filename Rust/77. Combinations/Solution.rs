impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>>{
        let mut output: Vec<Vec<i32>> = Vec::new();
        let mut cur_vec: Vec<i32> = (1..k+1).collect();
        let size = k as usize;
        'main:
        loop {
            output.push(cur_vec.clone());
            let mut idx_to_increase = size - 1;
            let a = n - (size as i32 - (idx_to_increase as i32 + 1));
            while cur_vec[idx_to_increase] == n - (size as i32 - (idx_to_increase as i32 + 1)) {
                if idx_to_increase == 0 {
                    break 'main;
                }
                idx_to_increase -= 1;
            }
            let new_val = cur_vec[idx_to_increase] + 1;
            cur_vec[idx_to_increase] = new_val;
            for idx in idx_to_increase+1..size{
                cur_vec[idx] = new_val + (idx as i32 - idx_to_increase as i32);
            }
        }
        return output;
    }
}