/*
* LeetCode19题，开始用的两次遍历，第一次统计总节点数目，第二次从开头遍历，删掉即可
* 提交之后看其他人的代码，大致就是用两个节点表示，先让first和Second相差n个节点，
* 然后把first移动到结尾。把second的节点删除即可
* 注意要用一个多余的节点(类似数据结构课程中的头节点)，防止处理头节点比较麻烦。
* */
public class RemoveNthNodeFromEndOfList {
    public static void createList(ListNode head,int[]nums){
        ListNode temp=head;
        for(int i=1;i<nums.length;i++){
            temp.next=new ListNode(nums[i]);
            temp=temp.next;
        }
    }
    public static void printList(ListNode head){
        ListNode temp=head;
        while(temp!=null){
            if(temp.next==null)
                System.out.println(temp.val);
            else
                System.out.print(temp.val+"->");
            temp=temp.next;
        }
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //倒数第0个
        if(n==0)
            return head;
        int nodeCount=0;
        ListNode temp=head;
        while(temp!=null){
            nodeCount++;
            temp=temp.next;
        }
        //删除头节点
        if(nodeCount==n){
            return head.next;
        }
        else{
            int forwardCount=nodeCount+1-n;
            temp=head;
            //移动到被删除节点前一个节点处
            for(int i=1;i<forwardCount-1;i++){
                temp=temp.next;
            }
            temp.next=temp.next.next;
            return head;
        }
    }
    public ListNode removeNthFromEnd_duplicated(ListNode head, int n){
        if(n==0)
            return head;
        //initialize
        ListNode duplicate=new ListNode(0);
        duplicate.next=head;
        ListNode first=duplicate;
        ListNode second=first;

        for(int i=0;i<n;i++){
            first=first.next;
        }
        while (first.next!=null){
            first=first.next;
            second=second.next;
        }
        second.next=second.next.next;
        return duplicate.next;
    }
    public static void main(String[]args){
        ListNode myList=new ListNode(1);
        int nums[]={1,2,3,4,5};
        createList(myList,nums);
        printList(myList);
        RemoveNthNodeFromEndOfList test=new RemoveNthNodeFromEndOfList();
        //printList(test.removeNthFromEnd(myList,5));
        //printList(test.removeNthFromEnd(myList,2));
        printList(test.removeNthFromEnd_duplicated(myList,1));
        printList(test.removeNthFromEnd_duplicated(myList,4));
    }
}
