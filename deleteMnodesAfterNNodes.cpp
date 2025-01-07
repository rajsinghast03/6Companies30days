Node *temp = head;
while (temp)
{
  for (int i = 0; i < m - 1 && temp->next; ++i)
    temp = temp->next;
  Node *temp2 = temp;
  for (int i = 0; i < n && temp2->next; ++i)
    temp2 = temp2->next;
  temp->next = temp2->next;
  temp = temp->next;
}

return head;