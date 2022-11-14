/*
 * sumaRecursiva.c
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

int sumaGauss(int n){
	if(n == 1){
		return 1;
	} else {
		printf(" %i ",n);
		return n + sumaGauss(n-1);
	}
}

int fibo(int n){
	if( !n || n==1){
		return n;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}

int digitos(int n){
	if(n < 0){
		return -1;
	}
	if(n < 10){
		putchar(n%10 + '0');
	} else {
		digitos(n/10);
		putchar(n%10 + '0');
	}
	return 0;
}


int main(int argc, char **argv)
{
	
	printf("\n S(%i) = %i \n",10,sumaGauss(5));
	printf("\n Fib(%i) = %i \n",10,fibo(5));
	printf("\n Dig(%i) = %i \n",4321,digitos(4321));
	
	return 0;
}

