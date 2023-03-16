use std::mem;
impl Solution {
    pub fn merge_two_lists(mut list1: Option<Box<ListNode>>, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>>{
        let mut onode = None;
        let mut p_next = &mut onode;

        while list1.is_some() && list2.is_some() {
            let lone = &mut list1;
            let ltwo = &mut list2;
            let lbuffer =
                if lone.as_ref().unwrap().val < ltwo.as_ref().unwrap().val {
                    lone
                }
                else { ltwo };

            mem::swap(p_next, lbuffer);
            mem::swap(lbuffer, &mut p_next.as_mut().unwrap().next);
            p_next = &mut p_next.as_mut().unwrap().next;
        }
        mem::swap(p_next, if list1.is_none() { &mut list2 } else { &mut list1 });
        return onode;
    }
}