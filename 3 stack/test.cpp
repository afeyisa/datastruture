#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
        string s=tokens[i]; 
      
    
            if (s=="*"){
            if(!stack.empty()&&stack.size()>1){
            int x =  stack.back();
            stack.pop_back();
            int y=stack.back();
            stack.pop_back();
            stack.push_back(x*y);}}
 

            else if (s=="+"){
            if(stack.size()>1){
            int x = stack.back();
            stack.pop_back();
            int y=stack.back();
            stack.pop_back();
           // cout<<x+y<<endl;
            stack.push_back(x+y);}}
          
         
            else if (s=="-"){
            if(stack.size()>1){
            int x = stack.back();
            stack.pop_back();
            int y=stack.back();
            stack.pop_back();
            stack.push_back(y-x);}}
   
    
            else if (s=="/"){
            if(stack.size()>1){
            int x = stack.back();
            stack.pop_back();
            int y=stack.back();
            stack.pop_back();
            int z=y/x;
            //cout<<z<<endl;
            stack.push_back(z);}}
          
       
            else{
               
            stack.push_back(stoi(s));
           }
           
            
         
        
        }
        return stack.back();
    }
};
int main(){
vector<string> v={"4","13","5","/","+"};
Solution s;
int d = s.evalRPN(v);
cout<<d<<endl;

//cout<<(int)13/5<<endl;

    return 0;
}