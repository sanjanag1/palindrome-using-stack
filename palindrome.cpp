
//Program that uses stack to recognize palindromes

#include <iostream>
#include <string>

using namespace std;

const int MAX = 50;

class Stack{
private:
    char array[MAX];
    int top, length, count;

public:
    Stack(){
        top = -1;
        length = 0;
        count = 0;
    }

    void push(char tmp){
    
    if(top == MAX-1){                                       //checking if the stack is full
        cout << "Stack Overflow" << endl;   
        return;
    }

    top++;                                                  
    array[top] = tmp;                                       //if the stack is not full, then pushing elements onto the stack
}

char pop(){
    if(top == -1){                                          //check if the stack is empty
        cout << "Stack Underflow" << endl;
        char ch = '\n';
        return ch;
    }
    char tmp = array[top];                                  //if the stack is not empty popping elements
    top--;
    return tmp;
}
   void checkPalindrome();

};

void Stack::checkPalindrome(){
    string exp;
    cout<<" Enter a String: ";
    getline(cin,exp);                                       //getting the entire string expression and storing it
    length=exp.length();                                    //storing the length of the string
    for(int i=0; i< length ;i++)
       push(exp[i]);                                        //pushing the characters of the string into a stack
    
    for(int i=0; i< length; i++){
        if(exp[i] == pop())                                 //popping the characters of the string in LIFO order so as to reverse order
            count++;                                        //if each character of the original string matches the character popped from the stack increment the flag
    }

    if(count == length)                     
        cout << "The string is a palindrome. " << endl;
    else
        cout << "String is not a palindrome." << endl;
    
}

int main()
{
    Stack st;                                               //creating a stack object
    string exp;
    st.checkPalindrome();                                   //calling the function to check for palindrome      
    return 0;
} 

