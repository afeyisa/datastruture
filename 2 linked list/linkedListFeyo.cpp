// oparation on linked lists
// insertion at the top
// insertion at the end
// insertion at the middle
#include <iostream>
using namespace std;


class linkedlist{
   public:
   int data;
   linkedlist*next;
   
   linkedlist(int val){
    data = val;
    next = nullptr;
   }


   // insertion at frot
    void insertTop(int t){

        linkedlist*temp= new linkedlist(this->data);
        temp->next=this->next;
        this->data=t;
        this->next=temp;

    }
// insertion at the end

    void insertAtend(int val){
        linkedlist *temp=new linkedlist(val);
        linkedlist *nodeptr=this;
        if(nodeptr == nullptr){
            nodeptr=temp;
        }


        else{
            while(nodeptr->next!=nullptr){
                nodeptr = nodeptr->next;
            }
            nodeptr->next=temp;  
        }
    }
    /*insertion at the middle in this the insertion condition is 
    under the assumption that index to insert is given
    */
    void insertMidle(int val,int index){
        linkedlist*temp=new linkedlist(val);
        linkedlist*pev=this,*nxt=this->next;
       if(index==0)insertTop(val);
        int count=1;
        // index must be greater than 0 and less than the length of the list
        while(count<index){
            if (nxt->next==nullptr){
                cout<<"index out of bound!"<<endl;
                return;}
            nxt=nxt->next;
            pev=pev->next;
            count++;
        }
        
        temp->next=nxt;
        pev->next=temp;

    }

    /* removing the element from the linked list*/
    void remove(int index){
        linkedlist*pev=this,*nxt=this->next;
        int count=1;
 
        // removing top
        if (index==0){
        this->data=nxt->data;
        this->next=next->next;}

        //removing midle
        else {
            while(count<index){
                if (nxt->next==nullptr){
                cout<<"there is no node to delete index out of bound!"<<endl;
                return;}
                pev=pev->next;
                nxt=nxt->next;
                count++;
            }
            pev->next=nxt->next;
            
        }
        
        
    }

};

int main(){

    linkedlist head=linkedlist(1);


    head.insertTop(2);
    head.insertAtend(3);       
    head.insertMidle(4,2);
    head.remove(3);

    //printing values
    linkedlist *p=&head;
    cout<<"this is the checker"<<endl;
    while(p!=nullptr){
        cout<<p->data<<endl;
        p=p->next;
    }



    return 0;
}
