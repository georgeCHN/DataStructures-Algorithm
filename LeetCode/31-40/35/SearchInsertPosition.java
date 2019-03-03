/*
就是二分搜索寻找最佳位置
*/

public class SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int lo=0,hi=nums.length-1;
        int mid=(lo+hi)/2;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]<target)
                lo=mid+1;
            else if(nums[mid]>target)
                hi=mid-1;
            else
                return mid;
        }
        //System.out.println("找不到该值，返回lo="+lo+"\thi="+hi);
        //返回一个较大的值作为该位置
        return lo;
    }
    public static void main(String[]args){
        SearchInsertPosition test=new SearchInsertPosition();
        int nums[]={1,3,5,6};
        System.out.println(test.searchInsert(nums,4));
    }
}
