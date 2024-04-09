#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void creation1(node* &head1, int n1)
{
    // creating linked list 1
    for (int i=2; i<=n1; i++)
    {
        int d;
        cout<<"Enter data of node"<<i<<":"<<endl;
        cin>>d;
        node* temp=new node(d);
        head1->next=temp;
        head1=head1->next;
    }
}
void creation2(node* &head2, int n2)
{
    // creating linked list 1
    for (int i=2; i<=n2; i++)
    {
        int d;
        cout<<"Enter data of node"<<i<<":"<<endl;
        cin>>d;
        node* temp=new node(d);
        head2->next=temp;
        head2=head2->next;
    }
}
node* reverse(node* head)
{
    if ((head==NULL)||(head->next==NULL))
    {
        return head;
    }
    node* curr_ptr=head;
    node* prev_ptr=NULL;
    node* next_ptr=NULL;
    while(curr_ptr!=NULL)
    {
        next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
    }
    return prev_ptr;
}
void insert_at_tail(node* &head, node* &tail, int val)
{
    node* temp=new node(val);
    if (head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
node* add(node* first, node* second)
{
    // checking if first linked list is NULL
    if (first==NULL)
    {
        return second;
    }

    // checking if second linked list is NULL
    if (second==NULL)
    {
        return first;
    }

    // checking if both are NULL
    if ((first==NULL)&&(second==NULL))
    {
        return second;
    }

    // creating variables for sum
    int sum, digit, carry=0;

    // creating head and tail of resultant linked list
    node* anshead=NULL;
    node* anstail=NULL;

    // loop till both are not NULL
    while ((first!=NULL)&&(second!=NULL))
    {
        sum=carry+first->data+second->data;
        digit=sum%10;
        insert_at_tail(anshead, anstail, digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }

    // loop till first is not NULL where second is NULL
    while (first!=NULL)
    {
        sum=carry+first->data;
        digit=sum%10;
        insert_at_tail(anshead, anstail, digit);
        carry=sum/10;
        first=first->next;
    }

    // loop till second is not NULL where first is NULL
    while (second!=NULL)
    {
        sum=carry+second->data;
        digit=sum%10;
        insert_at_tail(anshead, anstail, digit);
        carry=sum/10;
        second=second->next;
    }

    // loop when both first and second are NULL and we have to move carry
    while (carry!=0)
    {
        sum=carry;
        digit=sum%10;
        insert_at_tail(anshead, anstail, digit);
        carry=sum/10;
    }

    return anshead;
}
node* add_two_numbers_using_linked_list(node* &first, node* &second)
{
    // displaying linked list 1
    first=reverse(first);
    second=reverse(second);
    node* ans=add(first, second);
    ans=reverse(ans);
    return ans;
}
void display1(node* &head1)
{
    // displaying linked list 1
    node* temp=head1;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void display2(node* &head2)
{
    // displaying resultant linked list;
    node* temp=head2;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void display(node* &head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int n1;
    cout<<"Enter number of nodes of linked list 1:"<<endl;
    cin>>n1;

    int n2;
    cout<<"Enter number of nodes of linked list 2:"<<endl;
    cin>>n2;

    int d_node1;
    cout<<"Enter data of node1 of linked list 1:"<<endl;
    cin>>d_node1;

    int d_node2;
    cout<<"Enter data of node1 of linked list 2:"<<endl;
    cin>>d_node2;

    node* node1=new node(d_node1);
    node* head1=node1;
    node* h1=head1;
    creation1(head1, n1);
    display1(h1);

    node* node2=new node(d_node2);
    node* head2=node2;
    node* h2=head1;
    creation2(head2, n2);
    display2(h2);

    node* answer=add_two_numbers_using_linked_list(h1, h2);
    display(answer);
}