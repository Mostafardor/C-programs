/*
 * asteriskTriangle.cpp
 * 
 * @author: Josep Juda RV 
 * @date: idk
 * 
 * Copyright 2022 W10 <W10@DESKTOP-T3EABRP>
 * .
 * Output:
 * 
 * spaces and asterisks 
 * ----* 
 * ---***
 * --*****
 * -*******
 * *********
 * *********
 *--*******
 *---*****
 *----***
 *-----*
 * 
 * Note: when you don't close the instructions with brackets in a for or whike the 
 * instrution section is executed till fing another control instruccion, or in the same 
 * indentation. 
 * 
 * 
 */


#include <iostream>

using namespace std;

int main(int argc, char **argv){
	
	int i, j, n;
	
	cout << " Number of stairs : " ;
	cin >> n;
	cout << endl;
	
	
	// this is the spaces in each stair
	int stspc = n; 
	
	for (i = 0; i < n+1; i++){
	cout << " "; // a space to separate a bit
		for (j = 0; j < stspc ; j++)
		cout << " " ;
		// the spaces decrement 
		stspc--;
		for (j = 0; j < 2*i -1 ; j++)
		cout << "*" ;
	
	cout << endl;
	}
	
	
	stspc = 0;
	for (i = n; i > 0; i--){
	cout << " "; // a space to separate a bit
		for (j = 0; j < stspc ; j++)
		cout << " " ;
		// the spaces decrement 
		stspc++;
		for (j = 0; j < 2*i -1 ; j++)
		cout << "*" ;
	
	cout << endl;
	}
	
	return 0;
}

