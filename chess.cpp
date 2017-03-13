#include <iostream>
#include<string>
using namespace std;
string command;
char id; //return value from identify function
int rowpass, colpass, lightrowpass, lightcolpass;
char board [8][8] = {{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
char lightboard[8][8] ={{'R','N','B','K','Q','B','N','R'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
bool pa, pb, pc, pd, pe, pf, pg, ph, PA, PB, PC, PD, PE, PF, PG, PH = 0;

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

char identify (string command){
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

int pawndistance(void){
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
}

void engine(char piece){ //this is thew next thing that needs worked on
	char willdo;
	if (piece == 'p')
		{//going to need some bools to trip after a pawn is used once
		int pawnstep = pawndistance();
		int steps = 0	;
		while (steps < pawnstep){
			if (rowpass-steps >=0)
				{
				lightboard[rowpass-(steps+1)][colpass] = 'Y';
				printlightboard();
				steps++;
				}
		}
		}
	else if (piece == 'P')
		{//going to need some bools to trip after a pawn is used once
		int pawnstep = pawndistance();
		int steps = 0;
		while (steps < pawnstep){
			if (rowpass+steps <=7)
				{
				lightboard[rowpass+(steps+1)][colpass] = 'Y';
				printlightboard();
				steps++;
				}

		}
		}
	else
		{
		return;
		}
	while(1){ //need to only be able to move peice where it can go

	string mover;
	cout<<"enter coordianate to move peice"<<endl;
	getline(cin,mover);
	if (mover.substr(0, 1) >= "a" && mover.substr(0, 1) <= "h" && mover.substr(1, 1) >= "1" && mover.substr(1, 1) <= "8")
		{
		cout<<"piece moved to "<<mover.substr(0,2)<<endl;
		willdo = cando(mover);
		if(willdo == 'X' || willdo == 'Y')
			{
			board[lightrowpass][lightcolpass] = identify(command);
			board[rowpass][colpass] = '.';
			printboard();
			lightreset();
			break;
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
	}
}//end of engine function

int main() {
	int turnNo = 0;
	char id; //return value from identify function
	cout<<"chess test, commands are 'print','exit', and 'deselect'"<<endl;
	cout<<"or enter a coordinate to activate a peice"<<endl;
	cout<<"follow your command with the RETURN key"<<endl;
	while(1){ //infinite loop
	getline(cin,command);
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
		id = identify(command);
		cout<<"the selected piece is "<<id<<endl;
		engine(id);
		}
	else
		{
		cout<<"invalid, try another command"<<endl;
		}
	} //end of the main loop
return 0;}
