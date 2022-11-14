/*
 * @author: Yo'ochel
 * @file guessNumbers.cpp
 * 
 * Copyright 2022 W10 <W10@DESKTOP-T3EABRP>
 * 
 * the mean of attempts finding a every number tends to 42. 
 * 
 * this programm take a random number between k and m and guess 
 * the number till get it.
 * 
 * 
 * 
 */


#include <iostream>
#include <time.h>


using namespace std;

const int times = 100;


int main(int argc, char **argv)
{
	
	srand(time(0));
	
	int mean = 0;
	int average[times];
	
	int g;
	int attempts = 0;
	
	int m = 100;
	int k = 0;
		
	int n = k + rand() % m;
	
	for (int i = 0; i < times; i++){
		
	//cout << "\n Guess the numbe, Computer \n" << endl;
		
	//cout << "\n let me give you a hint, the number is greater than "<<k<<" and lesser than "<< m<< endl;
	
	cout << "\n the secret number is [" << n <<"] "<< endl;
	
	
	do{
		
		g = k + rand() % (m-k) ;
		
		attempts++;
		
		//cout << "________________________________________" << endl;
		cout << "\n The number is " << g << endl;
		//cout << " ["<<k<<","<<m<<"]" << endl;
		//cout << " attempts " << attempts << endl;
		
		if(g == n){
			cout << "\n You're goddam right  "<< endl;
			break;
		} 
		
		if( g < n ){
			//cout << "\n hint: the number is greater than that "<< endl;
			//cout << "________________________________________" << endl;
			k = g;
		} else {
			//cout << "\n hint: the number is lesser than that "<< endl;		
			//cout << "________________________________________" << endl;
			m = g;
		} 
		
		
	}while ( g != n);
	
	average[i] = attempts;
	
	attempts = 0;
	
	m = 100;
	k = 0;
		
	n = k + rand() % m;
	
	cout << endl;
	//cout << " Congrats you did it, Computer " << endl;
	
	}
	
	for (int i = 0; i < times; i++){
		mean = mean + average[i]; 
	}
	mean = mean/times;
	
	cout << " The mean of attempts guessing the number is : " << mean << endl;
	
	return 0;
}

