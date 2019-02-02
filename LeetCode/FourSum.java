import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FourSum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        ArrayList<List<Integer>>result=new ArrayList<>();
        //先排序
        Arrays.sort(nums);
        for(int i=0,len=nums.length;i<len-3;i++){
            //remove duplicated combination
            if((i>0)&&(nums[i]==nums[i-1]))
                continue;
            for(int j=i+1;j<len-2;j++){
                //remove duplicated combination
                if((nums[j]==nums[j-1])&&(j-1)>i)
                    continue;
                int left=j+1,right=len-1;
                while(left<right){
                    int temp=nums[i]+nums[j]+nums[left]+nums[right];
                    if(temp<target)
                        left++;
                    else if(temp>target)
                        right--;
                    //found
                    else{
                        if((right+1)<len&&left>j&&nums[left]==nums[left-1]&&nums[right]==nums[right+1]){
                            left++;
                            right--;
                            continue;
                        }
                        result.add(Arrays.asList(nums[i],nums[j],nums[left],nums[right]));
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
    public static void main(String[]args){
        int nums[]={0,0,0,0,1,0,-1,0,-2,2,2,3};
        FourSum test=new FourSum();
        System.out.println(test.fourSum(nums,0));
    }
}
