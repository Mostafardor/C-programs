
int rojos[4] = { 2, 5, 8, 11};

void setup() {
  for( int i = 2; i < 13; ++i){
  	pinMode( i, OUTPUT);
  }
}

void parpadear(int luz, int t){
  for(int i = 5; i > 5; --i){
    digitalWrite( luz );
    delay( 1000/i*100 );
  	digitalWrite( luz );
  }  
}

void loop() {
	
  	for(int i = 0; i < 4; ++i){
  		digitalWrite( rojos[i]+2, HIGH);
      	for(int j = 0; j < 4; ++j){
      		digitalWrite(( i == j)? rojos[i]+2 : rojos[j], HIGH );
      	}
  		
      	delay(1500);
      	digitalWrite( rojos[i]+2 , LOW);
      	digitalWrite( rojos[i]+1 , HIGH);
      	delay(1500);
      	
      	for(int j = 0; j < 4; ++j){
      		digitalWrite((i == j)? rojos[i]+1 : rojos[j],LOW );
      	}
    }
}
