#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int pos1, pos2;
    char matrix[10][10], mov, trash;

    //creates the matrix and fills it with blank spaces
    for(pos1=0 ; pos1<10 ; pos1++){
        for(pos2=0 ; pos2<10 ; pos2++){
            matrix[pos1][pos2] = ' ';
        }
    }

    //define a random point in map and place the asterix
    int asterixLine = rand()%10;
    int asterixColumn = rand()%10;
    matrix[asterixLine][asterixColumn] = '*';

    //controls
    printf("You can move around the asterix using W(up) A(left) S(down) D(right)\n");
    printf("If you want to stop playing, press any letter\n");

    //print the inicial matrix
    for(pos1=0 ; pos1<10 ; pos1++){
        for(pos2=0 ; pos2<10 ; pos2++){
            printf(" %c |", matrix[pos1][pos2]);
        }
        printf("\n");
    }



    do{
        printf("Where do you wanna move? ");
        mov = getchar();

        //clean the buffer
        do{
            trash = getchar();
        }while(trash != '\n');

        //define movements
        switch(mov){
            case 'w': case 'W':
                if(asterixLine>0){
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine--;
                    matrix[asterixLine][asterixColumn] = '*';
                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine = 9;
                    matrix[asterixLine][asterixColumn] = '*';

                }
            break;
            case 's': case 'S':
                if(asterixLine<9){
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine++;
                    matrix[asterixLine][asterixColumn] = '*';
                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine = 0;
                    matrix[asterixLine][asterixColumn] = '*';
                }
            break;
            case 'd': case 'D':
                if(asterixColumn<9){
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixColumn++;
                    matrix[asterixLine][asterixColumn] = '*';

                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixColumn = 0;
                    matrix[asterixLine][asterixColumn] = '*';
                }
            break;
            case 'a': case 'A':
                if(asterixColumn>0){
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixColumn--;
                    matrix[asterixLine][asterixColumn] = '*';

                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixColumn = 9;
                    matrix[asterixLine][asterixColumn] = '*';
                }
            break;
        }

        printf("\n");
        for(pos1=0 ; pos1<10 ; pos1++){
            for(pos2=0 ; pos2<10 ; pos2++){
                printf(" %c |", matrix[pos1][pos2]);
            }
            printf("\n");
        }

    }while(mov == 'w' || mov == 'a' || mov == 's' || mov == 'd' || mov == 'W' || mov == 'A' || mov == 'S' || mov == 'D');


    printf("Thanks for playing :D");




    return 0;
}
