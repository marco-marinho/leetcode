class Solution {
     public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int[] bigger;
            int[] smaller;
            int len1 = nums1.length;
            int len2 = nums2.length;
            if (len1 == 0){
                return median(nums2);
            }
            if (len2 == 0){
                return median(nums1);
            }
            if (len1 > len2){
                bigger = nums1;
                smaller = nums2;
            }
            else{
                bigger = nums2;
                smaller = nums1;
            }

            int m = smaller.length;
            int n = bigger.length;

            int start = 0;
            int end = m;

            while (start <= end) {
                int smallerSize = (start + end) / 2;
                int biggerSize = (m + n + 1) / 2 - smallerSize;
                int smallerLeft = smallerSize == 0 ? Integer.MIN_VALUE : smaller[smallerSize - 1];
                int smallerRight = smallerSize == m ? Integer.MAX_VALUE : smaller[smallerSize];
                int biggerLeft = biggerSize == 0 ? Integer.MIN_VALUE : bigger[biggerSize - 1];
                int biggerRight = biggerSize == n ? Integer.MAX_VALUE : bigger[biggerSize];
                if (smallerLeft <= biggerRight && biggerLeft <= smallerRight) {
                    if ((m + n) % 2 == 0) {
                        return (Math.max(smallerLeft, biggerLeft) + Math.min(smallerRight, biggerRight)) / 2.0;
                    } else {
                        return Math.max(smallerLeft, biggerLeft);
                    }
                }
                else if (smallerLeft > biggerRight) {
                    end = smallerSize - 1;
                }
                else {
                    start = smallerSize + 1;
                }
            }
        return -1;
        }

        private double median(int[] nums){
            if (nums.length % 2 == 0){
                return (nums[nums.length/2] + nums[(nums.length/2) - 1]) / (double)2;
            }
            else{
                return nums[nums.length/2];
            }
        }
}
