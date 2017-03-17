#include <iostream>
#include<string>
using namespace std;
string command;
char id, idd;
int rowpass, colpass, lightrowpass, lightcolpass;
char board [8][8] = {{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
char lightboard[8][8] ={{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
bool pa =0, pb= 0, pc =0, pd =0, pe =0, pf =0, pg =0, ph =0, PA =0, PB =0, PC =0, PD =0, PE =0, PF =0, PG =0, PH = 0;

class piece {
	public:
	//stuff
};
class king {
	public:
//	void initiate (button interrupt)
};
class queen {
	public:
//	void initiate (button interrupt)
};
class bishop {
	public:
//	void initiate (button interrupt)
};
class knight {
	public:
//	void initiate (button interrupt)
};
class rook {
	public:
//	void initiate (button interrupt)
};
class pawn {
	public:

//	void initiate (button interrupt)
};



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
if (board[rowpass -1][colpass +1] == 'P' || board[rowpass -1][colpass +1] == 'R' || board[rowpass -1][colpass +1] == 'N' || board[rowpass -1][colpass +1] == 'B' || board[rowpass -1][colpass +1] == 'K' || lightboard[rowpass -1][colpass +1] == 'Q')
			{
			lightboard[rowpass -1][colpass +1] = 'X';
			}
		if (board[rowpass -1][colpass -1] == 'P' || board[rowpass -1][colpass -1] == 'R' || board[rowpass -1][colpass -1] == 'N' || board[rowpass -1][colpass -1] == 'B' || board[rowpass -1][colpass -1] == 'K' || board[rowpass -1][colpass -1] == 'Q')
			{
			lightboard[rowpass -1][colpass -1] = 'X';
			}
			if (rowpass+steps >0 && board[rowpass+1][colpass] != 'P' && board[rowpass+1][colpass] != 'R' && board[rowpass+1][colpass] != 'N' && board[rowpass+1][colpass] != 'B' && board[rowpass+1][colpass] != 'Q' && board[rowpass+1][colpass] != 'K')
				{
				if (lightboard[rowpass-(steps+1)][colpass] == '.')
					{
cout<<"304 & steps="<<steps<<endl;
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
		if (board[rowpass +1][colpass +1] == 'p' || board[rowpass +1][colpass +1] == 'r' || board[rowpass +1][colpass +1] == 'n' || board[rowpass +1][colpass +1] == 'b' || board[rowpass +1][colpass +1] == 'k' || lightboard[rowpass +1][colpass +1] == 'q')
			{
			lightboard[rowpass +1][colpass +1] = 'X';
			}
		if (board[rowpass +1][colpass -1] == 'p' || board[rowpass +1][colpass -1] == 'r' || board[rowpass +1][colpass -1] == 'n' || board[rowpass +1][colpass -1] == 'b' || board[rowpass +1][colpass -1] == 'k' || board[rowpass +1][colpass -1] == 'q')
			{
			lightboard[rowpass +1][colpass -1] = 'X';
			}
			if (rowpass+steps <7 && board[rowpass+1][colpass] != 'P' && board[rowpass+1][colpass] != 'R' && board[rowpass+1][colpass] != 'N' && board[rowpass+1][colpass] != 'B' && board[rowpass+1][colpass] != 'Q' && board[rowpass+1][colpass] != 'K')
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
		if (board[downrow +1][colpass] == 'K' || board[downrow +1][colpass] == 'Q' || board[downrow +1][colpass] == 'B' || board[downrow +1][colpass] == 'R' || board[downrow +1][colpass] == 'N' || board[downrow +1][colpass] == 'P')
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (board[downrow +1][colpass] == 'k' || board[downrow +1][colpass] == 'q' || board[downrow +1][colpass] == 'b' || board[downrow +1][colpass] == 'r' || board[downrow +1][colpass] == 'n' || board[downrow +1][colpass] == 'p')
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (board[uprow -1][colpass] == 'K' || board[uprow -1][colpass] == 'Q' || board[uprow -1][colpass] == 'B' || board[uprow -1][colpass] == 'R' || board[uprow -1][colpass] == 'N' || board[uprow -1][colpass] == 'P')
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (board[uprow -1][colpass] == 'k' || board[uprow -1][colpass] == 'q' || board[uprow -1][colpass] == 'b' || board[uprow -1][colpass] == 'r' || board[uprow -1][colpass] == 'n' || board[uprow -1][colpass] == 'p')
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(board[rowpass][leftcol -1] =='K' || board[rowpass][leftcol -1] =='Q' || board[rowpass][leftcol -1] =='B' || board[rowpass][leftcol -1] =='R' || board[rowpass][leftcol -1] =='N' || board[rowpass][leftcol -1] =='P')
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (board[rowpass][leftcol -1] =='k' || board[rowpass][leftcol -1] =='q' || board[rowpass][leftcol -1] =='b' || board[rowpass][leftcol -1] =='r' || board[rowpass][leftcol -1] =='n' || board[rowpass][leftcol -1] =='p')
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (board[rowpass][rightcol +1] =='K' || board[rowpass][rightcol +1] =='Q' || board[rowpass][rightcol +1] =='B' || board[rowpass][rightcol +1] =='R' || board[rowpass][rightcol +1] =='N' || board[rowpass][rightcol +1] =='P')
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(board[rowpass][rightcol +1] =='k' || board[rowpass][rightcol +1] =='q' || board[rowpass][rightcol +1] =='b' || board[rowpass][rightcol +1] =='r' || board[rowpass][rightcol +1] =='n' || board[rowpass][rightcol +1] =='p')
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
		if (board[downrow +1][colpass] == 'k' || board[downrow +1][colpass] == 'q' || board[downrow +1][colpass] == 'b' || board[downrow +1][colpass] == 'r' || board[downrow +1][colpass] == 'n' || board[downrow +1][colpass] == 'p')
			{
			break;
			}
		else if( board[downrow +1][colpass] == '.')
			{
			lightboard[downrow +1][colpass] = 'Y';
			}
		else if (board[downrow +1][colpass] == 'K' || board[downrow +1][colpass] == 'Q' || board[downrow +1][colpass] == 'B' || board[downrow +1][colpass] == 'R' || board[downrow +1][colpass] == 'N' || board[downrow +1][colpass] == 'P')
			{
			lightboard[downrow +1][colpass] = 'X';
			break;
			}
	downrow++;
	}
	//UP LOOP (going - in array row)
	while (uprow >0){
		if (board[uprow -1][colpass] == 'k' || board[uprow -1][colpass] == 'q' || board[uprow -1][colpass] == 'b' || board[uprow -1][colpass] == 'r' || board[uprow -1][colpass] == 'n' || board[uprow -1][colpass] == 'p')
			{
			break;
			}
		else if( board[uprow -1][colpass] == '.')
			{
			lightboard[uprow - 1][colpass] = 'Y';
			}
		else if (board[uprow -1][colpass] == 'K' || board[uprow -1][colpass] == 'Q' || board[uprow -1][colpass] == 'B' || board[uprow -1][colpass] == 'R' || board[uprow -1][colpass] == 'N' || board[uprow -1][colpass] == 'P')
			{
			lightboard[uprow -1][colpass] = 'X';
			break;
			}
	uprow--;
	}
	//LEFT LOOP
	while(leftcol >0){
		if(board[rowpass][leftcol -1] =='k' || board[rowpass][leftcol -1] =='q' || board[rowpass][leftcol -1] =='b' || board[rowpass][leftcol -1] =='r' || board[rowpass][leftcol -1] =='n' || board[rowpass][leftcol -1] =='p')
			{
			break;
			}
		else if (board[rowpass][leftcol -1] == '.')
			{
			lightboard[rowpass][leftcol -1] ='Y';
			}
		else if (board[rowpass][leftcol -1] =='K' || board[rowpass][leftcol -1] =='Q' || board[rowpass][leftcol -1] =='B' || board[rowpass][leftcol -1] =='R' || board[rowpass][leftcol -1] =='N' || board[rowpass][leftcol -1] =='P')
			{
			lightboard[rowpass][leftcol -1] ='X';
			break;
			}
	leftcol--;
	}
	//RIGHT LOOP
	while(rightcol < 7){
		if (board[rowpass][rightcol +1] =='k' || board[rowpass][rightcol +1] =='q' || board[rowpass][rightcol +1] =='b' || board[rowpass][rightcol +1] =='r' || board[rowpass][rightcol +1] =='n' || board[rowpass][rightcol +1] =='p')
			{
			break;
			}
		else if (board[rowpass][rightcol +1] =='.')
			{
			lightboard[rowpass][rightcol +1] = 'Y';
			}
		else if(board[rowpass][rightcol +1] =='K' || board[rowpass][rightcol +1] =='Q' || board[rowpass][rightcol +1] =='B' || board[rowpass][rightcol +1] =='R' || board[rowpass][rightcol +1] =='N' || board[rowpass][rightcol +1] =='P')
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
		else if (board[rowpass+2][colpass+1] =='k' || board[rowpass+2][colpass+1] =='q' || board[rowpass+2][colpass+1] =='b' || board[rowpass+2][colpass+1] =='r' ||board[rowpass+2][colpass+1] =='n' || board[rowpass+2][colpass+1] =='p')
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
		else if (board[rowpass+2][colpass-1] =='k' || board[rowpass+2][colpass-1] =='q' || board[rowpass+2][colpass-1] =='b' || board[rowpass+2][colpass-1] =='r' ||board[rowpass+2][colpass-1] =='n' || board[rowpass+2][colpass-1] =='p')
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
		else if (board[rowpass-2][colpass+1] =='k' || board[rowpass-2][colpass+1] =='q' || board[rowpass-2][colpass+1] =='b' || board[rowpass-2][colpass+1] =='r' ||board[rowpass-2][colpass+1] =='n' || board[rowpass-2][colpass+1] =='p')
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
		else if (board[rowpass-2][colpass-1] =='k' || board[rowpass-2][colpass-1] =='q' || board[rowpass-2][colpass-1] =='b' || board[rowpass-2][colpass-1] =='r' ||board[rowpass-2][colpass-1] =='n' || board[rowpass-2][colpass-1] =='p')
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
		else if (board[rowpass+1][colpass+2] =='k' || board[rowpass+1][colpass+2] =='q' || board[rowpass+1][colpass+2] =='b' || board[rowpass+1][colpass+2] =='r' ||board[rowpass+1][colpass+2] =='n' || board[rowpass+1][colpass+2] =='p')
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
		else if (board[rowpass+1][colpass-2] =='k' || board[rowpass+1][colpass-2] =='q' || board[rowpass+1][colpass-2] =='b' || board[rowpass+1][colpass-2] =='r' ||board[rowpass+1][colpass-2] =='n' || board[rowpass+1][colpass-2] =='p')
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
		else if (board[rowpass-1][colpass+2] =='k' || board[rowpass-1][colpass+2] =='q' || board[rowpass-1][colpass+2] =='b' || board[rowpass-1][colpass+2] =='r' ||board[rowpass-1][colpass+2] =='n' || board[rowpass-1][colpass+2] =='p')
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
		else if (board[rowpass-1][colpass-2] =='k' || board[rowpass-1][colpass-2] =='q' || board[rowpass-1][colpass-2] =='b' || board[rowpass-1][colpass-2] =='r' ||board[rowpass-1][colpass-2] =='n' || board[rowpass-1][colpass-2] =='p')
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
		else if (board[rowpass+2][colpass+1] =='K' || board[rowpass+2][colpass+1] =='Q' || board[rowpass+2][colpass+1] =='B' || board[rowpass+2][colpass+1] =='R' ||board[rowpass+2][colpass+1] =='N' || board[rowpass+2][colpass+1] =='P')
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
		else if (board[rowpass+2][colpass-1] =='K' || board[rowpass+2][colpass-1] =='Q' || board[rowpass+2][colpass-1] =='B' || board[rowpass+2][colpass-1] =='R' ||board[rowpass+2][colpass-1] =='N' || board[rowpass+2][colpass-1] =='P')
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
		else if (board[rowpass-2][colpass+1] =='K' || board[rowpass-2][colpass+1] =='Q' || board[rowpass-2][colpass+1] =='B' || board[rowpass-2][colpass+1] =='R' ||board[rowpass-2][colpass+1] =='N' || board[rowpass-2][colpass+1] =='P')
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
		else if (board[rowpass-2][colpass-1] =='K' || board[rowpass-2][colpass-1] =='Q' || board[rowpass-2][colpass-1] =='B' || board[rowpass-2][colpass-1] =='R' ||board[rowpass-2][colpass-1] =='N' || board[rowpass-2][colpass-1] =='P')
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
		else if (board[rowpass+1][colpass+2] =='K' || board[rowpass+1][colpass+2] =='Q' || board[rowpass+1][colpass+2] =='B' || board[rowpass+1][colpass+2] =='R' ||board[rowpass+1][colpass+2] =='N' || board[rowpass+1][colpass+2] =='P')
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
		else if (board[rowpass+1][colpass-2] =='K' || board[rowpass+1][colpass-2] =='Q' || board[rowpass+1][colpass-2] =='B' || board[rowpass+1][colpass-2] =='R' ||board[rowpass+1][colpass-2] =='N' || board[rowpass+1][colpass-2] =='P')
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
		else if (board[rowpass-1][colpass+2] =='K' || board[rowpass-1][colpass+2] =='Q' || board[rowpass-1][colpass+2] =='B' || board[rowpass-1][colpass+2] =='R' ||board[rowpass-1][colpass+2] =='N' || board[rowpass-1][colpass+2] =='P')
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
		else if (board[rowpass-1][colpass-2] =='K' || board[rowpass-1][colpass-2] =='Q' || board[rowpass-1][colpass-2] =='B' || board[rowpass-1][colpass-2] =='R' ||board[rowpass-1][colpass-2] =='N' || board[rowpass-1][colpass-2] =='P')
			{
			lightboard[rowpass-1][colpass-2] = 'X';
			}
		}
	printboard();
	printlightboard();
} //end of lowerknightmove function

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
	else
		{
		return;
		}
	bool breakerbool = 0;
	while(1){ //need to only be able to move peice where it can go

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
			printlightboard();
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
		cout<<"coordiate"<<endl;
		if (id == '.')
			{
			cout<<"You picked an empty space."<<endl;
			continue;
			}
		else
			{
		cout<<"the selected piece is "<<id<<endl;
		engine(id);
			}
		}
	else
		{
		cout<<"invalid, try another command"<<endl;
		}
	} //end of the main loop
return 0;}
