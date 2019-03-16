import java.util.*;
/**
 * 先寻找最接近target的数字,然后把下标存储起来;
 * 例如[1,2,4],target=10;
 * 4,4,2; 4,4,1,1; 4,2,2,2;....
 * 这样的规律,当求解值等于或大于的时候,pop出一个数字;找更小接近target-sum的数
 */
public class CombinationSum {
    //根据right的范围,找到最逼近target的数字
    int closestPosi(int[]candidates,int target,int right){
        int lo=0;
        int hi=right;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(candidates[mid]>target)
                hi=mid-1;
            else if(candidates[mid]<target)
                lo=mid+1;
            else
                return mid;
        }
        return hi;
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<>();
        Arrays.sort(candidates);
        if(candidates.length<1) return res;
        if(target<candidates[0]) return res;
        int curr=closestPosi(candidates,target,candidates.length-1);
        ArrayList<Integer> stack=new ArrayList<>();
        int sum=0;
        while (!(stack.size()==0&&curr==-1)) {
            if(curr!=-1){
                sum+=candidates[curr];
                //存储的是指针下标
                stack.add(curr);
            }
            if(sum==target){
                ArrayList<Integer>temp=new ArrayList<>();
                for(int i=0;i<stack.size();i++)
                    temp.add(candidates[stack.get(i)]);
                res.add(temp);
                int top=stack.remove(stack.size()-1);
                sum-=candidates[top];
                curr=closestPosi(candidates,target-sum,top-1);
            }
            else if(sum>target){
                int top=stack.remove(stack.size()-1);
                sum-=candidates[top];
                curr=closestPosi(candidates,target-sum,top-1);
            }
            else{
                if(curr==-1){
                    int  top=stack.remove(stack.size()-1);
                    sum-=candidates[top];
                    curr=closestPosi(candidates,target-sum,top-1);
                }
                else
                    curr=closestPosi(candidates,target-sum,curr);
            }
        }
        return res;
    }
    public static void main(String[]args){
            CombinationSum test=new CombinationSum();
            int nums[]={1};
            System.out.println(test.combinationSum(nums,2));
            //4,4,2;    4,4,1,1;
    }
}
