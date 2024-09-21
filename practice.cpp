#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
struct list
{
    node* head;
};
void listnode(list& l)
{
    l.head = NULL;
};
node* createnode(int x)
{
    node* newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void print(list& l)
{
    node* temp = l.head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
// them vao dau mot node 
void addahead(list& l, int x)
{
    node* newnode = createnode(x);
    newnode->next = l.head;
    l.head = newnode;
}
int main()
{
    list l;
    listnode(l);
    int n;
    do
    {
        cout << "Nhap phan tu can them vao dau chuoi:\n";
        cin >> n;
        if (n > 0)
        {
            addahead(l, n);
        }
    } while (n > 0);
    cout << "Danh sach sau khi them la:\n";
    print(l);
    return 0;
}
