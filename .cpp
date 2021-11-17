#include <iostream>
using namespace std;

int main(){
    char a='a';
    cout<<"Char a: "<<a<<endl;
    char* p=new char(a);
    cout<<"Char* p(points to a): "<<*p<<endl;
    char** pp=new char*(p);
    cout<<"Char** pp (points to p which points to a): "<<**pp<<endl;
    return (0);
}
