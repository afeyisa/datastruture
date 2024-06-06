#include <iostream>
using namespace std;

int main(){
    // declaring an array
 
    // array operations
    // crearing array
    // accessing elements
    // adding elements 
    // removing elements
    // destroying arrays

// 1 crearing array
   int ages[10];


// 2 adding elements
 ages[0]=10;
 ages[1]=11;
 ages[2]=12;
 ages[3]=13;
 ages[4]=14;
 ages[5]=15;
 int *ptr;
 ptr=ages;
// or initializing with elements
    string names []={"my ","name ","is","Feyisa","kenenisa"};

    for(int i=0;i<sizeof(names)/sizeof(names[0]);i++)
{    cout<<names[i]<<endl;}
    return 0;
}