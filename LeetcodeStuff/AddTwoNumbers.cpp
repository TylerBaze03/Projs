/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 semi works, need to rewitre in order to pass test case 1565
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long num1 = 0, num2 = 0;
        struct ListNode* ans = new struct ListNode;
        if (l1->val == 0 && l2->val == 0 && l1->next == NULL && l2->next == NULL){
            ans->val = 0;
            return ans;
        }
        int iter1 = 0, iter2 = 0;
        while(l1 != NULL){
            num1 = (l1->val * pow(10, iter1)) + num1;
            iter1++;
            l1 = l1->next;
        }
        while(l2 != NULL){
            num2 = (l2->val * pow(10, iter2)) +num2;
            iter2++;
            l2 = l2->next;
        }
        cout<<num1<<"\t"<<num2<<"\t";
        long  num3 = num1+num2;
        long  countNum = num3;
        int count = 0;
        vector<int> numVect;
        while(countNum !=0){
            numVect.push_back(countNum %10);
            countNum = countNum/10;
            count++;
        }
        for (int x:numVect)
            cout<<x<<"\t";
        int y = count-1;
        ans->val = numVect[y];
        count--;
        y--;
        while(count !=0){
            struct ListNode* ansNext = new struct ListNode;
            ansNext->val = numVect[y];
            count--;
            y--;
            ansNext->next = ans;
            ans = ansNext;
        }
        return ans;
    }
};
