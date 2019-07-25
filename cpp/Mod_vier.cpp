#pragma once

#include "Mod_absolute.cpp"

//Überprüft ob man sich innerhalb des Spielfeldes bewegt
bool checkBoundary(List<Int> matrix, int width, int x, int y){
	if(x>=0 && x < width && y>=0 && length(matrix) > (y*width+x))
		return true;
	return false;
}

//Neuberechnung der Koordinaten
int dirChangeX(int x, int a){
	switch (a){
		case 0:                 //top
		case 4: return x;       //bot
		case 1:                 //right-top
		case 2:                 //right
		case 3: return x+1;     //right-bot
		case 5:                 //left-bot
		case 6:                 //left
		case 7: return x-1;     //left-top
	}
	return x;
}

int dirChangeY(int y, int a){
	switch (a){
		case 2:
		case 6: return y;
		case 7:
		case 0:
		case 1: return y+1;
		case 3:
		case 4:
		case 5: return y-1;
	}
	return y;
}

bool checkWon(List<Int> matrix, int width, int x, int y, int player){
	bool won = false;
	int pos = y*width +x;
	int xstart = x;
	int ystart = y;
	for(int a = 0; a<8; a++){
		x = xstart;
		y = ystart;
		pos = y*width +x;
		bool tmpWon = true;
		
        //vom Startpunkt in 8 Richtungen überrpüfen ob 4 in einer Reihe
		for(int i = 0; i<4; i++){
			if(checkBoundary(matrix, width, x, y)){
				if(get(matrix, pos) != player){
					tmpWon = false;
					break;
				}
			}else{
				tmpWon = false;
				break;
			}
			x = dirChangeX(x, a);
			y = dirChangeY(y, a);
			pos = y*width+x;
		}
		if(tmpWon){
			won = true;
			break;
		}
	}
	return won;
}



Int vier(List<Int> zugfolge){
	int max = 0;
	for(int i = 0; i<length(zugfolge); i++){
		max = sp_max(max, absolute(get(zugfolge, i)));
	}
	int width = 2*max+1;
	
	List<Int> matrix;
	for (int i = 0; i<length(zugfolge); i++){
		int h = 0;
		int player = (i%2)+1;
		int other;
		if(player == 1)
			other = 2;
		else 
			other = 1;
		int x = get(zugfolge, i) + max; // 0-basiert
		while(true){
			while(length(matrix) <= (h*width + x)){
				matrix = append(matrix, 0);
			}
			if(get(matrix, h*width + x) == 0){
				matrix = set(matrix, h*width + x, player);
				break;
			}else{
				h+=1;
			}
		}
        
		if(checkWon(matrix, width, x, h, player)){
			return player;
		}
	}
	return 0;
}
