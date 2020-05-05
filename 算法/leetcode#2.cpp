/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *Nl3 = new ListNode(0);  //头结点
        ListNode *l3=Nl3;
        int r=0,s=0;                      //r用于存储进位，s存储相加
        while(l1!=NULL||l2!=NULL)
        {
            int a = (l1!=NULL)?l1->val:0; //判断a、b是否为空
            int b = (l2!=NULL)?l2->val:0;
            s=a+b+r;
            r=s/10;                       //r为0或1
            l3->next = new ListNode(s%10);
            l3=l3->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(r==1) l3->next= new ListNode(1);//不要忽略最后一位的进位
        
        return Nl3->next;                  //返回除头节点以外数


        
    }
};
