impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        let mut output:Vec<String> = Vec::new();
        let word: Vec<char> = s.to_lowercase().chars().collect();
        let len = word.len();
        Solution::dfs(word, &mut output, 0, len);
        return output;
    }

    pub fn dfs(word: Vec<char>, output: &mut Vec<String>, index: usize, len: usize){
        if index < len {
            Solution::dfs(word.clone(), output, index+1, len);
            if word[index].is_alphabetic(){
                let mut innerword = word.clone();
                innerword[index] = innerword[index].to_uppercase().next().unwrap();
                Solution::dfs(innerword, output, index+1, len);
            }
        }
        else {
            output.push(word.into_iter().collect())
        }
    }
}