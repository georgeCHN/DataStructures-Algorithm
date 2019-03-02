/**
 * 二分查找到位置。再在左右延拓就行了吧。最糟的情况就是n的复杂度了
 *
 * * */
public class LeetCode34 {
    public int bSearch(int[]nums,int target){
        int lo=0;
        int hi=nums.length-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<target)
                lo=mid+1;
            else if(nums[mid]>target)
                hi=mid-1;
            else
                return mid;
        }
        return -1;
    }
    public int[] searchRange(int[] nums, int target) {
        int i=bSearch(nums,target);
        int res[]=new int[2];
        if(i==-1) {
            res[0]=res[1]=-1;
            return res;
        }
        int left=i-1,right=i+1;
        while(true){
            while(left>-1&&nums[left]==target)
                left--;
            while(right<nums.length&&nums[right]==target)
                right++;
            break;
        }
        res[0]=left+1;
        res[1]=right-1;
        return res;
    }
    public static void main(String[]args){
        LeetCode34 test=new LeetCode34();
        int nums[]={1};
        int res[]=test.searchRange(nums,1);
        for(int i:res)
            System.out.print(i+"\t");
    }
}
