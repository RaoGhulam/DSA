// Write a function to reverse the singly linked list.

node *rec(node *head)
{
    node *currentNode = head;
    node *preNode = nullptr;
    while (currentNode != nullptr)
    {
        node *nextNode = currentNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }
    return preNode;
}

node *rec(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *newHead = rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

/*Insert some elements in Singly Linked List and write a function to segregate even and
odd numbers such that all even numbers precede odd numbers.*/

node *segregate(node *head)
{
    node *even_head = nullptr;
    node *even_tail = nullptr;
    node *odd_head = nullptr;
    node *odd_tail = nullptr;
    node *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->data % 2 == 0)
        {
            if (even_head == nullptr)
            {
                even_head = ptr;
                even_tail = ptr;
            }
            else
            {
                even_tail->next = ptr;
                even_tail = ptr;
            }
        }
        else
        {
            if (odd_head == nullptr)
            {
                odd_head = ptr;
                odd_tail = ptr;
            }
            else
            {
                odd_tail->next = ptr;
                odd_tail = ptr;
            }
        }
        ptr = ptr->next;
    }
    if (even_tail != nullptr)
    {
        even_tail->next = odd_head;
    }
    if (odd_tail != nullptr)
    {
        odd_tail->next = nullptr;
    }
    return (even_head != nullptr) ? even_head : odd_head;
}

/*Write a program to sort a doubly linked list and remove duplicates from the sorted list.*/

node *sort(node *head)
{
}