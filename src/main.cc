#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

enum themes{
    dark,
    white,
    catppuccin,
    onedark,
    monokai,
    dracula,
    neon
};

enum display{
    MENU,
    Inicio,
    askH1,
    askP,
    askHREF,
    askH3,
    clean
};
string getTheme(themes t){
    switch (t) {
        case dark: 
                return "";
        case white: 
                return "";
        case catppuccin:
                return "";
        case onedark: 
                return "";
        case monokai: 
                return "";
        case dracula: 
                return "";
        case neon: 
                return "";
    }
}

void showDisplay(display d){
    switch (d) {
        case MENU: 
            cout << " Elige la opción: \n 1- Crear titulo\n 2- Crear subtitulo\n 3- Crear párrafo\n 4- Crear enlace\n 5- Salir\n Opción: ";
            break;
        case Inicio: cout << "Dime el nombre de tu página web: ";
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
    string ubuntu = "<link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"><link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin><link href=\"https://fonts.googleapis.com/css2?family=Ubuntu:ital,wght@0,300;0,400;0,500;0,700;1,300;1,400;1,500;1,700&display=swap\" rel=\"stylesheet\"> ";

    string s = "<html>"+ubuntu+"<link rel=\"stylesheet\" href="+ theme+">" "<title>"+fileName+"</title></html><body>";
    fichero.open(fileName, ios::out);
    fichero << s;

    fichero.close();
    return 0;
}

string themes();

int introduceHTML(string fileName, string content, string type){
    ofstream fichero;
    fichero.open(fileName, ios::app);

    fichero<< "<"+type+">"+content+"</"+type+">";
    fichero.close();
    return 0;
}


int main(){
    string s, file, theme = "../themes/default.css";
    bool exit = false;
    int option;
    string content, auxiliar;

    showDisplay(Inicio);
    getline(cin, file);
    initializeFile(file, theme);

    while (!exit) {
        showDisplay(clean);
        showDisplay(MENU);
        getline(cin, auxiliar);
        option = stoi(auxiliar);

        switch (option) {
            case 1:
                getline(cin, content);
                introduceHTML(file, content, "h1");
                break;
            case 2:
                getline(cin, content);
                introduceHTML(file, content, "h3");
                break;
            case 3:
                getline(cin, content);
                introduceHTML(file, content, "p");
                break;
            case 4:
                // para el href la sintaxis cambia  
                //getline(cin, content);
                //introduce(file, content, "a href=");
                break;
            case 5:
                exit = true;
                break;
        
        }
    }







    return 0;
}

