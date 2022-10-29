#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int col, lin, total=0,
    vogais=0, conso=0;

char texto[40][80];

    printf("\n\tDigite o texto: \n\n");

    for(col=0;col<80;col++){
        for(lin=0;lin<40;lin++){
            scanf("%c", &texto[lin][col]);
        }
    }

    for(col=0;col<80;col++){
        for(lin=0;lin<40;lin++){
            if(texto[lin][col] >= 'a' && texto[lin][col] <= 'z'){
                if(texto[lin][col] == 'a' || texto[lin][col] == 'e' ||
                    texto[lin][col] == 'i' || texto[lin][col] == 'o' ||
                    texto[lin][col] == 'u'){
                    vogais = vogais+1;
                }else{
                    conso = conso+1;
                }
            }
        }
    }

    total = vogais+conso;

    printf("\n\n\t\t  Total de letras: %d.", total);
    printf("\n\t\t  Quantidade de vogais: %d.", vogais);
    printf("\n\t\t  Quantidade de consoantes: %d.\n\n", conso);

    printf("\n");
    for(col=0;col<80;col++){
            printf("\t\t");
        for(lin=0;lin<40;lin++){
            printf("%c", texto[lin][col]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\n\t\t  Total de letras: %d.", total);
    printf("\n\t\t  Quantidade de vogais: %d.", vogais);
    printf("\n\t\t  Quantidade de consoantes: %d.\n\n", conso);

}
