#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>
#include"tic.h"
void redefine(char **mtr){
    mtr[0][0]='1',mtr[0][1]='2',mtr[0][2]='3',
    mtr[1][0]='4',mtr[1][1]='5',mtr[1][2]='6',
    mtr[2][0]='7',mtr[2][1]='8',mtr[2][2]='9';
    k=0,l=0;
}
void cls(HANDLE hConsole){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SMALL_RECT scrollRect;
    COORD scrollTarget;
    CHAR_INFO fill;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Scroll the rectangle of the entire buffer.
    scrollRect.Left = 0;
    scrollRect.Top = 7;
    scrollRect.Right = csbi.dwSize.X;
    scrollRect.Bottom = csbi.dwSize.Y;

    // Scroll it upwards off the top of the buffer with a magnitude of the entire height.
    scrollTarget.X = 0;
    scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

    // Fill with empty spaces with the buffer's default text attribute.
    fill.Char.UnicodeChar = TEXT(' ');
    fill.Attributes = csbi.wAttributes;

    // Do the scroll
    ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

    // Move the cursor to the top left corner too.
    csbi.dwCursorPosition.X = 0;
    csbi.dwCursorPosition.Y = 0;

    SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void dly(unsigned int mls){
    clock_t whait = mls + clock();
    while(whait>clock());
}
int win(char **mtr){
if((mtr[0][0]=='X' && mtr[0][1]=='X' && mtr[0][2]=='X' )|| (mtr[1][0]=='X' && mtr[1][1]=='X' && mtr[1][2]=='X') || (mtr[2][0]=='X' && mtr[2][1]=='X' && mtr[2][2]=='X') || (mtr[0][0]=='X' && mtr[1][1]=='X' && mtr[2][2]=='X') || (mtr[0][2]=='X' && mtr[1][1]=='X' && mtr[2][0]=='X') || (mtr[0][0]=='X' && mtr[1][0]=='X' && mtr[2][0]=='X') || (mtr[0][1]=='X' && mtr[1][1]=='X' && mtr[2][1]=='X') || (mtr[0][2]=='X' && mtr[1][2]=='X' && mtr[2][2]=='X' ) )
    return 1 ;
else if((mtr[0][0]=='O' && mtr[0][1]=='O' && mtr[0][2]=='O' )|| (mtr[1][0]=='O' && mtr[1][1]=='O' && mtr[1][2]=='O') || (mtr[2][0]=='O' && mtr[2][1]=='O' && mtr[2][2]=='O') || (mtr[0][0]=='O' && mtr[1][1]=='O' && mtr[2][2]=='O') || (mtr[0][2]=='O' && mtr[1][1]=='O' && mtr[2][0]=='O') || (mtr[0][0]=='O' && mtr[1][0]=='O' && mtr[2][0]=='O') || (mtr[0][1]=='O' && mtr[1][1]=='O' && mtr[2][1]=='O') || (mtr[0][2]=='O' && mtr[1][2]=='O' && mtr[2][2]=='O' ) )
    return 2 ;
else 
    return 0 ;  
   
}
void close(char game){
    char answer;
    gotoxy(17,18);
    printf("Enter {1} to go to the menu  and  'any key' to play again : ");
        answer=getch();
    redefine(data);
    if (answer == '1')
    {
        system("color 9");
        menu();
    }
    else
    {   
            switch (game)
            {
            case '1' : play('1');
                break;
            case '2' : computer_play(1,'2');
                break;
            case '3' : computer_play(2,'3');
                break;
            }
    }
}
void title(){
    system("cls");
    system("color 9");
    char str[35]="\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TIC_TAC_TOE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
       gotoxy(20,5);
    for(int i=0;i<34;i++){
        dly(70);
        printf("%c",str[i]);
    }
}
void draw(char **mtr){
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hStdout);
    gotoxy(30,7);
    printf(" %c  |",mtr[0][0]);
    gotoxy(35,7);
    printf(" %c  |",mtr[0][1]);
    gotoxy(40,7);
    printf(" %c  ",mtr[0][2]);

    gotoxy(30,8);
    printf("_____|");
    gotoxy(35,8);
    printf("_____|");
    gotoxy(40,8);
    printf("____");

    gotoxy(30,10);
    printf(" %c  |",mtr[1][0]);
    gotoxy(35,10);
    printf(" %c  |",mtr[1][1]);
    gotoxy(40,10);
    printf(" %c   ",mtr[1][2]);

    gotoxy(30,11);
    printf("_____|");
    gotoxy(35,11);
    printf("_____|");
    gotoxy(40,11);
    printf("____");

    gotoxy(30,13);
    printf(" %c  |",mtr[2][0]);
    gotoxy(35,13);
    printf(" %c  |",mtr[2][1]);
    gotoxy(40,13);
    printf(" %c  ",mtr[2][2]);
}
bool stil_play(char **mtr){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(mtr[i][j]>47 && mtr[i][j]<58)
                return false;
        }
    }
    return true ; 
}
void place_value(char pos,char **mtr,int player){
        switch (pos)
                {
                case '1' : matrix[0][0]=(player==1)?'X':'O';
                break;
                case '2' : matrix[0][1]=(player==1)?'X':'O';
                break; 
                case '3' : matrix[0][2]=(player==1)?'X':'O';
                break; 
                case '4' : matrix[1][0]=(player==1)?'X':'O';
                break; 
                case '5' : matrix[1][1]=(player==1)?'X':'O';
                break; 
                case '6' : matrix[1][2]=(player==1)?'X':'O';
                break;
                case '7' : matrix[2][0]=(player==1)?'X':'O';
                break; 
                case '8' : matrix[2][1]=(player==1)?'X':'O';
                break; 
                case '9' : matrix[2][2]=(player==1)?'X':'O';
                break;  
                }
}
void play(char choice){
    int turn=1 ; 
    int check ; 
    char a;
    draw(data);
    do{
        if(turn==1){
            do{
                gotoxy(20,15);
                printf("player(1)(X) Enter a valeu :");
                a=getch();
            }while(oldvalue(a,data)==false);
                place_value(a,data,1);
            turn=2;
            draw(data);
        }else{
            do{
                gotoxy(20,15);
                printf(" player(2)(O) Enter a valeu :");
                a=getch();
            }while(oldvalue(a,data)==false);
            place_value(a,data,2);
            turn=1;
            draw(data);
        }
    }while(stil_play(data)==false && (check=win(data))==0);
    switch (check)
    {
    case 1: {
        gotoxy(17,15);
        printf("Player(1)(X) WIN :) ") ;
        close(choice);
    }
        break;
    case 2:{
        gotoxy(17,15);
        printf("Player(2)(O) WIN :)  ");
        close(choice);
    }
        break;
    case 0 :  {
        gotoxy(17,15);
        printf("NO WINER :( ");
        close(choice);
    } 
        break;
    }
}
bool oldvalue(char value,char **mtr){
    int i , j ;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(mtr[i][j]==value ){
                return true ;
            }
        }
    }
    return false ;
}
bool oldCmpvalue(int a,int b){
    if(matrix[a][b]=='X' || matrix[a][b]=='O')
    return false ;
    else 
    return true ; 
}
void computer_play(int xo,char choice){
    int turn=xo  ,start=1;
    int check ; 
    char a;
    draw(data);
    do{
            if(turn==1){
                do{
                    if(xo==1){
                        gotoxy(20,15);
                        printf("player(1)(X) Enter a valeu :");
                        a=getch();
                    }else{
                        gotoxy(20,15);
                        printf("player(1)(O) Enter a valeu :");
                        a=getch();
                    }
                }while(oldvalue(a,data)==false);
                xo==1?place_value_comp(a,data,1):place_value_comp(a,data,2);
                turn=2;
                draw(data);
            }else{
                if(start==1){
                    start = 0 ;
                    if(oldCmpvalue(1,1)==true){
                    xo==1?place_value_comp('5',data,2):place_value_comp('5',data,1);
                    }else{
                    xo==1?place_value_comp('1',data,2):place_value_comp('1',data,1);
                    }
                    turn=1;
                    draw(data);
                }
                else{
                    if(xo==1){
                            a=comp_value_play('O');
                            place_value_comp(a,data,2);
                    }else{
                        if(k==1 && l==1){
                            if(matrix[0][0]=='O' )
                                place_value_comp('7',data,1);
                            else 
                                place_value_comp('1',data,1);
                        }else{
                            a=comp_value_play('X');
                            place_value_comp(a,data,1);
                        }
                    }
                    turn=1;
                    draw(data);      
                }
            }
    }while(stil_play(data)==false && (check=win(data))==0);
    switch (check*xo)
    {
    case 1: {
        gotoxy(17,15);
        printf("Player(1)(X) WIN :) ") ;
        close(choice);
    }
        break;
    case 2:{
        gotoxy(17,15);
        printf("Computer WIN :) ");
        close(choice);
    }
        break;
    case 0 :  {
        gotoxy(17,15);
        printf("NO WINER :( ");
        close(choice);
    } 
        break;
    }
}
void place_value_comp(char pos_,char **mtr,int player){
      int i ,j ; 
      for(i=0;i<3;i++){
          for(j=0;j<3;j++){
              if(mtr[i][j]==pos_){
                  if(player==1){
                    tabx[k].row=i;
                    tabx[k].col=j; 
                    k++;
                    mtr[i][j]='X';
                  }
                  else{
                    tabo[l].row=i;
                    tabo[l].col=j; 
                    l++;
                    mtr[i][j]='O';
                  }

                }
            }
        }

}
char comp_value_play(char ch){
    char x , o ,a ; 
        if(ch=='O'){
            if(l>1){
                o=pos(tabo,l);
            }
            x=pos(tabx,k);
            if(o>47 && o <58 )
                return o;
            else if(x>47 && x<58)
                return x ; 
            else {
                a=Cmp_p(tabx,k);
                if(a=='E'){
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(matrix[i][j]>48 && matrix[i][j]<58)
                            return matrix[i][j];
                        }
                    }
                }
                else{
                    return a;
                }
            }
        }
        else{
            if(k>1){
                x=pos(tabx,k);
            }
            o=pos(tabo,l);
            if(x>47 && x <58 )
                return x;
            else if(o>47 && o<58) 
                return o ; 
            else {
                a=Cmp_p(tabo,l);
                if(a=='E'){
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(matrix[i][j]>48 && matrix[i][j]<58)
                            return matrix[i][j];
                        }
                    }
                }
                else{
                    return a;
                }

            }
        }

}
int valu_col_row(int a ,int b ){
    if(a==0 && b==1)
        return 2 ;
    if(a==1 && b==0)
        return 2 ;
    if(a==0 && b==2)
        return 1;
    if(a==2 && b==0)
        return 1 ;
    if(a==2 && b==1)
        return 0 ;
    if(a==1 && b==2)
        return 0 ;
}
char pos(colrow *tab , int la){
    int i , r ,c ;
    colrow ap;
    int last_value = la-1;
    bool old; 
    if(last_value>0){
        for(i=0;i<last_value;i++){
            if(tab[last_value].col == tab[i].col && tab[last_value].row!=tab[i].row){
                    c = tab[i].col;
                    r=valu_col_row(tab[last_value].row, tab[i].row);
                    old = oldCmpvalue(r,c);
                    if(old==true)
                        return matrix[r][c];
            }
            else if(tab[last_value].col != tab[i].col && tab[last_value].row==tab[i].row){
                    r = tab[i].row;
                    c=valu_col_row(tab[last_value].col, tab[i].col);
                    old = oldCmpvalue(r,c);
                    if(old==true){
                        return matrix[r][c];
                    }
            }else if((tab[last_value].col == tab[last_value].row && tab[i].row == tab[i].col) || ( (tab[last_value].col==1 && (tab[last_value].row==1 ) || tab[i].col ==1 && tab[i].row==1) )){
                r = valu_col_row(tab[last_value].row, tab[i].row);
                c = valu_col_row(tab[last_value].col, tab[i].col);
                    old = oldCmpvalue(r,c);
                    if(old==true)
                        return matrix[r][c];
            }
        }
    }
    return 'E' ;
}
colrow position(int ar,int ac , int br , int bc ){
    colrow pos0,pos1,pos2;
    int mcol=ar+bc;
    int mrow=ac+br;
    bool check;
    if(mrow==1 && mcol == 2){
            pos0.row=2,pos0.col=0;
            pos1.row=1,pos1.col=1;
            if((check = oldCmpvalue(2,0))==true && (check = oldCmpvalue(0,1))==true)
                return pos0;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
    }
    if(mrow==2 && mcol==1 ){
            pos0.row=1,pos0.col=1;
            pos1.row=0,pos1.col=2;
            if((check = oldCmpvalue(0,2))==true && (check = oldCmpvalue(0,1))==true)
                return pos1;
            if((check = oldCmpvalue(1,1))==true)
                return pos0;      
    }

    if(mrow==2 && mcol == 2 && ((ar==ac) || (br==bc))){
        pos0.row=0,pos0.col=2;
        pos1.row=2,pos1.col=0;
        if((check = oldCmpvalue(0,2))==true)
            return pos0;
        if((check = oldCmpvalue(2,0))==true)
            return pos1;  
    }

    if(mrow==0 && mcol==2){
            pos0.row=0,pos0.col=0;
            pos1.row=1,pos1.col=1;
            if((check = oldCmpvalue(0,0))==true && (check = oldCmpvalue(1,0))==true)
                return pos0;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
    }

    if(mrow==0 && mcol==3 && ((ar==0 && ac==1) || (ar==2 && ac==0))){
            pos0.row=0,pos0.col=0;
            pos1.row=2,pos1.col=1;
            if((check = oldCmpvalue(0,0))==true)
                return pos0;
            if((check = oldCmpvalue(2,1))==true)
                return pos1;
    }

    if(mrow==2 && mcol==3){
            pos0.row=0,pos0.col=2;
            pos1.row=2,pos1.col=1;
           if((check = oldCmpvalue(0,2))==true && (check = oldCmpvalue(1,2))==true)
                return pos0;
            if((check = oldCmpvalue(2,1))==true)
                return pos1;
    }

    if(mrow==2 && mcol==2 && ((ar==0 && ac==1) || (ar==1 && ac==2)) ){
            pos0.row=0,pos0.col=2;
            pos1.row=1,pos1.col=1;
            if((check = oldCmpvalue(0,2))==true && (check = oldCmpvalue(0,0))==true)
                return pos0;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
    }

    if(mrow==0 && mcol==3 && ((ar==0 && ac==2) || (ar==1 && ac==0))){
            pos0.row=0,pos0.col=0;
            pos1.row=1,pos1.col=1;
            if((check = oldCmpvalue(0,0))==true && (check = oldCmpvalue(0,1))==true)
                return pos0;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
    }
    if(mrow==0 && mcol==4){
            pos0.row=0,pos0.col=0;
            pos1.row=1,pos1.col=1;
            pos2.row=2,pos2.col=1;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
            if((check = oldCmpvalue(0,0))==true)
                return pos0;
            if((check = oldCmpvalue(2,1))==true)
                return pos0;
    }

    if(mrow==1 && mcol==4 && ((ar==0 && ac==2 )||(ar==2 && ac==1))){
            pos0.row=2,pos0.col=2;
            pos1.row=1,pos1.col=1;
            if((check = oldCmpvalue(2,2))==true && (check = oldCmpvalue(1,2))==true)
                return pos0;
            if((check = oldCmpvalue(1,1))==true)
                return pos1;
    }
     if(mrow==2 && mcol==2 && ((ar==1 && ac==0) || (ar==2 && ac==1))){
            pos0.row=1,pos0.col=1;
            pos1.row=2,pos1.col=0;
            if((check = oldCmpvalue(1,1))==true && (check = oldCmpvalue(0,1))==true)
                return pos0;
            if((check = oldCmpvalue(2,0))==true)
                return pos1;
    }

    if(mrow==3 && mcol==2){
            pos0.row=1,pos0.col=2;
            pos1.row=2,pos1.col=0;
            if((check = oldCmpvalue(1,2))==true && (check = oldCmpvalue(0,2))==true)
                return pos0;
            if((check = oldCmpvalue(2,0))==true)
                return pos1;
    }
    if(mrow==1 && mcol==4 && ((ar==1 && ac==2 )||(ar==2 && ac==0))){
            pos0.row=1,pos0.col=0;
            pos1.row=2,pos1.col=2;
            if((check = oldCmpvalue(1,0))==true && (check = oldCmpvalue(0,0))==true)
                return pos0;
            if((check = oldCmpvalue(2,2))==true)
                return pos1;
    }
    if(mrow==2 && mcol==4){
            pos0.row=1,pos0.col=1;
            pos1.row=2,pos1.col=2;
            if((check = oldCmpvalue(1,1))==true && (check = oldCmpvalue(0,1))==true)
                return pos0;
            if((check = oldCmpvalue(2,2))==true)
                return pos1;
    }
    pos0.row=-1,pos0.col=-1;
    return pos0;
}
char Cmp_p(colrow *tab , int la){
    int i , r ,c ;
    colrow ap;
    int last_value = la-1;
    for(i=0;i<last_value;i++){  
            if(tab[last_value].col != tab[i].col && tab[last_value].row != tab[i].row){
                    ap=position(tab[last_value].row,tab[last_value].col,tab[i].row,tab[i].col);
                    if(ap.row != -1 && ap.col != -1){
                        r=ap.row ,c=ap.col;
                            return matrix[r][c];
                    } 
            }
    }
    return 'E';
}
void XorO(){
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hStdout);
    char choice ; 
    gotoxy(20,7);
    printf("*- Play with 'X' {1} ");
    gotoxy(20,8);
    printf("*- Play with 'O' {2} ");
    gotoxy(20,9);
    printf("*- Go beak       {3} ");
    do{
    gotoxy(15,11);
    printf("Enter your choice : ");
    choice = getch();
    }while(choice != '1' && choice!='2' && choice!='3');
    switch (choice)
    {
    case '1': {
        system("color 5");
        computer_play(1,'2');
    }
        break;
    case '2':{ 
        system("color 6");      
        computer_play(2,'3');
    }
        break;
    case '3': menu();
        break;    
    }
}
void menu(){
    char choice ; 
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hStdout);
    gotoxy(20,7);
    printf("*- Play with friends {1} ");
    gotoxy(20,8);
    printf("*- VS Computer       {2} ");
    gotoxy(20,9);
    printf("*- Exit              {3} ");
    do{
    gotoxy(15,11);
    printf("Enter your choice : ");
    choice = getch();
    }while(choice != '1' && choice!='2' && choice!='3');
    switch (choice)
    {
    case '1': {
        system("color 4");
        play(choice);
    }
        break;
    case '2': XorO();
        break;
    case '3': exit(EXIT_SUCCESS);
        break;    
    }
}
int main(){
    title();
    menu();
    return 0 ; 
}