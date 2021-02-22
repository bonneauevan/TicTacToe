#include <iostream>

//maybe look into editing the board inline instead of drawing a new board after each move
void updateBoard(char game[]){
	std::cout << " " << game[0] << " | " << game[1] << " | "<< game[2] << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << " " << game[3] << " | " << game[4] << " | "<< game[5] << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << " " << game[6] << " | " << game[7] << " | "<< game[8] << std::endl;
	return;
}

// this function is gross and i want to make it better 
bool checkWin(char game[]){
	if(game[0] == game[1] && game[1] == game[2]) return true;
	if(game[3] == game[4] && game[4] == game[5]) return true;
	if(game[6] == game[7] && game[7] == game[8]) return true;
	if(game[0] == game[3] && game[3] == game[6]) return true;
	if(game[1] == game[4] && game[4] == game[7]) return true;
	if(game[2] == game[5] && game[5] == game[8]) return true;
	if(game[0] == game[4] && game[4] == game[8]) return true;
	if(game[2] == game[4] && game[4] == game[6]) return true;
	return false;
}

bool checkDraw(char game[]){
	for(int i=0; i<9; i++){
		if(game[i] == ('0'+ i)) return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	// set the initial game characters to serve as an input indicator to the player
	char game[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
	int player = 0;
	int choice; 

	//draw initial state of the game
	updateBoard(game);

	while(true){ // main game loop, exits on win or draw
		
		std::cout << "Player " << player+1 << " Please enter your move: " << std::endl;
		std::cin >> choice; 

		while(std::cin.fail() || choice < 0 || choice > 8 || game[choice] != (char)('0'+ choice)){
			//verifies the input and checks if it is available. If not another input is requested
			//next two lines clear the cin fail state if an int isnt seen and
			//flush the input stream so that a new int can be accepted.
			std::cin.clear();	
			std::cin.ignore();	
			std::cout << "Please enter a valid input..." << std::endl;
			std::cin >> choice;
		}

		//set the space the player selected to their mark
		game[choice] = player==0 ? 'X' : 'O';

		//draw the players move on the screen
		updateBoard(game);

		//check if the player played the winning move
		if(checkWin(game)){
			std::cout << "Player " << player+1 << " wins!" << std::endl;
			return 0;
		}
		//if there are no empty spaces the game is a draw
		if(checkDraw(game)){
			std::cout << "The game ends in a draw" << std::endl;
			return 0;
		}
		//pass the turn to the other player
		player=(player+1)%2;
	}
}