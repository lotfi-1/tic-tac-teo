#ifndef TICTACTEO
#define TICTACTEO
#include<windows.h>
typedef struct colrow colrow ; 
struct colrow{
    int row ; 
    int col ;
};
int k=0,l=0 ;
colrow tabx[5];
colrow tabo[5];

void play(char choice);
void close(char game);
void dly();
void cls(HANDLE hConsole);
void gotoxy (int x, int y);
bool stil_play(char **mtr);
void place_value(char pos,char **mtr,int player);
void title();
int win(char **mtr);
void draw(char **mtr);
void redefine(char **mtr);
bool oldvalue(char value,char **mtr);
char comp_value_play(char ch);
void place_value_comp(char pos,char **mtr,int player);
char pos(colrow *tab , int last_value);
int valu_col_row(int a ,int b );
void computer_play(int xo,char choice);
bool oldCmpvalue(int a,int b);
colrow position(int ar,int ac , int br , int bc );
char Cmp_p(colrow *tab , int la);
void menu();
void XorO();


char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char* data[]= {matrix[0], matrix[1], matrix[2]};

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;

#endif