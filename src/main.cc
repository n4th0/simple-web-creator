#include <iostream>
#include <fstream>
#include <unistd.h>

#define EXT ".html"

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
    askSelected,
    askTheme,
    clean
};

string getTheme(int t){
    switch (t) {
        case 1: 
            return "../theme/dark.css";
        case 2: 
            return "../theme/white.css";
        case 3:
            return "../theme/catppuccin.css";
        case 4: 
            return "../theme/onedark.css";
        case 7: 
            return "../theme/monokai.css";
        case 5: 
            return "../theme/dracula.css";
        case 6: 
            return "../theme/neon.css";
        default:
            return "../themes/default.css";
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
        case askSelected: cout << "Quieres que esté seleccionado?[y/n]: ";
                          break;
        case askTheme: cout << " Elige la opción: \n 1- Dark\n 2- White\n 3- Catpuccin\n 4- Onedark\n 5- Dracula\n 6- Neon\n 7- Monokai\n Opción: ";
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
    fichero.open(fileName+EXT, ios::out);
    fichero << s;

    fichero.close();
    return 0;
}


int introduceHTML(string fileName, string content, string type, bool selected){
    ofstream fichero;
    fichero.open(fileName+EXT, ios::app);

    if(selected){
        fichero<< "<"+type+" class=\"selected\" "+">"+content+"</"+type+">";

    }else {
        fichero<< "<"+type+">"+content+"</"+type+">";
    }
    fichero.close();
    return 0;
}


int main(){
    string aux, file, theme;
    bool exit = false;
    int option;
    string content, auxiliar;

    showDisplay(Inicio);
    getline(cin, file);

    showDisplay(askTheme);
    getline(cin, theme);

    if (theme.empty()) {
        initializeFile(file, getTheme(0));
    }else {
        initializeFile(file, getTheme(stoi(theme)));
    }



    while (!exit) {
        showDisplay(clean);
        showDisplay(MENU);
        getline(cin, auxiliar);
        option = stoi(auxiliar);

        switch (option) {
            case 1:
                getline(cin, content);
                showDisplay(askSelected);
                getline(cin, aux);
                if (aux == "y") {
                    introduceHTML(file, content, "h1", true);
                }else {
                    introduceHTML(file, content, "h1", false);
                }
                break;
            case 2:
                getline(cin, content);
                showDisplay(askSelected);
                getline(cin, aux);

                if (aux == "y") {
                    introduceHTML(file, content, "h3", true);
                }else {
                    introduceHTML(file, content, "h3", false);
                }
                break;
            case 3:
                getline(cin, content);
                showDisplay(askSelected);
                getline(cin, aux);

                if (aux == "y") {
                    introduceHTML(file, content, "p", true);
                }else {
                    introduceHTML(file, content, "p", false);
                }
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
