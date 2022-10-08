#include <functions.hpp>

//=====FUNÇÕRD GERAIS=====
    void sayHello(){
        cout << "Hello World!" << endl;
    }

    void Assert(bool x, string text){
        if(!x){
            cout << text << endl;
            exit(1);
        }
    }

    char* checkLineArguments(int argc, char **argv, int x){
        if(argc < 2){
            cout << "--------Few arguments---------" << endl;
            cout << "---provide the file address---" << endl;
            exit(1);
        }
        return argv[x];
    }



//============================
//_____FUNÇÕES DE CLASSES_____

//=====FOLLOWER=====
    //Preenche um seguidor a partir de uma linha
    follower::follower(){
        x1 = -1;
        x2 = -1;
        y1 = -1;
        y2 = -1;
    }
    follower::follower(string line){
        stringstream lineITvalues(line);
            lineITvalues >> x1;
            lineITvalues >> x2;
            lineITvalues >> y1;
            lineITvalues >> y2;
    }

    void follower::print(){
        cout << x1 << " | ";
        cout << x2 << " | ";
        cout << y1 << " | ";
        cout << y2 << endl;;
    }
