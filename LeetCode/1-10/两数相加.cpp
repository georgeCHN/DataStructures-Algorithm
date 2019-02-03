/**
 * Definition for singly-linked list.*/
 #include <iostream>
 using namespace std;
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        res=new ListNode(0);
        bool flag=false;
        res->val=(l1->val+l2->val)%10;
        if(l1->val+l2->val>10)
        flag=true;
        while(l1->next&&l2->next){
            l1=l1->next;
            l2=l2->next;
            int temp=l1->val+l2->val;
            temp+=flag;
            res=res->next=new ListNode(temp%10);
            if(temp>10)
                flag=true;
            else
                flag=false;
            
        }
        //考虑l1和l2不等长
        if(l1->next&&!(l2->next)){
            while(l1->next){
                res=res->next=new ListNode(0);
                l1=l1->next;
                res->val=l1->val;
            }
        }
        else if(l2->next&&!(l1->next)){
               while(l2->next){
                res=res->next=new ListNode(0);
                l2=l2->next;
                res->val=l2->val;
            }
        }
        else{
            ListNode* temp=res;
            int* num;
            for(;temp;temp=temp->next){
                num=new int;
                *num=temp->val;
            }
            int length=0;
            for(length=0,temp=res;temp;length++){
                temp=temp->next;
                num=new int;
                *num=temp->val;
            }
            ListNode* ans=new ListNode(0);
            for(int i=0;i<length;i++){
                ans->val=num[length-i];
                ans->next=new ListNode(0);
            }
             return ans;
        }
       
        
};
int main(){
	Solution s1;
	ListNode l1(3);
	
	return 0;
}
