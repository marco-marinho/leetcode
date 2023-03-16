impl Solution {
    pub fn climb_stairs(steps: i32) -> i32 {
        let mut path = [1, 2];
        if steps == 1 {
            return path[0];
        }
        if steps == 2 {
            return path[1];
        }
        for _i in 2..steps{
            let cur = path[0] + path[1];
            path.swap(0, 1);
            path[1] = cur;
        }
        path[1]
    }
}