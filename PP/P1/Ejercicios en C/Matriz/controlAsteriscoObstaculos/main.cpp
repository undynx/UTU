#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int pos1, pos2, bombPos1, bombPos2, bombCounter = 0, asterixLine = 0, asterixColumn = 9;
    char matrix[10][10], mov, trash;

    //creates the matrix and fills it with blank spaces
    for(pos1=0 ; pos1<10 ; pos1++){
        for(pos2=0 ; pos2<10 ; pos2++){
            matrix[pos1][pos2] = ' ';
        }
    }

    //place the asterix
    matrix[asterixLine][asterixColumn] = '*';

    //define and place random obstacles
    do{
        //define
        do{
            bombPos1 = rand()%10;
            bombPos2 = rand()%10;
        }while(matrix[bombPos1][bombPos2] != ' ');

        //place
        matrix[bombPos1][bombPos2] = 'X';
        bombCounter++;
    }while(bombCounter<10);

    //controls
    printf("You can move around the asterix using W(up) A(left) S(down) D(right)\n");
    printf("Don't touch the obstacles!\n");
    printf("Get to the bottom left corner to win\n\n");

    //print the inicial matrix
    for(pos1=0 ; pos1<10 ; pos1++){
        for(pos2=0 ; pos2<10 ; pos2++){
            printf(" %c |", matrix[pos1][pos2]);
        }
        printf("\n");
    }



    do{
        printf("\nWhere do you wanna move? ");
        mov = getchar();

        //clean the buffer
        do{
            trash = getchar();
        }while(trash != '\n');

        //define movements
        switch(mov){
            case 'w': case 'W':
                if(asterixLine>0){
                    if(matrix[asterixLine-1][asterixColumn] != 'X'){
                        matrix[asterixLine][asterixColumn] = ' ';
                        asterixLine--;
                        matrix[asterixLine][asterixColumn] = '*';
                    }else{
                        printf("There's an obstacle, you can't move there");
                    }
                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine = 9;
                    matrix[asterixLine][asterixColumn] = '*';

                }
            break;
            case 's': case 'S':
                if(asterixLine<9){
                    if(matrix[asterixLine+1][asterixColumn] != 'X'){
                        matrix[asterixLine][asterixColumn] = ' ';
                        asterixLine++;
                        matrix[asterixLine][asterixColumn] = '*';
                    }else{
                        printf("There's an obstacle, you can't move there");
                    }
                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixLine = 0;
                    matrix[asterixLine][asterixColumn] = '*';
                }
            break;
            case 'd': case 'D':
                if(asterixColumn<9){
                    if(matrix[asterixLine][asterixColumn+1] != 'X'){
                        matrix[asterixLine][asterixColumn] = ' ';
                        asterixColumn++;
                        matrix[asterixLine][asterixColumn] = '*';
                    }else{
                        printf("There's an obstacle, you can't move there");
                    }
                } else {
                    matrix[asterixLine][asterixColumn] = ' ';
                    asterixColumn = 0;
                    matrix[asterixLine][asterixColumn] = '*';
                }
            break;
            case 'a': case 'A':
                if(asterixColumn>0){
                    if(matrix[asterixLine][asterixColumn-1] != 'X'){
                        matrix[asterixLine][asterixColumn] = ' ';
                        asterixColumn--;
                        matrix[asterixLine][asterixColumn] = '*';
                    }else{
                        printf("There's an obstacle, you can't move there");
                    }
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

    }while(matrix[9][0] != '*');

    printf("YOU WON!");


    return 0;
}
