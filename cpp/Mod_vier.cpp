#pragma once

#include "Mod_absolute.cpp"

bool checkBoundary(List<Int> matrix, int width, int x, int y){
	if(x>=0 && x < width && y>=0 && length(matrix) > (y*width+x))
		return true;
	return false;
}

int dirChangeX(int x, int a){
	switch (a){
		case 0:
		case 4: return x;
		case 1:
		case 2:
		case 3: return x+1;
		case 5:
		case 6:
		case 7: return x-1;
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
