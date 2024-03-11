
#include <bits/types/wint_t.h>
#include <iostream>
#include <fstream>
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
        case askH1: cout << "Dime el titulo de tu página web: ";
            break;
        case askP: cout << "Dime el contenido de tu apartado: ";
            break;
        case askHREF: cout << "Introduce el enlace: ";
            break;
        case askH3: cout << "Introduce el titulo del apartado: ";
            break;
        case clean: cout << "\e[1;1H\e[2J"<< endl;
            break;
    }

}
/// create the html structure
int initializeFile(string fileName, string theme){
    ofstream fichero;
    string ubuntu = "link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"><link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin><link href=\"https://fonts.googleapis.com/css2?family=Ubuntu:ital,wght@0,300;0,400;0,500;0,700;1,300;1,400;1,500;1,700&display=swap\" rel=\"stylesheet\"> ";
    string s = "<html>"+ubuntu+"<link rel=\"stylesheet\" href="+ theme+">" "<title>"+fileName+"</title></html><body>";
    fichero.open(fileName);
    fichero << s;

    fichero.close();
    return 0;
}


int introduce(string fileName, string h1Content, string type){
    ofstream fichero;
    fichero.open(fileName, ios::app);

    fichero<< "<"+type+">"+h1Content+"</"+type+">";
    fichero.close();
    return 0;
}


int main(){
    string s, file = "prueba.html", theme = "../themes/default.css";

    initializeFile(file, theme);


    showDisplay(askH1);
    getline(cin, s);
    introduce(file, s, "h1");

    showDisplay(askP);
    getline(cin, s);
    introduce(file, s, "p");

    showDisplay(askH1);
    getline(cin, s);
    introduce(file, s, "h1");

    showDisplay(askP);
    getline(cin, s);
    introduce(file, s, "p");




    return 0;
}

