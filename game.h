int showMenu();
/////////////////////////////////////
DWORD WINAPI ThreadFn(LPVOID vpParam)
{
	while (1) {
		for(int i=8;i<=190;i++)
            {
               if(GetAsyncKeyState(i)==-32767){
               if(i==37){l=0;}else if(i==39){l=3;}//else if(i==38){menuIndex--;}else if(i==40){menuIndex++;}
               }
            }
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
DWORD qThreadID;
HANDLE hThread;
void startInput(){
hThread = CreateThread(0, 0, ThreadFn, 0, 0, &qThreadID);
}
/////////////////////////////////////////////////////////////////////////////
void startGame(){
system("cls");
gotoxy(7,2);cout<<"  CONTROLS";
gotoxy(7,3);cout<<"  ========";
gotoxy(7,4);cout<<"<<== [LEFT ARROW]";
gotoxy(7,5);cout<<"==>> [RIGHT ARROW]";

for(int i=3;i>=0;i--){
gotoxy(7,7);cout<<i;
gotoxy(14,14);
Sleep(1000);
}
system("cls");

while(bul){
           gotoxy(14,4);cout<<"SCORE:"<<score;
           gotoxy(14,5);cout<<"LEVEL:"<<level;
         resetb();
         drawc(r,g);
         drawc(l,12);
	for(int j=0;j<16;j++){
          gotoxy(4,j+1);cout<<"8";
          gotoxy(5,j+1);
          for(int i=0;i<6;i++){if(mat[i][j]==1){cout <<"O";}else{cout<<" ";}}gotoxy(11,j+1);cout<<"8";
		  if(g>=12&l==r){bul=0;}
	}
	g++;
	if(g==15){g=-4;r=getr();score++;}
	if(score%5==0&(g==15|g==-4)){level++;dela=dela-15;}
	if(dela<0){gotoxy(14,4);cout<<"YOU WIN!"<<endl;bul=0;}
	Sleep(dela);
}//end while
	// Close the handle to the thread

	if(dela>0){gotoxy(14,4);colorit(12);cout<<"GAME OVER"<<endl;colorit(15);}
g=0,bul=1,l=0,r;
score=1,level=1,dela=100;
	Sleep(1000);
	system("cls");
    gotoxy(14,4);colorit(12);cout<<"GAME OVER"<<endl;colorit(15);
    Sleep(1500);
    showMenu();

}
/////////////////////////////////////////////////////////////////////////////
void exitGame(){
CloseHandle(hThread);
system("cls");
gotoxy(3,3);cout<<"GOOD BYE!";
colorit(15);
Sleep(2500);
}
////////////////////////////////////////////////////
int key;
int showMenu(){
    int ret=1;
    system("cls");

        key=0;
        system("cls");
        while(key!=13){
        gotoxy(3,3);
        colorit(15);
        cout<<"CAR GAME CONSOLE";//cout<<key<<"---"<<index;
        gotoxy(3,4);
        cout<<"================";
        gotoxy(3,5);
        colorit(15);
        if(index==1){colorit(12);}
        cout<<"START GAME";
        gotoxy(3,6);
        colorit(15);
        if(index==2){colorit(12);}
        cout<<"MORE GAMES";
        gotoxy(3,7);
        colorit(15);
        if(index==3){colorit(12);}
        cout<<"ABOUT";
        gotoxy(3,8);
        colorit(15);
        if(index==4){colorit(12);}
        cout<<"EXIT";
        gotoxy(20,12);
        colorit(15);cout<<"𝕎𝕙𝕒𝕥’𝕤 𝕓𝕖𝕙𝕚𝕟𝕕 𝕪𝕠𝕦 𝕕𝕠𝕖𝕤𝕟’𝕥 𝕞𝕒𝕥𝕥𝕖𝕣.";colorit(15);
        gotoxy(0,0);
        /////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==5){index=1;}
        if(index==0){index=4;}
        }
        if(index==1){
                startGame();
        }
        else if (index==2){
            ShellExecute( NULL, TEXT( "open" ), TEXT( "https://github.com/kalanakt" ), NULL, NULL, 0 );
            showMenu();
        }
        else if (index==3){
            system("cls");
            gotoxy(3,3);cout<<"Car Console Game";
	    gotoxy(3,4);cout<<"Using C , C++";
            Sleep(5000);
            showMenu();
        }

        else if (index==4){
                ret=1;
            exitGame();
        }
    return ret;
}




