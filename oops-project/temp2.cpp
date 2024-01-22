#include<iostream>
using namespace std;
class one{
    public:
    int x;
    public:
    one(int a): x(a){}
    void display(){
        cout<<x<<endl;
    }

};
    void modify(one &ob,int a){
        ob.x=a;
    }
int main(){
    one ob(5);
    modify(ob,6);

}