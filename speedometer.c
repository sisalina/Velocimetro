///////////////////////////////////////////////// definir leds para la decena
void cero(){         // si aca todos fueran cero se escribe un cero
   PORTD.B6=1;       // si aca todos son uno se escribe cero
   PORTB.B2=1;       // es interesante que sea cual sea el caso
   PORTB.B1=1;       // se entiende
   PORTB.B0=1;
}
void uno(){
   PORTD.B6=1;
   PORTB.B2=0;
   PORTB.B1=0;
   PORTB.B0=0;
}
void dos(){
   PORTD.B6=0;
   PORTB.B2=1;
   PORTB.B1=0;
   PORTB.B0=0;
}
void tres(){
   PORTD.B6=1;
   PORTB.B2=1;
   PORTB.B1=0;
   PORTB.B0=0;
}
void cuatro(){
   PORTD.B6=0;
   PORTB.B2=0;
   PORTB.B1=1;
   PORTB.B0=0;
}
void cinco(){
   PORTD.B6=1;
   PORTB.B2=0;
   PORTB.B1=1;
   PORTB.B0=0;
}
void seis(){
   PORTD.B6=0;
   PORTB.B2=1;
   PORTB.B1=1;
   PORTB.B0=0;
}
void siete(){
   PORTD.B6=1;
   PORTB.B2=1;
   PORTB.B1=1;
   PORTB.B0=0;
}
void ocho(){
   PORTD.B6=0;
   PORTB.B2=0;
   PORTB.B1=0;
   PORTB.B0=1;
}

void nueve(){
   PORTD.B6=1;
   PORTB.B2=0;
   PORTB.B1=0;
   PORTB.B0=1;
}
//////////////////////////////////////// definir LED´s para la unidad
void cero_u(){
   PORTA.B0=0;
   PORTD.B4=0;
   PORTD.B3=0;
   PORTD.B2=0;
}
void uno_u(){
   PORTA.B0=1;
   PORTD.B4=0;
   PORTD.B3=0;
   PORTD.B2=0;
}
void dos_u(){
   PORTA.B0=0;
   PORTD.B4=1;
   PORTD.B3=0;
   PORTD.B2=0;
}
void tres_u(){
   PORTA.B0=1;
   PORTD.B4=1;
   PORTD.B3=0;
   PORTD.B2=0;
}
void cuatro_u(){
   PORTA.B0=0;
   PORTD.B4=0;
   PORTD.B3=1;
   PORTD.B2=0;
}
void cinco_u(){
   PORTA.B0=1;
   PORTD.B4=0;
   PORTD.B3=1;
   PORTD.B2=0;
}
void seis_u(){
   PORTA.B0=0;
   PORTD.B4=1;
   PORTD.B3=1;
   PORTD.B2=0;
}
void siete_u(){
   PORTA.B0=1;
   PORTD.B4=1;
   PORTD.B3=1;
   PORTD.B2=0;
}
void ocho_u(){
   PORTA.B0=0;
   PORTD.B4=0;
   PORTD.B3=0;
   PORTD.B2=1;
}

void nueve_u(){
   PORTA.B0=1;
   PORTD.B4=0;
   PORTD.B3=0;
   PORTD.B2=1;
}

void ubica_decena(int velocidad){
 if(velocidad>=0  && velocidad <10){
 cero();
 }
 if(velocidad>=10 && velocidad <20){
 uno();
 }
 if(velocidad>=20 && velocidad <30){
 dos();
 }
 if(velocidad>=30 && velocidad <40){
 tres();
 }
 if(velocidad>=40 && velocidad <50){
 cuatro();
 }
 if(velocidad>=50 && velocidad <60){
 cinco();
 }
 if(velocidad>=60 && velocidad <70){
 seis();
 }
 if(velocidad>=70 && velocidad <80){
 siete();
 }
 if(velocidad>=80 && velocidad <90){
 ocho();
 }
 if(velocidad>=90 && velocidad <100){
 nueve();
 }
}


void ubica_unidad(int velocidad){
 int decena=0;
 int unidad=0;
 decena = velocidad/10;
 unidad=velocidad-decena*10;

 if(unidad>=0  && unidad<1){
 cero_u();
 }
 if(unidad>=1  && unidad<2){
 uno_u();
 }
 if(unidad>=2  && unidad<3){
 dos_u();
 }
 if(unidad>=3  && unidad<4){
 tres_u();
 }
 if(unidad>=4  && unidad<5){
 cuatro_u();
 }
 if(unidad>=5  && unidad<6){
 cinco_u();
 }
 if(unidad>=6  && unidad<7){
 seis_u();
 }
 if(unidad>=7  && unidad<8){
 siete_u();
 }
 if(unidad>=8  && unidad<9){
 ocho_u();
 }
 if(unidad>=9  && unidad<10){
 nueve_u();
 }
}


////////////////////////////////////////////////////////////////////////////////

void main() {

  int contador = 0;
  int velocidad = 0;
  int cuenta=0;
  int status;
  
  DDRA.B0 = 1;
  DDRB.B0 = 1;
  DDRB.B1 = 1;
  DDRB.B2 = 1;
  DDRB.B3 = 0;
  DDRD.B2 = 1;
  DDRD.B3 = 1;
  DDRD.B4 = 1;
  DDRD.B6=  1;

  while (1) {

status=PINB.B3;

           if( status==1 ){
                       delay_us(100);
                       contador++;
                       }
           else{
                    velocidad = 45216/contador;     // 45216 = 2*3.14*20*360
                    ubica_decena(velocidad);
                    ubica_unidad(velocidad);
                    contador=0;
                       }
  }

}