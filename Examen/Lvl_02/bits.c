#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)



//OPERADORES CONDICIONALES
&&  <--- AND LOGICO  1 y 1 -> 1
||  <--- OR LOGICO   1 0 o 0 1 o 1 1 - > 1

//OPERADORES BINARIOS
&  <--- AND BINARIO
|  <--- OR BINARIO

//AND BINARIO COMO FUNCIONA?

char c = 'z'
(a nivel de bits)
c = 10010010

char a = 'b'
b= 01011000

//Acemos un and binario entre c y a
c = c & a

c = 10010010
b = 01011000
____________
c = 00010000 	

//Acemos un or binario

c = c | b

c = 00010000
b = 01011000
____________
	01011000


//MAS OPERADORES BINARIOS QUE ESTIMARAS
(no estci segur si sescriu dobles o simples)
<<  <--- Desplazamiento bits a la izquierda
>>  <--- Desplazmiento bits a la derecha

int n = 1;

(a nivel binario)
n = 00000001

n = n << 1;

n = 0000010

n = n << 2;
n =  00010000

n = n >> 6
n = 01000000

//Uso de maskaras para leer X columna de un numero en bits
//Para leer usar maskaras con un solo 1 , y operador AND
c = 010100001
int mask;
mask = 1;

mask = 00000001
(tambien serian validas maskaras como , 1, 2, 4, 8, 16, 32, 64,  128, 
 pero a efectas practics nomes utilitzarem el 1 o el 128)

	1 = 00000001
	2 = 00000010
	4 = 00000100
	8=  00001000
   16 = 00010000
   32=  00100000
   64=  01000000
   128= 10000000

 (vui llegir el bitt mes a la dreta de C)
 c    = 010100001
 mask = 000000001

 if( c & mask != 0)
	ultim bit es 1
 else
 	ultim bit es 0

 c  = 010100001
 mask=000000001
 ______________
      000000001   <--- no dona zero el ultim bit de c es 1

 ara vui legir el penultim de C

 if(c & (mask << 1) != 0)
	el penultim bit de c es un 1
 else
    el penultim es un zero



EL maravellos mon decreaar una variable bit a bit
(tambe utilitzarem "maskaras" pero utilitzarem el OR binari (operacio inversa)

Per operacions de reconstruccio tinc que partir d una variable que tot 
siguin 0

char result = '\0'  <--- TOT ZEROS, el caracter '0' no es tot zeros

result = 00000000

imaginem que la cago y utilitzo el '0' en lloc del '\0'

'0' a nivel bit val 48 (igual que el caracter ASCII
result = 00110000

TORNEM
result  = '\0'
result = 00000000

vui posar un 1 a la primera posicio de 0
mask = 128
mask = 10000000

result = result | mask

result = 00000000
mask  =  10000000
        _________
		 10000000

ara vui color un 1 al segon bit de result

result = result | (mask > 1);

result = 10000000
mask   = 01000000   (ja desplasada)
         ________
		 11000000

ara vui colocar un 0 a la tercera posicio
Que faig?
Por no faig res y donc una volta al while per na a coocar el cuart bit


