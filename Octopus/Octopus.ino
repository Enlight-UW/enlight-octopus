/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);  
 
 
  float h = 0.24;
  float s = 0.84;
  float v = 0.51;
  float r;
  float g;
  float b;
  
  HSVtoRGB(&r, &g, &b, h, s, v);
  
  Serial.println(r);
  Serial.println(g);
  Serial.println(b);
  
  RGBtoHSV(r, g, b, &h, &s, &v);
  
  Serial.println(h);
  Serial.println(s);
  Serial.println(v);
 
  // TODO: initialize current states
  
  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
 

   stateUpdate(); 
}




// [8 bits of nothing][red 8][green 8][blue 8]
uint32_t ledCurrentStates[6] = {0, 0, 0, 0, 0, 0};
uint32_t ledGoalStates[6] = {0, 0, 0, 0, 0, 13120009};


void setGoalState(int id, int color) {  
    ledCurrentStates[id] = color;
}


int SPEED = 1;

void stateUpdate() {
  for (int i = 0; i < 6; i++) {
    uint32_t rc, gc, bc;
    uint32_t rg, gg, bg;
    
     // Read current value out
     rc = (ledCurrentStates[i] >> 16) & 255;
     gc = (ledCurrentStates[i] >> 8) & 255;
     bc = (ledCurrentStates[i] >> 0) & 255;
     
     Serial.print("Red Current: ");
      Serial.println(rc);
 
     Serial.print("Green Current: ");
      Serial.println(gc);
 
     Serial.print("Blue Current: ");
      Serial.println(bc);
 
     // Read goals
     rg = (ledGoalStates[i] >> 16) & 255;
     gg = (ledGoalStates[i] >> 8) & 255;
     bg = (ledGoalStates[i] >> 0) & 255;

    
     Serial.print("Red Goal: ");
      Serial.println(rg);
 
     Serial.print("Green Goal: ");
      Serial.println(gg);
 
     Serial.print("Blue Goal: ");
      Serial.println(bg);
      
     if (rc != rg)
       rc += ((rg > rc) ? SPEED : -SPEED);
     
     if (gc != gg)
       gc += ((gg > gc) ? SPEED : -SPEED);
     
     if (bc != bg)
       bc += ((bg > bc) ? SPEED : -SPEED);
     
     ledCurrentStates[i] = (rc << 16) | (gc << 8) | bc;
   }
}


// http://www.cs.rit.edu/~ncs/color/t_convert.html#RGB%20to%20HSV%20&%20HSV%20to%20RGB

void RGBtoHSV( float r, float g, float b, float *h, float *s, float *v ) {
	float vmin, vmax, delta;

	vmin = min(min( r, g), b );
	vmax = max(max(r, g), b );
	*v = vmax;				// v

	delta = vmax - vmin;

	if( vmax != 0 )
		*s = delta / vmax;		// s
	else {
		// r = g = b = 0		// s = 0, v is undefined
		*s = 0;
		*h = -1;
		return;
	}

	if( r == vmax )
		*h = ( g - b ) / delta;		// between yellow & magenta
	else if( g == vmax )
		*h = 2 + ( b - r ) / delta;	// between cyan & yellow
	else
		*h = 4 + ( r - g ) / delta;	// between magenta & cyan

	*h *= 60;				// degrees
	if( *h < 0 )
		*h += 360;

}

void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v )
{
	int i;
	float f, p, q, t;

	if( s == 0 ) {
		// achromatic (grey)
		*r = *g = *b = v;
		return;
	}

	h /= 60;			// sector 0 to 5
	i = floor( h );
	f = h - i;			// factorial part of h
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );

	switch( i ) {
		case 0:
			*r = v;
			*g = t;
			*b = p;
			break;
		case 1:
			*r = q;
			*g = v;
			*b = p;
			break;
		case 2:
			*r = p;
			*g = v;
			*b = t;
			break;
		case 3:
			*r = p;
			*g = q;
			*b = v;
			break;
		case 4:
			*r = t;
			*g = p;
			*b = v;
			break;
		default:		// case 5:
			*r = v;
			*g = p;
			*b = q;
			break;
	}
}

