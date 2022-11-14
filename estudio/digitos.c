/*
 * digitos.c
 * 
 * Copyright 2022 W10 <W10@DESKTOP-T3EABRP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int digitos(int n){
	int i = 0;
	while( n >= 1 || n <= -1){
		n /=10;
		++i; 
	}
	return i;
}

int esPositivo(int n){
	return (n > 0)? 1 : 0;
}

void descomponer(int n, int lenNum, int i){
	if(!esPositivo(n)){
		n = -n;
		printf("-");
	}
	if( i++ == lenNum-2){
		printf(" 10^%i*%i",i,n%10);
	} else {
		printf(" 10^%i*%i +",i,n%10);
	}
	if(n <= 10 || n <= -10)
		return;
	else
		descomponer((n-n%10)/10, lenNum, i);
} 

int main(int argc, char **argv){
	
	int n = 2147483647;
	int m = -2147483647;
	
	
	int lenNum = digitos(n);
	
	int i = -1;
	
	
	printf("\n\n %i = ",n);
	descomponer(n, lenNum, i );
	
	
	printf("\n\n %i = ",m);
	descomponer(m, lenNum, i );
	
	// versión no recursiva 
	//for (i = 0; i < lenNum; i++){
		//if( i == lenNum-1){
			//printf(" 10^%i*%i",i,n%10);
		//} else {
			//printf(" 10^%i*%i +",i,n%10);
		//}
		//n = (n - n%10)/10;
	//}
	
	
	return 0;
}

