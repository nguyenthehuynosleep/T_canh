#include<iostream>
#include<fstream>
#include<string>

using namespace std;
bool openFileIn(fstream &fs,string filename){
    fs.open(filename.c_str(),ios::in);
    if(fs.fail()){
        return false;
    }
    return true;
}
void showContems(fstream &fs){
    string s;
    while (fs>>s/* condition */)
    {
        cout<<s<<endl;
        /* code */
    }
    
}
int main(){
    string fn="input.txt";
    fstream fs;
    bool b=openFileIn(fs,fn);
    if(b){
        cout<<" Ton tai file "<<endl;
        cout<<" noi dung file la :"<<endl;
        showContems(fs);
    }
    else{
        cout<<" khong ton tai file";
        }
    return 0;

}