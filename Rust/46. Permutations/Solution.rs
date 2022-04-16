impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>>{
        let mut output: Vec<Vec<i32>> = Vec::new();
        let len = nums.len();
        let mut perm = vec![0; len-1];
        output.push(nums.clone());
        if len == 1 {
            return output;
        }
        'main:
        loop{
            let mut pindex = len-2;
            while perm[pindex] >= len-pindex-1{
                if pindex == 0 {
                    break 'main;
                }
                perm[pindex] = 0;
                pindex -= 1;
            }
            perm[pindex]+=1;
            let mut buff = nums.clone();
            for i in 0..len-1{
                buff.swap(i, i+perm[i]);
            }
            output.push(buff);
        }
        return output;
    }
}