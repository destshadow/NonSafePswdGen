//
// Created by destshadow on 29/10/2021.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char *PassGen(int dim = 8){
    char *pswd;
    //std::cout << dim << "\n";
    pswd = (char *) malloc ((dim + 1) * sizeof(char));

    for(int i = 0; i <= dim; i++){
        if(i < dim)
            *(pswd + i) = char(32 + std::rand() %  (126 - 32 + 1)); //range 32 - 126 della tabella ascii
        else if(i == dim)
            *(pswd + i) = '\0';
    }

    return pswd;
}

int main(){
    srand(time(NULL));
    int dim = 8;
    char scelta;

    std::cout << "              Password generator NON safe NON secure\n";

    std::cout << "Do you want to set the dimension of the password? (8 default) (Y || y) \n";
    std::cin >> scelta;

    if(scelta == 'Y' || scelta == 'y') {
        std::cout << "Please insert the dimension of the passowrd to generate: \n";
        std::cin >> dim;
        do{
            /*if(dim > 17 || dim < 8){
                std::cout << "Please insert a valid dimension < 17 and > 8\n";
                std::cin >> dim;
            }*/
            if(dim > 255){
                std::cout << "Max range is 255\n";
                std::cin >> dim;
            }
        } while (/*dim > 17 || dim < 8*/ dim > 255);
    }else{
        std::cout << "Dimension default\n";
        //std::cout << dim << "\n";
    }

    char *pswd = PassGen(dim);
    std::cout << "Password created successfully: ";
    std::cout << pswd;
    std::cout << "\n";

    free(pswd);

    return 0;
}