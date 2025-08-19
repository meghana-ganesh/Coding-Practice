//TC:O(n)
class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int v) {
        val = v;
        next = NULL;
    }
    };

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int current_size = 0;
public:
    //1 2 3 4
    MyLinkedList() 
    {
        
    }
    
    int get(int index) 
    {
        if(index < 0 || index >= current_size)
            return -1;
        ListNode *temp = head;
        for(int i=0;i<index;i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val)
    {
        ListNode *newHead = new ListNode(val);
        newHead->next = head;
        head = newHead;
        if(current_size == 0)
            tail = head;
        current_size++;
    }
    
    void addAtTail(int val) 
    {
        if(current_size == 0)
            addAtHead(val);
        else
        {
            tail->next = new ListNode(val);
            tail = tail->next;
            current_size++;
        }

    }
    //1 2 3 5
    void addAtIndex(int index, int val) 
    {
        if(index < 0 || index > current_size)
            return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        if(index == current_size)
        {
            addAtTail(val);
            return;
        }
        ListNode *temp = head;
        for(int i=0;i<index-1;i++)
        {
            temp = temp->next;
        }
        ListNode *newNode = new ListNode(val);
        ListNode *nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;
        current_size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < 0 || index >= current_size)
            return;
        else if(current_size == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else if(index == 0)
        {
            head = head->next;
        }
        else
        {
            //1 2 3 4 5
            ListNode *temp = head;
            for(int i=0;i<index-1;i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            if (index == current_size - 1)
                tail = temp;
        }
        current_size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
