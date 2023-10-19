#include <iostream>
#include <string>
using namespace std;

struct String{
    char str[100];
};

int length(struct String *str){
    int i;
    for (i=0;str->str[i]!='\0';i++){}
    return i;
}

void uppercase(struct String *str){
    int i;
    for(i=0;str->str[i]!='\0';i++){
        str->str[i]=str->str[i]-32;
    }
}

//The ostream& operator<< function is an operator overloading 
//function that allows you to define how an object of your custom type
//(in this case, String) should be formatted and displayed
//when you use the insertion operator (<<) with std::cout or other output streams.

//overload the << operator for the String structure.
ostream& operator<<(ostream& os, const String &str){ 
  //ostream&: returns a reference to the output stream (std::ostream).
  //operator<<: tells C++ that you're defining how the << operator should work for your custom String type.
  //ostream& os: the first parameter, representing the output stream (e.g., std::cout). It's passed by reference so that you can modify and return the same stream.
  //const String &str: the second parameter, representing the String object you want to print. It's passed as a constant reference to avoid modifying it. 
    os<< str.str;
    return os;
}

int main(){
    String s={"monu"};
    uppercase(&s);
    std::cout <<s.str;
    return 0;
}
