
int mat[6][16];
int g=0,bul=1,l=0,r;
int score=1,level=1,dela=100;//101010101;
//////////////////////////////////////////////////////
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//////////////////////////////////////////////////////
void resetb()
{
     for(int j=0;j<16;j++){
             for(int i=0;i<6;i++){mat[i][j]=0;}

             }
}
///////////////////////////////////////////////////
void drawp(int x,int y)
{
if(x>=0&x<6&y>=0&y<16){mat[x][y]=1;}
}
//////////////////////////////////////////////////
void drawc(int x,int y)
{
drawp(1+x,0+y);
drawp(0+x,1+y);drawp(1+x,1+y);drawp(2+x,1+y);
drawp(1+x,2+y);
drawp(0+x,3+y);drawp(1+x,3+y);drawp(2+x,3+y);
}
/////////////////////////////////////////////////
int getr()
{
 int n;
 if(rand()%2==0){n=0;}else{n=3;}
  return n;
}
/////////////////////////////////////////////////
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
int index=1;
    void colorit(int col){//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
        SetConsoleTextAttribute( hstdout, col );
    }
