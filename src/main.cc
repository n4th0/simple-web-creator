
#include <iostream>
#include <unistd.h>
using namespace std;

enum display{
    MENU,
    askH1,
    askP,
    askHREF,
    askH3,
    clean
};
void showDisplay(display d){
    switch (d) {
        case MENU: cout << "Bienvenido "<<endl;
            break;
        case askH1: cout << "Dime el titulo de tu página web: "<<endl;
            break;
        case askP: cout << "Dime el contenido de tu apartado: "<<endl;
            break;
        case askHREF: cout << "Introduce el enlace: "<< endl;
            break;
        case askH3: cout << "Introduce el titulo del apartado: "<<endl;
            break;
        case clean: cout << "\e[1;1H\e[2J"<< endl;
            break;
    
    }

}


int main(){

    showDisplay(MENU);
    sleep(4);
    showDisplay(clean);
    showDisplay(askP);
    showDisplay(askH3);


    return 0;
}

