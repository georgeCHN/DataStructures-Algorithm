/*
* 这题我真的感觉我快蠢死了，竟然开始把所有重复项移动到数组尾部，，，
* 官方题解是，用双指针，遇到非重复的，覆盖旧的数据即可
*重复的跳过即可
* */
public class RemoveDuplicatesFromSortedArray {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)
            return 0;
        int i=0;
        for(int j=1,len=nums.length;j<len;j++){
            if(nums[j]!=nums[i]){
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
    public static void main(String[]args){
        int nums[]={0,0,1,1,1};
        RemoveDuplicatesFromSortedArray test=new RemoveDuplicatesFromSortedArray();
        int cnt=test.removeDuplicates(nums);
        for(int i=0;i<cnt-1;i++){
            System.out.print(nums[i]+",");
        }
        if(cnt>0)
        System.out.print(nums[cnt-1]);

    }
}
