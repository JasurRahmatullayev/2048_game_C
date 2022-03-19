#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
int main()
{
    int doska[4][4] = {
    {0, 0, 0, 0}, 
    {0, 0, 0, 0}, 
    {0, 0, 0, 0}, 
    {0, 0, 0, 0}
    };
    char yonalish;
    int x=5, y=5;
    int son=0;
    int tr=1;
    int tort;
    
    boshla:
    x=5;
    y=5;
    srand(time(NULL));

    son++;
    for (int q=0; q<4; q++){
        for(int w=0; w<4; w++){
            if(doska[q][w]==2048){
                printf("yutdingiz!!!");
            }       
        }
    }
    int b=0;
    for (int q=0; q<4; q++){
        for(int w=0; w<4; w++){
            if(doska[q][w]==0){
                
                printf("taxmin-%d\n", son);
                tort=rand()%4;
                while (tr){
                    
                    if(x<4 && y<4 && doska[y][x]==0){
                        
                        if(tort==0 && son>3){
                            doska[y][x]=4;
                        } else{
                            doska[y][x]=2;
                        }
                        break;
                    } else {
                        x = rand() % 4;
                        y = rand() % 4;
                    }    
                }
                printf("\nchiqarish\n");
                for(int a=0; a<4; a++){
                    for(int b=0; b<4; b++){
                        if(doska[a][b]==0){
                            printf("    |");
                        } else {
                            printf("%3d |", doska[a][b]);
                        }
                    }
                printf("\n--------------------\n");
                }
                
                printf("yonalishni kiriting(w, a, s, d): ");
                scanf("%c", &yonalish);
                
                if(yonalish=='w'){
                    for( int x=0; x<4; x++){
                        for(int y=0; y<4; y++){
                            if(y==0){
                                continue;
                            }
                            if(doska[y][x]>0){
                                for(int j=0; j<y; j++){
                                    if(doska[y][x]==doska[j][x] && y!=j){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[j][x]=doska[y][x]+doska[j][x];
                                        doska[y][x]=0;
                                        printf("\nqoshishda xatolik\n");
                                        tr=1;
                                        break;
                                    } else if(doska[j][x]==0){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[j][x]=doska[y][x];
                                        doska[y][x]=0;
                                        printf("\norniga qda xatolik\n");
                                        tr=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    
                } else if(yonalish=='d'){
                    for( int y=0; y<4; y++){
                        for(int x=3; x>=0; x--){
                            if(x==3){
                                continue;
                            }
                            if(doska[y][x]>0){
                                for(int j=3; j>x; j--){
                                    if(doska[y][x]==doska[y][j] && x!=j){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[y][j]=doska[y][x]+doska[y][j];
                                        doska[y][x]=0;
                                        printf("\nqoshishda xatolik\n");
                                        tr=1;
                                        break;
                                    } else if(doska[y][j]==0){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[y][j]=doska[y][x];
                                        doska[y][x]=0;
                                        printf("\norniga qda xatolik\n");
                                        tr=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                
                } else if(yonalish=='s'){
                    for( int x=0; x<4; x++){
                        for(int y=3; y>=0; y--){
                            if(y==3){
                                continue;
                            }
                            if(doska[y][x]>0){
                                for(int j=3; j>y; j--){
                                    if(doska[y][x]==doska[j][x] && y!=j){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[j][x]=doska[y][x]+doska[j][x];
                                        doska[y][x]=0;
                                        printf("\nqoshishda xatolik\n");
                                        tr=1;
                                        break;
                                    } else if(doska[j][x]==0){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[j][x]=doska[y][x];
                                        doska[y][x]=0;
                                        printf("\norniga qda xatolik\n");
                                        tr=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else if(yonalish=='a'){
                    for( int y=0; y<4; y++){
                        for(int x=0; x<4; x++){
                            if(x==0){
                                continue;
                            }
                            if(doska[y][x]>0){
                                for(int j=0; j<x; j++){
                                    if(doska[y][x]==doska[y][j] && x!=j){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[y][j]=doska[y][x]+doska[y][j];
                                        doska[y][x]=0;
                                        printf("\nqoshishda xatolik\n");
                                        tr=1;
                                        break;
                                    } else if(doska[y][j]==0){
                                        printf("j-%d, y-%d, x-%d", j, y, x);
                                        doska[y][j]=doska[y][x];
                                        doska[y][x]=0;
                                        printf("\norniga qda xatolik\n");
                                        tr=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                
                
                system("clear");
                goto boshla;
                
            } else if(q==3 && w==3){
                printf("yutqazdingiz");
            }
        }
    }
    
    return 0;
}





