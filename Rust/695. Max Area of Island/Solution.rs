impl Solution {
    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {

        let nrows = grid.len();
        let ncols = grid[0].len();
        let mut visited = vec![vec![false; ncols]; nrows];
        let mut oarea = 0;
        for row in 0..nrows{
            for col in 0..ncols{
                let area = Solution::get_area(&grid, &mut visited, row, col, nrows, ncols);
                if area > oarea{
                    oarea = area;
                }
            }
        }
        return oarea;
    }
    pub fn get_area(grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>, row: usize, col: usize,
                    nrows: usize, ncols: usize) -> i32{

        if visited[row][col] == true {
            return 0;
        }

        visited[row][col] = true;
        if grid[row][col] == 0 {
            return 0;
        }

        let mut area = 1;
        if row > 0 {
            if grid[row - 1][col] == 1{
                area += Solution::get_area(grid, visited, row - 1, col, nrows, ncols);
            }
        }
        if row < nrows - 1 {
            if grid[row + 1][col] == 1{
                area += Solution::get_area(grid, visited, row + 1, col, nrows, ncols);
            }
        }
        if col > 0 {
            if grid[row][col - 1] == 1{
                area += Solution::get_area(grid, visited, row, col - 1, nrows, ncols);
            }
        }
        if col < ncols - 1 {
            if grid[row][col + 1] == 1{
                area += Solution::get_area(grid, visited, row, col + 1, nrows, ncols);
            }
        }
        return area;
    }
}
