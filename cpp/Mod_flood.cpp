#pragma once

String flood(String s, int width, int x, int y){
	List<Char> str = s2lc(s);
	int pos = width*y+x;
	Char color = get(str, pos);
	Char newColor;
	if(color == 'b')
		newColor = 'w';
	else 
		newColor = 'b';
	
	str = set(str, pos, newColor);
	
    //left neighbor
	if(x != 0){
		int newX = x-1;
		int newPos = width*y+newX;
		if(get(str, newPos) != newColor){
			str = s2lc(flood(lc2s(str), width, newX, y));
		}
	}
	
    //bottom neighbor
	if(y != 0){
		int newY = y-1;
		int newPos = width*newY+x;
		if(get(str, newPos) != newColor){
			str = s2lc(flood(lc2s(str), width, x, newY));
		}
	}
	
    //right neighbor
	if(x != (width-1)){
		int newX = x+1;
		int newPos = width*y+newX;
		if(get(str, newPos) != newColor){
			str = s2lc(flood(lc2s(str), width, newX, y));
		}
	}
	
    //top neighbor
	if(y != sp_div(length(str), width)-1) {
		int newY = y+1;
		int newPos = width*newY+x;
		if(get(str, newPos) != newColor){
			str = s2lc(flood(lc2s(str), width, x, newY));
		}
	}
	
	return lc2s(str);
}
