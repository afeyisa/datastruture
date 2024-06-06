struct node{
    int val;
    int *next;
    node (int v){
        val=v;
        next=nullptr;
    }
};


class MyLinkedList {
    
public:
   node head;
    MyLinkedList() {  
         head = NULL; 
    }
    
    int get(int index) {
        if (this->head != NULL){
        node * ptr=this->head;
        int count=0;
        while (ptr!=nullptr){
            if(count==index){return ptr->val;}
            prt=ptr->next;
            count++
        }
        return -1;}
        else {return -1;}
        
    }
    
    void addAtHead(int val) {
        node temp= new node(val);
        if (this->head==NULL){
            head=temp;
        }

        else{
            temp.next=&this->head;
            this->head = temp;
        }        
        
    }
    
    void addAtTail(int val) {
         node *temp= new node(val);
         node *ptr=&this->head;
         while (ptr !=nullptr){
            ptr=ptr->next;
         }
         ptr=temp;
        
    }
    
    void addAtIndex(int index, int val) {
    
     if (index ==0){
        addAtHead(val);
        return;}
    else{
     node *temp= new node(val);
     node *ptr = &this->head;
     node *ptr2=ptr->next;
     count=1;
     while(ptr2!=nullptr){
         if(index==count){
            temp->next=ptr2;
            ptr->next=temp;
         }
         ptr2=ptr2->next;
         ptr=ptr->next;
         count++;
     }}

        
    }
    
    void deleteAtIndex(int index) {
        if (head!=NULL&&index==0){head=*head->next;}
        else if(head!=NULL && index>0){
                count=1;
                node *ptr = &this->head;
                node *ptr2=ptr->next
                while(count<=index &&ptr2!=nullptr){
                   if(count==index){
                    if (ptr2->next==nullptr){ptr->=nullptr;}
                    else{
                        ptr->next=ptr2->next;
                    }

                   }
                   ptr2=ptr2->next;
                   ptr=ptr->next;


                }
            }
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