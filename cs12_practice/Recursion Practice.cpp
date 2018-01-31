int IntList::sum() const
{
    return sum(head);
}

int IntList::sum(IntNode *curr) const
{
    if(curr == 0)
    return 0;
    return curr->data + sum(curr->next);
}