/*
 * asteriskSnake.cpp
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


#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	int i, j;
	
	cout << " Stairs : ";
	cin >> n;
	
	
	
	for (i = 0; i < n+1; i++){
		cout << endl;
		cout <<"    ";
		if(i == 0 || i == n){
			for (j = 0; j < n; j++)
			cout << "*";
		} else {
			cout << "*";
			for (j = 0; j < n-2; j++)
				cout << " ";
			cout << "*";
		} 
		i++;
	}	
	
	return 0;
}



















