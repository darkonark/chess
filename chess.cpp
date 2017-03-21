#include <iostream>
#include<string>
using namespace std;
string command;
char id;
int rowpass, colpass, lightrowpass, lightcolpass, turncounter = 0;
char board [8][8] = {{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
char lightboard[8][8] ={{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
bool pa =0, pb= 0, pc =0, pd =0, pe =0, pf =0, pg =0, ph =0, PA =0, PB =0, PC =0, PD =0, PE =0, PF =0, PG =0, PH = 0;
bool gamestart = false, flipflop;
void printboard (void){
	int col, row;	
	cout<<"    Board"<<endl;
	for (row = 0; row <8; row++){
		for (col =0; col <8; col++){
			cout<<" "<<board[row][col];
		}
		cout<<endl;}
}//end of printboard function
void printlightboard (void){
	cout<<"  Light_Board"<<endl;
	int col, row;	
	for (row = 0; row <8; row++){
		for (col =0; col <8; col++){
			cout<<" "<<lightboard[row][col];
		}
		cout<<endl;}
}//end of printlightboard function
char identify (string command){//identify piece function
	int col, row;
	if (command.substr(0,1) == "a"){
		col = 0;
		}
		else if (command.substr(0,1) == "b"){
			col = 1;
		}
		else if (command.substr(0,1) == "c"){
			col = 2;
		}
		else if (command.substr(0,1) == "d"){
			col = 3;
		}
		else if (command.substr(0,1) == "e"){
			col = 4;
		}
		else if (command.substr(0,1) == "f"){
			col = 5;
		}
		else if (command.substr(0,1) == "g"){
			col = 6;
		}
		else if (command.substr(0,1) == "h"){
			col = 7;
		}
	if (command.substr(1,1) == "8"){
		row = 0;
		}
		else if (command.substr(1,1) == "7"){
			row = 1;
		}
		else if (command.substr(1,1) == "6"){
			row = 2;
		}
		else if (command.substr(1,1) == "5"){
			row = 3;
		}
		else if (command.substr(1,1) == "4"){
			row = 4;
		}
		else if (command.substr(1,1) == "3"){
			row = 5;
		}
		else if (command.substr(1,1) == "2"){
			row = 6;
		}
		else if (command.substr(1,1) == "1"){
			row = 7;
		}
	rowpass = row;
	colpass = col;
	return board[row][col];
}//end of piece identifying function
char cando (string command){
	int col, row;
	if (command.substr(0,1) == "a"){
		col = 0;
		}
		else if (command.substr(0,1) == "b"){
			col = 1;
		}
		else if (command.substr(0,1) == "c"){
			col = 2;
		}
		else if (command.substr(0,1) == "d"){
			col = 3;
		}
		else if (command.substr(0,1) == "e"){
			col = 4;
		}
		else if (command.substr(0,1) == "f"){
			col = 5;
		}
		else if (command.substr(0,1) == "g"){
			col = 6;
		}
		else if (command.substr(0,1) == "h"){
			col = 7;
		}
	if (command.substr(1,1) == "8"){
		row = 0;
		}
		else if (command.substr(1,1) == "7"){
			row = 1;
		}
		else if (command.substr(1,1) == "6"){
			row = 2;
		}
		else if (command.substr(1,1) == "5"){
			row = 3;
		}
		else if (command.substr(1,1) == "4"){
			row = 4;
		}
		else if (command.substr(1,1) == "3"){
			row = 5;
		}
		else if (command.substr(1,1) == "2"){
			row = 6;
		}
		else if (command.substr(1,1) == "1"){
			row = 7;
		}
	lightrowpass = row;
	lightcolpass = col;
	return lightboard[row][col];
}//end of CanDo functiom
void lightreset(void){
	int col, row;	
	for (row = 0; row <8; row++){
		for (col =0; col <8; col++){
		lightboard[row][col] = board[row][col];
		}
	}
		printlightboard();
}//end of lightreset function
bool seeiflowercase(int row,int col){
	if(board[row][col] =='k' || board[row][col] =='q' || board[row][col] =='b' || board[row][col] =='r' || board[row][col] =='n' || board[row][col] =='p' )
	{
	return true;
	}
	else
		{
		return false;
		}
}//end of see_if_lower_case function
bool seeifuppercase(int row,int col){
	if(board[row][col] =='K' || board[row][col] =='Q' || board[row][col] =='B' || board[row][col] =='R' || board[row][col] =='N' || board[row][col] =='P' )
	{
	return true;
	}
	else
		{
		return false;
		}
}//end of see_if_upper_case function
int pawntick(bool used){ //dependancy of pawndistance function
	if (used == 0)
		{
		return 2;//first time being used
		}
	else
		{
		return 1;//not the first time being used
		}
} //end of pawntick function

int pawndistance(void){//determines how far a pawn can forward
	int inuse;
	if (board[rowpass][colpass] == 'p')
		{
		if(colpass == 0)
			{
			inuse = pawntick(pa);
			pa = 1;
			}
		else if (colpass == 1)
			{
			inuse = pawntick(pb);
			pb = 1;
			}
		else if (colpass == 2)
			{
			inuse = pawntick(pc);
			pc = 1;			
			}
		else if (colpass == 3)
			{
			inuse = pawntick(pd);
			pd = 1;
			}
		else if (colpass == 4)
			{
			inuse = pawntick(pe);
			pe = 1;
			}
		else if (colpass == 5)
			{
			inuse = pawntick(pf);
			pf = 1;
			}
		else if (colpass == 6)
			{
			inuse = pawntick(pg);
			pg = 1;
			}
		else if (colpass == 7)
			{
			inuse = pawntick(ph);
			ph = 1;
			}
		}
	else if (board[rowpass][colpass] == 'P')
		{
		if(colpass == 0)
			{
			inuse = pawntick(PA);
			PA = 1;
			}
		else if (colpass == 1)
			{
			inuse = pawntick(PB);
			PB = 1;
			}
		else if (colpass == 2)
			{
			inuse = pawntick(PC);
			PC = 1;
			}
		else if (colpass == 3)
			{
			inuse = pawntick(PD);
			PD = 1;
			}
		else if (colpass == 4)
			{
			inuse = pawntick(PE);
			PE = 1;
			}
		else if (colpass == 5)
			{
			inuse = pawntick(PF);
			PF = 1;
			}
		else if (colpass == 6)
			{
			inuse = pawntick(PG);
			PG = 1;
			}
		else if (colpass == 7)
			{
			inuse = pawntick(PH);
			PH = 1;
			}
		}
	return inuse;
}//end of pawndistance function

void lowercasepawnmove(void){
int pawnstep = pawndistance();
		int steps = 0;
		while (steps < pawnstep && rowpass != 0){
if (seeifuppercase(rowpass -1,colpass +1))
			{
			lightboard[rowpass -1][colpass +1] = 'X';
			}
		if (seeifuppercase(rowpass -1,colpass -1))
			{
			lightboard[rowpass -1][colpass -1] = 'X';
			}
			if (rowpass+steps >0 && seeifuppercase(rowpass+1,colpass) == false)
				{
				if (lightboard[rowpass-(steps+1)][colpass] == '.')
					{
					lightboard[rowpass-(steps+1)][colpass] = 'Y';
					}
				}
		printlightboard();
		steps++;
		}
}//end of lowercasepawnmove

void uppercasepawnmove(void){
int pawnstep = pawndistance();
		int steps = 0;
		while (steps < pawnstep && rowpass != 7){
		if (seeiflowercase(rowpass +1,colpass +1))
			{
			lightboard[rowpass +1][colpass +1] = 'X';
			}
		if (seeiflowercase(rowpass +1,colpass -1))
			{
			lightboard[rowpass +1][colpass -1] = 'X';
			}
			if (rowpass+steps <7 && seeifuppercase(rowpass+1,colpass) == false)
				{
				if (lightboard[rowpass+(steps+1)][colpass] == '.')
					{
					lightboard[rowpass+(steps+1)][colpass] = 'Y';
					}
				}
		printlightboard();
		steps++;
		}
}//end of uppercasepawnmove

void upperrookmove(void){
	int uprow = rowpass, downrow = rowpass, leftcol = colpass, rightcol = colpass;
	
	//DOWN LOOP (going + in array row)
	while (downrow < 7){
		if (seeifuppercase(downrow +1,colpass))
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (seeiflowercase(downrow +1,colpass))
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (seeifuppercase(uprow -1,colpass))
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (seeiflowercase(uprow -1,colpass))
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(seeifuppercase(rowpass,leftcol -1))
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (seeiflowercase(rowpass,leftcol -1))
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (seeifuppercase(rowpass,rightcol +1))
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(seeiflowercase(rowpass,rightcol +1))
			{
			lightboard[rowpass][rightcol +1] = 'X';
			break;
			}
	rightcol++;
	}
	printboard();
	printlightboard();
}//end of upperrookmove function


void lowerrookmove(void){
	int uprow = rowpass, downrow = rowpass, leftcol = colpass, rightcol = colpass;
	
	//DOWN LOOP (going + in array row)
	while (downrow < 7){
		if (seeiflowercase(downrow +1,colpass))
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (seeifuppercase(downrow +1,colpass))
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (seeiflowercase(uprow -1,colpass))
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (seeifuppercase(uprow -1,colpass))
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(seeiflowercase(rowpass,leftcol -1))
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (seeifuppercase(rowpass,leftcol -1))
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (seeiflowercase(rowpass,rightcol +1))
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(seeifuppercase(rowpass,rightcol +1))
			{
			lightboard[rowpass][rightcol +1] = 'X';
			break;
			}
	rightcol++;
	}
	printboard();
	printlightboard();
} //end of lowerrookmove function

void upperknightmove(void){
	if (rowpass + 2 <= 7 && colpass +1 <= 7) //d2r1
		{
		if (board[rowpass+2][colpass+1] =='.')
			{
			lightboard[rowpass+2][colpass+1] = 'Y';
			}
		else if (seeiflowercase(rowpass+2,colpass+1))
			{
			lightboard[rowpass+2][colpass+1] = 'X';
			}
		}
	if (rowpass + 2 <= 7 && colpass -1 >= 0) //d2l1
		{
		if (board[rowpass+2][colpass-1] =='.')
			{
			lightboard[rowpass+2][colpass-1] = 'Y';
			}
		else if (seeiflowercase(rowpass+2,colpass-1))
			{
			lightboard[rowpass+2][colpass-1] = 'X';
			}
		}
	if (rowpass - 2 >= 0 && colpass +1 <= 7) //u2r1
		{
		if (board[rowpass-2][colpass+1] =='.')
			{
			lightboard[rowpass-2][colpass+1] = 'Y';
			}
		else if (seeiflowercase(rowpass-2,colpass+1))
			{
			lightboard[rowpass-2][colpass+1] = 'X';
			}
		}
	if (rowpass -2 >= 0 && colpass -1 >= 0) //u2l1
		{
		if (board[rowpass-2][colpass-1] =='.')
			{
			lightboard[rowpass-2][colpass-1] = 'Y';
			}
		else if (seeiflowercase(rowpass-2,colpass-1))
			{
			lightboard[rowpass-2][colpass-1] = 'X';
			}
		}
	if (rowpass + 1 <= 7 && colpass +2 <= 7) //d1r2
		{
		if (board[rowpass+1][colpass+2] =='.')
			{
			lightboard[rowpass+1][colpass+2] = 'Y';
			}
		else if (seeiflowercase(rowpass+1,colpass+2))
			{
			lightboard[rowpass+1][colpass+2] = 'X';
			}
		}
	if (rowpass + 1 <= 7 && colpass -2 >= 0) //d1l2
		{
		if (board[rowpass+1][colpass-2] =='.')
			{
			lightboard[rowpass+1][colpass-2] = 'Y';
			}
		else if (seeiflowercase(rowpass+1,colpass-2))
			{
			lightboard[rowpass+1][colpass-2] = 'X';
			}
		}
	if (rowpass -1 >= 0 && colpass +2 <= 7) //u1r2
		{
		if (board[rowpass-1][colpass+2] =='.')
			{
			lightboard[rowpass-1][colpass+2] = 'Y';
			}
		else if (seeiflowercase(rowpass-1,colpass+2))
			{
			lightboard[rowpass-1][colpass+2] = 'X';
			}
		}
	if (rowpass -1 >= 0 && colpass -2 >= 0) //u1l2
		{
		if (board[rowpass-1][colpass-2] =='.')
			{
			lightboard[rowpass-1][colpass-2] = 'Y';
			}
		else if (seeiflowercase(rowpass-1,colpass-2))
			{
			lightboard[rowpass-1][colpass-2] = 'X';
			}
		}
	printboard();
	printlightboard();
} //end of upperknightmove function

void lowerknightmove(void){
	if (rowpass + 2 <= 7 && colpass +1 <= 7) //d2r1
		{
		if (board[rowpass+2][colpass+1] =='.')
			{
			lightboard[rowpass+2][colpass+1] = 'Y';
			}
		else if (seeifuppercase(rowpass+2,colpass+1))
			{
			lightboard[rowpass+2][colpass+1] = 'X';
			}
		}
	if (rowpass + 2 <= 7 && colpass -1 >= 0) //d2l1
		{
		if (board[rowpass+2][colpass-1] =='.')
			{
			lightboard[rowpass+2][colpass-1] = 'Y';
			}
		else if (seeifuppercase(rowpass+2,colpass-1))
			{
			lightboard[rowpass+2][colpass-1] = 'X';
			}
		}
	if (rowpass - 2 >= 0 && colpass +1 <= 7) //u2r1
		{
		if (board[rowpass-2][colpass+1] =='.')
			{
			lightboard[rowpass-2][colpass+1] = 'Y';
			}
		else if (seeifuppercase(rowpass-2,colpass+1))
			{
			lightboard[rowpass-2][colpass+1] = 'X';
			}
		}
	if (rowpass -2 >= 0 && colpass -1 >= 0) //u2l1
		{
		if (board[rowpass-2][colpass-1] =='.')
			{
			lightboard[rowpass-2][colpass-1] = 'Y';
			}
		else if (seeifuppercase(rowpass-2,colpass-1))
			{
			lightboard[rowpass-2][colpass-1] = 'X';
			}
		}
	if (rowpass + 1 <= 7 && colpass +2 <= 7) //d1r2
		{
		if (board[rowpass+1][colpass+2] =='.')
			{
			lightboard[rowpass+1][colpass+2] = 'Y';
			}
		else if (seeifuppercase(rowpass+1,colpass+2))
			{
			lightboard[rowpass+1][colpass+2] = 'X';
			}
		}
	if (rowpass + 1 <= 7 && colpass -2 >= 0) //d1l2
		{
		if (board[rowpass+1][colpass-2] =='.')
			{
			lightboard[rowpass+1][colpass-2] = 'Y';
			}
		else if (seeifuppercase(rowpass+1,colpass-2))
			{
			lightboard[rowpass+1][colpass-2] = 'X';
			}
		}
	if (rowpass -1 >= 0 && colpass +2 <= 7) //u1r2
		{
		if (board[rowpass-1][colpass+2] =='.')
			{
			lightboard[rowpass-1][colpass+2] = 'Y';
			}
		else if (seeifuppercase(rowpass-1,colpass+2))
			{
			lightboard[rowpass-1][colpass+2] = 'X';
			}
		}
	if (rowpass -1 >= 0 && colpass -2 >= 0) //u1l2
		{
		if (board[rowpass-1][colpass-2] =='.')
			{
			lightboard[rowpass-1][colpass-2] = 'Y';
			}
		else if (seeifuppercase(rowpass-1,colpass-2))
			{
			lightboard[rowpass-1][colpass-2] = 'X';
			}
		}
	printboard();
	printlightboard();
} //end of lowerknightmove function

void upperbishopmove(void){
	int nerow = rowpass, necol = colpass, nwrow = rowpass, nwcol = colpass, serow = rowpass, secol = colpass, swrow = rowpass, swcol = colpass;
	while(nerow >0 && necol >0){ //Northeast Loop 
		if(seeifuppercase(nerow -1,necol -1))
			{
			break;
			}
		else if (board[nerow-1][necol-1] == '.')
			{
			lightboard[nerow-1][necol-1] = 'Y';
			}
		else if(seeiflowercase(nerow -1,necol -1))
			{
			lightboard[nerow-1][necol-1] = 'X';
			break;
			}
	nerow--;
	necol--;
	}
	while(nwrow >0 && nwcol <7){ //Northwest Loop 
		if(seeifuppercase(nwrow -1,nwcol +1))
			{
			break;
			}
		else if (board[nwrow-1][nwcol+1] == '.')
			{
			lightboard[nwrow-1][nwcol+1] = 'Y';
			}
		else if(seeiflowercase(nwrow -1,nwcol +1))
			{
			lightboard[nwrow-1][nwcol+1] = 'X';
			break;
			}
	nwrow--;
	nwcol++;
	}
	while(serow <7 && secol >0){ //SouthEast Loop 
		if(seeifuppercase(serow +1,secol -1))
			{
			break;
			}
		else if (board[serow+1][secol-1] == '.')
			{
			lightboard[serow+1][secol-1] = 'Y';
			}
		else if(seeiflowercase(serow +1,secol -1))
			{
			lightboard[serow+1][secol-1] = 'X';
			break;
			}
	serow++;
	secol--;
	}
	while(swrow <7 && swcol <7){ //Southwest Loop 
		if(seeifuppercase(swrow +1,swcol +1))
			{
			break;
			}
		else if (board[swrow+1][swcol+1] == '.')
			{
			lightboard[swrow+1][swcol+1] = 'Y';
			}
		else if(seeiflowercase(swrow +1,swcol +1))
			{
			lightboard[swrow+1][swcol+1] = 'X';
			break;
			}
	swrow++;
	swcol++;
	}
	printboard();
	printlightboard();

}//end of upperbishopmove function


 	
void lowerbishopmove(void){
	int nerow = rowpass, necol = colpass, nwrow = rowpass, nwcol = colpass, serow = rowpass, secol = colpass, swrow = rowpass, swcol = colpass;
	while(nerow >0 && necol >0){ //Northeast Loop 
		if(seeiflowercase(nerow -1,necol -1))
			{
			break;
			}
		else if (board[nerow-1][necol-1] == '.')
			{
			lightboard[nerow-1][necol-1] = 'Y';
			}
		else if(seeifuppercase(nerow -1,necol -1))
			{
			lightboard[nerow-1][necol-1] = 'X';
			break;
			}
	nerow--;
	necol--;
	}
	while(nwrow >0 && nwcol <7){ //Northwest Loop 
		if(seeiflowercase(nwrow -1,nwcol +1))
			{
			break;
			}
		else if (board[nwrow-1][nwcol+1] == '.')
			{
			lightboard[nwrow-1][nwcol+1] = 'Y';
			}
		else if(seeifuppercase(nwrow -1,nwcol +1))
			{
			lightboard[nwrow-1][nwcol+1] = 'X';
			break;
			}
	nwrow--;
	nwcol++;
	}
	while(serow <7 && secol >0){ //SouthEast Loop 
		if(seeiflowercase(serow +1,secol -1))
			{
			break;
			}
		else if (board[serow+1][secol-1] == '.')
			{
			lightboard[serow+1][secol-1] = 'Y';
			}
		else if(seeifuppercase(serow +1,secol -1))
			{
			lightboard[serow+1][secol-1] = 'X';
			break;
			}
	serow++;
	secol--;
	}
	while(swrow <7 && swcol <7){ //Southwest Loop 
		if(seeiflowercase(swrow +1,swcol +1))
			{
			break;
			}
		else if (board[swrow+1][swcol+1] == '.')
			{
			lightboard[swrow+1][swcol+1] = 'Y';
			}
		else if(seeifuppercase(swrow +1,swcol +1))
			{
			lightboard[swrow+1][swcol+1] = 'X';
			break;
			}
	swrow++;
	swcol++;
	}
	printboard();
	printlightboard();
}//end of lowerbishopmove function

void upperqueenmove(void){
int uprow = rowpass, downrow = rowpass, leftcol = colpass, rightcol = colpass, nerow = rowpass, necol = colpass, nwrow = rowpass, nwcol = colpass, serow = rowpass, secol = colpass, swrow = rowpass, swcol = colpass;


	//DOWN LOOP (going + in array row)
	while (downrow < 7){
		if (seeifuppercase(downrow +1,colpass))
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (seeiflowercase(downrow +1,colpass))
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (seeifuppercase(uprow -1,colpass))
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (seeiflowercase(uprow -1,colpass))
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(seeifuppercase(rowpass,leftcol -1))
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (seeiflowercase(rowpass,leftcol -1))
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (seeifuppercase(rowpass,rightcol +1))
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(seeiflowercase(rowpass,rightcol +1))
			{
			lightboard[rowpass][rightcol +1] = 'X';
			break;
			}
	rightcol++;
	}
	while(nerow >0 && necol >0){ //Northeast Loop 
		if(seeifuppercase(nerow -1,necol -1))
			{
			break;
			}
		else if (board[nerow-1][necol-1] == '.')
			{
			lightboard[nerow-1][necol-1] = 'Y';
			}
		else if(seeiflowercase(nerow -1,necol -1))
			{
			lightboard[nerow-1][necol-1] = 'X';
			break;
			}
	nerow--;
	necol--;
	}
	while(nwrow >0 && nwcol <7){ //Northwest Loop 
		if(seeifuppercase(nwrow -1,nwcol +1))
			{
			break;
			}
		else if (board[nwrow-1][nwcol+1] == '.')
			{
			lightboard[nwrow-1][nwcol+1] = 'Y';
			}
		else if(seeiflowercase(nwrow -1,nwcol +1))
			{
			lightboard[nwrow-1][nwcol+1] = 'X';
			break;
			}
	nwrow--;
	nwcol++;
	}
	while(serow <7 && secol >0){ //SouthEast Loop 
		if(seeifuppercase(serow +1,secol -1))
			{
			break;
			}
		else if (board[serow+1][secol-1] == '.')
			{
			lightboard[serow+1][secol-1] = 'Y';
			}
		else if(seeiflowercase(serow +1,secol -1))
			{
			lightboard[serow+1][secol-1] = 'X';
			break;
			}
	serow++;
	secol--;
	}
	while(swrow <7 && swcol <7){ //Southwest Loop 
		if(seeifuppercase(swrow +1,swcol +1))
			{
			break;
			}
		else if (board[swrow+1][swcol+1] == '.')
			{
			lightboard[swrow+1][swcol+1] = 'Y';
			}
		else if(seeiflowercase(swrow +1,swcol +1))
			{
			lightboard[swrow+1][swcol+1] = 'X';
			break;
			}
	swrow++;
	swcol++;
	}
	printboard();
	printlightboard();
}//end of upper queen move function
void lowerqueenmove(void){
int uprow = rowpass, downrow = rowpass, leftcol = colpass, rightcol = colpass, nerow = rowpass, necol = colpass, nwrow = rowpass, nwcol = colpass, serow = rowpass, secol = colpass, swrow = rowpass, swcol = colpass;
	//DOWN LOOP (going + in array row)
	while (downrow < 7){
		if (seeiflowercase(downrow +1,colpass))
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (seeifuppercase(downrow +1,colpass))
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (seeiflowercase(uprow -1,colpass))
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (seeifuppercase(uprow -1,colpass))
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(seeiflowercase(rowpass,leftcol -1))
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (seeifuppercase(rowpass,leftcol -1))
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (seeiflowercase(rowpass,rightcol +1))
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(seeifuppercase(rowpass,rightcol +1))
			{
			lightboard[rowpass][rightcol +1] = 'X';
			break;
			}
	rightcol++;
	}
		while(nerow >0 && necol >0){ //Northeast Loop 
		if(seeiflowercase(nerow -1,necol -1))
			{
			break;
			}
		else if (board[nerow-1][necol-1] == '.')
			{
			lightboard[nerow-1][necol-1] = 'Y';
			}
		else if(seeifuppercase(nerow -1,necol -1))
			{
			lightboard[nerow-1][necol-1] = 'X';
			break;
			}
	nerow--;
	necol--;
	}
	while(nwrow >0 && nwcol <7){ //Northwest Loop 
		if(seeiflowercase(nwrow -1,nwcol +1))
			{
			break;
			}
		else if (board[nwrow-1][nwcol+1] == '.')
			{
			lightboard[nwrow-1][nwcol+1] = 'Y';
			}
		else if(seeifuppercase(nwrow -1,nwcol +1))
			{
			lightboard[nwrow-1][nwcol+1] = 'X';
			break;
			}
	nwrow--;
	nwcol++;
	}
	while(serow <7 && secol >0){ //SouthEast Loop 
		if(seeiflowercase(serow +1,secol -1))
			{
			break;
			}
		else if (board[serow+1][secol-1] == '.')
			{
			lightboard[serow+1][secol-1] = 'Y';
			}
		else if(seeifuppercase(serow +1,secol -1))
			{
			lightboard[serow+1][secol-1] = 'X';
			break;
			}
	serow++;
	secol--;
	}
	while(swrow <7 && swcol <7){ //Southwest Loop 
		if(seeiflowercase(swrow +1,swcol +1))
			{
			break;
			}
		else if (board[swrow+1][swcol+1] == '.')
			{
			lightboard[swrow+1][swcol+1] = 'Y';
			}
		else if(seeifuppercase(swrow +1,swcol +1))
			{
			lightboard[swrow+1][swcol+1] = 'X';
			break;
			}
	swrow++;
	swcol++;
	}
	printboard();
	printlightboard();
}//end of lower queen move function

void upperkingmove(void){
int row = rowpass, col = colpass;
	if(row-1 >0) //UP
		{
		if(seeiflowercase(row-1, col))
			{
			lightboard[row-1][col] ='X';
			}
		else if(board[row-1][col] ='.')
			{
			lightboard[row-1][col] ='Y';
			}
		}
	if(row-1 >0 && col+1 <7) //UP & RIGHT
		{
		if(seeiflowercase(row-1, col+1))
			{
			lightboard[row-1][col+1] ='X';
			}
		else if(board[row-1][col+1] ='.')
			{
			lightboard[row-1][col+1] ='Y';
			}
		}
	if(row-1 >0 && col-1 >0) //UP & LEFT
		{
		if(seeiflowercase(row-1, col-1))
			{
			lightboard[row-1][col-1] ='X';
			}
		else if(board[row-1][col-1] ='.')
			{
			lightboard[row-1][col-1] ='Y';
			}
		}
	if(col+1 <7) //RIGHT
		{
		if(seeiflowercase(row, col+1))
			{
			lightboard[row][col+1] ='X';
			}
		else if(board[row][col+1] ='.')
			{
			lightboard[row][col+1] ='Y';
			}
		}
	if(col-1 >0) //LEFT
		{
		if(seeiflowercase(row, col-1))
			{
			lightboard[row][col-1] ='X';
			}
		else if(board[row][col-1] ='.')
			{
			lightboard[row][col-1] ='Y';
			}
		}
	if(row+1 <7) //DOWN
		{
		if(seeiflowercase(row+1, col))
			{
			lightboard[row+1][col] ='X';
			}
		else if(board[row+1][col] ='.')
			{
			lightboard[row+1][col] ='Y';
			}
		}
	if(row+1 <7 && col+1 <7) //DOWN & RIGHT
		{
		if(seeiflowercase(row+1, col+1))
			{
			lightboard[row+1][col+1] ='X';
			}
		else if(board[row+1][col+1] ='.')
			{
			lightboard[row+1][col+1] ='Y';
			}
		}
	if(row+1 <7 && col-1 >0) //DOWN & LEFT
		{
		if(seeiflowercase(row+1, col-1))
			{
			lightboard[row+1][col-1] ='X';
			}
		else if(board[row+1][col-1] ='.')
			{
			lightboard[row+1][col-1] ='Y';
			}
		}
	printboard();
	printlightboard();
} // end of upper king move function
void lowerkingmove(void){
int row = rowpass, col = colpass;
	if(row-1 >0) //UP
		{
		if(seeifuppercase(row-1, col))
			{
			lightboard[row-1][col] ='X';
			}
		else if(board[row-1][col] ='.')
			{
			lightboard[row-1][col] ='Y';
			}
		}
	if(row-1 >0 && col+1 <7) //UP & RIGHT
		{
		if(seeifuppercase(row-1, col+1))
			{
			lightboard[row-1][col+1] ='X';
			}
		else if(board[row-1][col+1] ='.')
			{
			lightboard[row-1][col+1] ='Y';
			}
		}
	if(row-1 >0 && col-1 >0) //UP & LEFT
		{
		if(seeifuppercase(row-1, col-1))
			{
			lightboard[row-1][col-1] ='X';
			}
		else if(board[row-1][col-1] ='.')
			{
			lightboard[row-1][col-1] ='Y';
			}
		}
	if(col+1 <7) //RIGHT
		{
		if(seeifuppercase(row, col+1))
			{
			lightboard[row][col+1] ='X';
			}
		else if(board[row][col+1] ='.')
			{
			lightboard[row][col+1] ='Y';
			}
		}
	if(col-1 >0) //LEFT
		{
		if(seeifuppercase(row, col-1))
			{
			lightboard[row][col-1] ='X';
			}
		else if(board[row][col-1] ='.')
			{
			lightboard[row][col-1] ='Y';
			}
		}
	if(row+1 <7) //DOWN
		{
		if(seeifuppercase(row+1, col))
			{
			lightboard[row+1][col] ='X';
			}
		else if(board[row+1][col] ='.')
			{
			lightboard[row+1][col] ='Y';
			}
		}
	if(row+1 <7 && col+1 <7) //DOWN & RIGHT
		{
		if(seeifuppercase(row+1, col+1))
			{
			lightboard[row+1][col+1] ='X';
			}
		else if(board[row+1][col+1] ='.')
			{
			lightboard[row+1][col+1] ='Y';
			}
		}
	if(row+1 <7 && col-1 >0) //DOWN & LEFT
		{
		if(seeifuppercase(row+1, col-1))
			{
			lightboard[row+1][col-1] ='X';
			}
		else if(board[row+1][col-1] ='.')
			{
			lightboard[row+1][col-1] ='Y';
			}
		}
	printboard();
	printlightboard();
}//end of lowerkingmove function
void engine(char piece){ 
	char willdo;
	if (piece == 'p')
		{
		lowercasepawnmove();
		}
	else if (piece == 'P')
		{
		uppercasepawnmove();
		}
	else if (piece == 'R')
		{
		upperrookmove();
		}
	else if (piece == 'r')
		{
		lowerrookmove();
		}
	else if (piece =='N')
		{
		upperknightmove();
		}
	else if (piece == 'n')
		{
		lowerknightmove();
		}
	else if (piece == 'B')
		{
		upperbishopmove();
		}
	else if (piece == 'b')
		{
		lowerbishopmove();
		}
	else if (piece == 'q')
		{
		lowerqueenmove();
		}
	else if (piece == 'Q')
		{
		upperqueenmove();
		}
	else if (piece == 'k')
		{
		lowerkingmove();
		}
	else if (piece == 'K')
		{
		upperkingmove();
		}
	else
		{
		return;
		}
	bool breakerbool = 0;
	while(1){ //need to only be able to move peice where it can go as marked by Xs and Ys on the lightboard
	string mover;
	cout<<"enter coordianate to move peice"<<endl;
	getline(cin,mover);
	if (mover.substr(0, 1) >= "a" && mover.substr(0, 1) <= "h" && mover.substr(1, 1) >= "1" && mover.substr(1, 1) <= "8")
		{
		willdo = cando(mover);
		if(willdo == 'X' || willdo == 'Y' || willdo == id)
			{
			board[rowpass][colpass] = '.';
			board[lightrowpass][lightcolpass] = id;
			printboard();
			lightreset();
			cout<<"piece moved to "<<mover.substr(0,2)<<endl;
			breakerbool = 1;
			}
		else
			{
			cout<<"you cannot move there"<<endl;
			lightreset();
			printboard();
			}
		}
	else
		{
		cout<<"invalid, enter a different coordinate (letter number)"<<endl;
		}
	if (breakerbool = 1)
		{
		break;
		}
	}
}//end of engine function

int main() {
	int turnNo = 0;
	cout<<"chess test, commands are 'print','exit', and 'deselect'"<<endl;
	cout<<"or enter a coordinate to activate a peice"<<endl;
	cout<<"follow your command with the RETURN key"<<endl;
	while(1){ //infinite loop
	cout<<"enter a coordinate to activate a peice"<<endl;
	cout<<"follow your command with the RETURN key"<<endl;
	getline(cin,command);
	id = identify(command);
	if (command.substr(0,4) == "exit")
		{
		break;
		}
	if (command.substr(0,5) == "print")
		{
		printboard();
		continue;
		}
	if (command.substr(0,8) =="deselect")
		{
		lightreset();
		continue;
		}
	if (command.substr(0, 1) >= "a" && command.substr(0, 1) <= "h" && command.substr(1, 1) >= "1" && command.substr(1, 1) <= "8")
		{
		if (gamestart ==true)
			{
			if((id=='K' || id=='Q'|| id=='B' || id=='N' || id=='R' || id=='P') && flipflop == false)
				{
				cout<<"lowercase turn, not uppercase"<<endl;
				continue;
				}
			if((id=='k' || id=='q'|| id=='b' || id=='n' || id=='r' || id=='p')&& flipflop == true)
				{
				cout<<"uppercase turn, not lowercase"<<endl;
				continue;
				}
			}
		if (gamestart == false)
			{
			if(id=='K' || id=='Q'|| id=='B' || id=='N' || id=='R' || id=='P')
				{
				cout<<"uppercase first"<<endl;
				flipflop = true;//uppercase has first move
				gamestart = true;
				}
			else if(id=='k' || id=='q'|| id=='b' || id=='n' || id=='r' || id=='p')
				{
				cout<<"lowercase first"<<endl;
				flipflop = false; //lowercase goes first
				gamestart = true;
				}
			else
				{
				cout<<"You picked an empty space."<<endl;
				continue;
				}
			}
		if(id =='.')
			{
			cout<<"You picked an empty space."<<endl;
			continue;
			}
		else
			{
			cout<<"the selected piece is "<<id<<endl;
			engine(id);
			if (flipflop == true)
				{
				flipflop = false;
				}
			else
				{
				flipflop = true;
				}
			}
		}
	else
		{
		cout<<"invalid, try another command"<<endl;
		}
	} //end of the main loop
return 0;}
