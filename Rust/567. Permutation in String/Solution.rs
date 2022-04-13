use std::collections::HashMap;
impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let win_len = s1.len();
        let target_len = s2.len();
        if win_len > target_len {
            return false;
        }
        let to_check = Solution::str_to_map(s1);
        for idx in 0..target_len - win_len + 1 {
            let slice = &s2[idx..idx+win_len];
            let cur_map = Solution::str_to_map(slice.to_string());
            if to_check == cur_map {
                return true;
            }
        }
        return false;
    }

    pub fn str_to_map(s1: String) -> HashMap<char, i32>{
        return s1
            .to_lowercase()
            .chars()
            .fold(HashMap::new(), |mut map, c| {
                *map.entry(c).or_insert(0) += 1;
                map
            });
    }
}
