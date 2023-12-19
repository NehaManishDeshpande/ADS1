Node* temp = currentHead;
    Node* prev = nullptr;
    while (temp != nullptr && data > temp->data) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;

    return currentHead;