class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
        int pos =-1; int numofEl = 0;
        if(head == NULL) return NULL;
        Node* pre,*next;
        Node* temp = head;

        while(temp != NULL) {
            numofEl++;
            temp = temp->next;
        }
        pos = numofEl -n;

        if(pos == 0)
        {
            temp = head->next;
            free(head);
            return temp;
        }

        temp = head;
        while(head!= NULL){
            pos--;
            pre = head;
            head = head->next;
            next = head->next;

            if(!pos){
                pre->next = next;
                free(head);
                return temp;
            }
        }
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
    Node* head = solution->removeNthFromEnd(head1,1);

    while(head != NULL){
        std::cout<<head->data<<std::endl;
        head = head->next;
    }

    return 0;
}
