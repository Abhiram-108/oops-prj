#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ifstream ob1;
    ofstream ob2;
    fstream ob3;
    ob3.open("abhi.txt",ios::app);

    ob1.open("abhi3.txt");
    ob2.open("abhi2.txt");
    string s;
    int y;
    getline(cin,s);
    cin>>y;

    if(!ob1)
    cout<<" ERROR WHILE ACEESSING!!!"<<endl;
    if(!ob2)
    cout<<" ERROR WHILE ACEESSING!!!"<<endl;
    else{
        string s1;
        int x;

        while(!ob1.eof()){
            ob1>>s1>>x;
            if(x>y){
            ob2<<s1;
            ob2<<endl;}
        }

    }
    ob3<<" jayanth.c.t is number one bokudu"<<endl;
    
    ob3.close();

    ob2.close();
    ob1.close();
cout<<"files copied succesfully"<<endl;

    
}