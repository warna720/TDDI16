/**********************************************************************
 *  Kn�cka l�senord readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt): ~8 timmar.

/**********************************************************************
 *  Ge en h�gniv�beskrivning av ditt program decrypt.c.
 **********************************************************************/
Programmet b�rjar med att deklarera alla variabler som beh�vs.

Sedan har vi en variabel som skall indikera mitten av alla m�jliga l�senord
och beroende p� l�ngden av variabeln 'C' skall bokstaven 'b' s�ttas in p� antingen
('C' / 2) eller ('C' / 2 - 1).

Sedan l�ser vi in tabellen till variabeln 'T' (som vanligt, inga �ndringar gjorda h�r).

D�refter samlar vi resultaten (krypterade l�senordet - utr�knade subset-sum av l�senordskandidaten)
i symboltabellen.

Till slut testar vi andra h�lften (resten) av alla m�jliga l�senord och kollar ifall
den utr�knade subset-sum hittas i symboltabellen och d� printar vi ut alla m�jliga
l�senord fr�n vektorn, d� dessa �r alla m�jliga l�senord.

/**********************************************************************
 *  Beskriv symboltabellen du anv�nt f�r decrypt.c.
 **********************************************************************/
Strukturen p� v�r symboltabell �r en map d�r 'Key' �r v�rdet p� det krypterade
l�senordet minus subset-sum och value �r en vektor med alla m�jliga l�senord (i klartext).

Value �r en vektor eftersom att flera olika m�jliga l�senord kan mappa mot
samma key och d� f�ngar vi alla hash-collisions.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla l�senord med 8 och 10
 *  bokst�ver i uppgiften du lyckades kn�ca med DIN kod.
 **********************************************************************/


8 bokst�ver         10 bokst�ver
-----------         ------------
congrats            completely
youfound            unbreakabl
theright            cryptogram
solution            ormaybenot

/****************************************************************************
 *  Hur l�ng tid anv�nder brute.c f�r att kn�cka l�senord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ***************************************************************************/


Char     Brute
--------------
 4       ~1s*       //utmatning: 0s.
 5       25s
 6       1131s
 8       1131+s*    //tar v�ldigt l�ng tid.


/******************************************************************************
 *  Hur l�ng tid anv�nder decrypt.c f�r att kn�cka l�senord av en viss storlek?
 *  Hur mycket minne anv�nder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6       ~1s*              2,293,760         //utmatning: 0s.
8       4s                75,497,472
10      226s              2,751,463,424
12      226s+*            3,000,000,000+*   //"Killed.", slut p� minne.

/*************************************************************************
 * Hur m�nga operationer anv�nder brute.c f�r ett N-bitars l�senord?
 * Hur m�nga operationer anv�nder din decrypt.c f�r ett N-bitars l�senord?
 * Anv�nd ordo-notation.
 *************************************************************************/
brute.cc:   O(N + 2^N)
decrypt.cc: O(N + 2^(N/2) + 2^(N/2) * (2^(N/2) + log 2^(N/2)))
