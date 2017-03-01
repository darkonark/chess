#include <iostream>
#include<string>
using namespace std;

char board [8][8] = {{'R','N','B','K','Q','B','N','N'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};
int rowpass, colpass;
char lightboard[8][8] ={{'R','N','B','K','Q','B','N','N'},	{'P','P','P','P','P','P','P','P'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'p','p','p','p','p','p','p','p'},{'r','n','b','k','q','b','n','r'}};



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
/*const string K = "topking";
const char topqueen = 'Q';
const char toprook = 'R';
const char topbishop = 'B';
const char topknight = 'N';
const char toppawn = 'P';
const char btmking = 'k';
const char btmqueen = 'q';
const char btmrook = 'r';
const char btmbishop = 'b';
const char btmknight = 'n';
const char btmpawn = 'p';
const char empty ='.';
const char canmove ='X';    not sure if this will be needed at all*/

void printboard (void){
	int col, row;	
	for (row = 0; row <8; row++){
		for (col =0; col <8; col++){
			cout<<" "<<board[row][col];
		}
		cout<<endl;}
}//end of printboard function
void printlightboard (void){
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

void legality(char piece){ //this is thew next thing that needs worked on
	if (piece == 'p'){
		if (rowpass-1 >=0){
		lightboard[rowpass-1][colpass] = 'o';
		printlightboard();
		}
		
	}
	else{ return;}
}//end of legality function

void lightreset(void){
	int col, row;	
	for (row = 0; row <8; row++){
		for (col =0; col <8; col++){
		lightboard[row][col] = board[row][col];
		}
	}
		printlightboard();
}//end of lightreset function

int main() {
	int turnNo = 0;
	char id; //return value from identify function
	string command;
	cout<<"chess test, commands are 'print','exit', and 'deselect'"<<endl;
	cout<<"or enter a coordinate to activate a peice"<<endl;
	cout<<"follow your command with the RETURN key"<<endl;
	while(1){ //this is supposed to be an infinite loop
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
		legality(id);
		}
	else{ cout<<"invalid, try another command"<<endl;
		}
	} //end of the main loop
return 0;}
