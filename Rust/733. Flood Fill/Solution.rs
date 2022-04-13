impl Solution {
    pub fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
            if new_color == image[sr as usize][sc as usize]{
                return image;
            }
            let mut img = image.clone();
            let nrows = image.len();
            let ncols = image[0].len();
            Solution::flood(&mut img, sr as usize, sc as usize, new_color, nrows, ncols);
            return img;
    }
    pub fn flood(image: &mut Vec<Vec<i32>>, sr: usize, sc: usize, new_color: i32,
                 nrows: usize, ncols: usize){

        let original_color = image[sr][sc];
        image[sr][sc] = new_color;
        if sr > 0 {
            if image[sr - 1][sc] == original_color{
                Solution::flood(image, sr - 1, sc, new_color, nrows, ncols);
            }
        }
        if sr < nrows - 1 {
            if image[sr + 1][sc] == original_color{
                Solution::flood(image, sr + 1, sc, new_color, nrows, ncols);
            }
        }
        if sc > 0 {
            if image[sr][sc - 1] == original_color{
                Solution::flood(image, sr, sc - 1, new_color, nrows, ncols);
            }
        }
        if sc < ncols - 1 {
            if image[sr][sc + 1] == original_color{
                Solution::flood(image, sr, sc + 1, new_color, nrows, ncols);
            }
        }
    }
}
