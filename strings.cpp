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

void togglecase(struct String *str){
    int i;
    for(i=0;str->str[i]!='\0';i++){
        if (str->str[i]>='A' && str->str[i]<='Z'){str->str[i]=str->str[i]+32;}
        else if (str->str[i]>='a' && str->str[i]<='z'){str->str[i]=str->str[i]-32;}
    }
}

int count(struct String *str,int num){
    int i,vcount=0,ccount=0,wcount=1;
    if (num==1){
        for(i=0;str->str[i]!='\0';i++){
            if (str->str[i]=='a'||str->str[i]=='e'||str->str[i]=='i'||str->str[i]=='o'||str->str[i]=='u'||
            str->str[i]=='A'||str->str[i]=='E'||str->str[i]=='I'||str->str[i]=='O'||str->str[i]=='U')
            {
                vcount++;
            }  
        }
        return vcount;
    }
    else if (num==3){
        for(i=0;str->str[i]!='\0';i++){
            if(str->str[i]==' '){
                wcount++;
            }
        }
        return wcount++;
    }
    else if (num==2){
        for(i=0;str->str[i]!='\0';i++){
            ccount++;
            if(str->str[i]=='a'||str->str[i]=='e'||str->str[i]=='i'||str->str[i]=='o'||str->str[i]=='u'||
            str->str[i]=='A'||str->str[i]=='E'||str->str[i]=='I'||str->str[i]=='O'||str->str[i]=='U'||
            (str->str[i]>=32&&str->str[i]<=64)||(str->str[i]>=91&& str->str[i]<=96)){
                ccount--;
            }
        }
        return ccount;
        
    }
    else return -1;
}

int valid_passwrd(struct String *str){
    int i;
    for(i=0;str->str[i]!='\0';i++){
        if(!(str->str[i]>=65&&str->str[i]<=90)&&!(str->str[i]>=97&&str->str[i]<=122)&&
        !(str->str[i]>=48&&str->str[i]<=57)){
            return 0;
        }
    }
    return 1;
}

void reverse(struct String *str){
    String Rev={};
    int i,j;
    for (i=0;str->str[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>=0;i--,j++){
        Rev.str[j]=str->str[i];
    }
    Rev.str[j]='\0';
    cout<<"reverse string: ";

    for(i=0;Rev.str[i]!='\0';i++){
        cout<<Rev.str[i];
    }
    //on deleting Rev, getting error of deleting unallocated location.
}
void compare(struct String* str1, struct String* str2){
    int i,j;
    for(i=0,j=0; str1->str[i]!='\0',str2->str[j]!='\0';i++,j++){
        if(str1->str[i]!=str2->str[j]){break;}
    }
    if(str1->str[i]==str2->str[j]){
        cout<<"equal"<<endl;
    }
    else if(str1->str[i]>str2->str[j]){cout<<"string 1 is greater than string 2."<<endl;}
    else{cout<<"string 1 is smaller than string 2."<<endl;}
}

void palindrome(struct String* str){
    int i,j,p=1;
    String Rev{};
    for (i=0;str->str[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>=0;i--,j++){
        Rev.str[j]=str->str[i];
    }
    Rev.str[j]='\0';
    for(i=0,j=0; str->str[i]!='\0',Rev.str[j]!='\0';i++,j++){
        if(str->str[i]!=Rev.str[j]){break;}
    }
    if(str->str[i]==Rev.str[j]){
        cout<<"in palindrome."<<endl;
    }
    else {cout<<"not in palindrome."<<endl;}
}

void duplicate_hashtable(struct String* str){
    //only lowercase letters considered
    int H[26],i;
    for(i=0;i<26;i++){//assuming all the values at each index=0
        H[i]=0;
    }
    for(i=0;str->str[i]!='\0';i++){//incrementing the values based on occurence of each letter
        H[str->str[i]-97]++;
    }
    for(i=0;i<26;i++){//std::cout the letter and occurence.
        if(H[i]>1){cout<<char(97+i)<<" ";cout<<H[i]<<endl;}
    }
}

void duplicate_bitwise(struct String* str){
    //only for lowercase letters
    long int H=0, x=0; //H= to store the occurence of letters in bit.
    int i; // x; for masking and merging.
    for(i=0;str->str[i]!='\0';i++){
        x=1;
        x=x<<str->str[i]-97;
        if((x&H)>0){//checking if H is already ON by Masking.
            cout<<str->str[i]<<" has duplicate"<<endl;
        }
        else{H= x|H; }//if H is OFF, turn ON the index by merging with x
    }

}

void isAnagram(struct String* str1, struct String* str2){
    int i, H[26]={0};
    for(i=0;str1->str[i]!='\0';i++){H[str1->str[i]-97]++;}
    for(i=0;str2->str[i]!='\0';i++){
        H[str2->str[i]-97]--;
        if(H[str2->str[i]-97]<0){cout<<"not anagram. "<<endl;break;}
    }
    if(str2->str[i]=='\0'){cout<<"anagram."<<endl;}
}

void permutation(struct String* str, int k){
    static int A[10]={0};
    static char Result[10];
    int i;
    if(str->str[k]=='\0'){
        Result[k]='\0';
        cout<<Result<<endl;
    }
    else{
        for(i=0;str->str[i]!='\0';i++){
        if(A[i]==0){
            Result[i]=str->str[i];
            A[i]=1;
            permutation(str,k++);
            A[i]=0;
        }
    }
    }
    
}

// overload the << operator for the String structure.
ostream& operator<<(ostream& os, const String &str){
    os<< str.str;
    return os;
}

int main(){
    String A={"ABC"};
    permutation(&A,0);
    return 0;
}