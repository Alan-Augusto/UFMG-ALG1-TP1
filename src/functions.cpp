#include <functions.hpp>

using namespace std;

void sayHello(){
    cout << "Hello World!" << endl;
}

void Assert(bool x, string text){
    if(!x){
        cout << text << endl;
        exit(1);
    }
}

char* lineArguments(int argc, char **argv, int x){
    if(argc < 2){
        cout << "Few arguments" << endl;
        cout << "---provide the file address---" << endl;
        exit(1);
    }
    return argv[x];
}