class Solution {
public:
    Node* addTwoNumbers(Node* head1, Node* head2) {
        int num1 =0; int num2 =0;
        int mul = 1;
        while(head1 != NULL)
        {
            num1 += (head1->data)*mul;
            mul*=10;
            head1 = head1->next;
        }

        mul =1;

        while(head2 != NULL)
        {
            num2 += (head2->data)*mul;
            mul*=10;
            head2 = head2->next;
        }

        int total = num1 + num2;
        int result=0; int remain;

        Node* head = new Node; head->data = total%10; head->next = NULL; total /= 10;
        while(total != 0)
        {
            append(head,total%10);
            total /= 10;
        }
        return head;

    }
};

int main()
{
    Node* head1 = new Node; Node* head2 = new Node;
    head1->next= NULL; head2->next = NULL;
    head1->data = 2; head2->data = 5;
    append(head1,4); append(head1,3);
    append(head2,6);append(head2,4);

    Solution* solution = new Solution();
    solution->addTwoNumbers(head1,head2);

    return 0;
}
