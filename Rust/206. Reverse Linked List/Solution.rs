impl Solution {
    pub fn reverse_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>>{
        let mut prev = None;
        let mut current = head.take();
        while current.is_some() {
            let next = current.as_mut().unwrap().next.take();
            current.as_mut().unwrap().next = prev.take();
            prev = current.take();
            current = next;
        }
        return prev.take();
    }
}