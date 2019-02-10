public class RemoveElement{
    public int removeElement(int[] nums, int val) {
        if(nums.length==0)
            return 0;
        int i=0;
        for(int j=0,len=nums.length;j<len;j++){
            if(nums[j]!=val)
                nums[i++]=nums[j];
        }
        return i;
    }
    public static void main(String[]args){
        int nums[]={2,2,2,2};
        RemoveElement test=new RemoveElement();
        int cnt=test.removeElement(nums,2);
        for(int i=0;i<cnt;i++){
            System.out.print(nums[i]+",");
        }
    }
}
