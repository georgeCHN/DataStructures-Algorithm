public class SearchInRotatedSortedArray {
    public int bSearch(int[]nums,int lo,int hi,int target){
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
    public int search(int[] nums, int target) {
        if(nums.length<1)
            return -1;
        int N=nums.length;
        int lo=0,hi=N-1;
        int position=-1;
        //0表示左边有序，1表示右边有序
        int isSorted=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[lo]<=nums[mid]){
                isSorted=0;
                position=bSearch(nums,lo,mid,target);
                if(position!=-1)
                    return position;
            }
            else if(nums[mid]<nums[hi]){
                isSorted=1;
                position=bSearch(nums,mid,hi,target);
                if(position!=-1)
                    return position;
            }
            if(isSorted==0){
                lo=mid+1;
            }
            else if(isSorted==1){
                hi=mid-1;
            }
        }
        return -1;
    }
    public static void main(String[]args){
        int nums[]={3};
        SearchInRotatedSortedArray test=new SearchInRotatedSortedArray();
        System.out.println(test.search(nums,3));
    }
}
