/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt): ~8 timmar.

/**********************************************************************
 *  Ge en högnivåbeskrivning av ditt program decrypt.c.
 **********************************************************************/
Programmet börjar med att deklarera alla variabler som behövs.

Sedan har vi en variabel som skall indikera mitten av alla möjliga lösenord
och beroende på längden av variabeln 'C' skall bokstaven 'b' sättas in på antingen
('C' / 2) eller ('C' / 2 - 1).

Sedan läser vi in tabellen till variabeln 'T' (som vanligt, inga ändringar gjorda här).

Därefter samlar vi resultaten (krypterade lösenordet - uträknade subset-sum av lösenordskandidaten)
i symboltabellen.

Till slut testar vi andra hälften (resten) av alla möjliga lösenord och kollar ifall
den uträknade subset-sum hittas i symboltabellen och då printar vi ut alla möjliga
lösenord från vektorn, då dessa är alla möjliga lösenord.

/**********************************************************************
 *  Beskriv symboltabellen du använt för decrypt.c.
 **********************************************************************/
Strukturen på vår symboltabell är en map där 'Key' är värdet på det krypterade
lösenordet minus subset-sum och value är en vektor med alla möjliga lösenord (i klartext).

Value är en vektor eftersom att flera olika möjliga lösenord kan mappa mot
samma key och då fångar vi alla hash-collisions.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         10 bokstäver
-----------         ------------
congrats            completely
youfound            unbreakabl
theright            cryptogram
solution            ormaybenot

/****************************************************************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ***************************************************************************/


Char     Brute
--------------
 4       ~1s*       //utmatning: 0s.
 5       25s
 6       1131s
 8       1131+s*    //tar väldigt lång tid.


/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6       ~1s*              2,293,760         //utmatning: 0s.
8       4s                75,497,472
10      226s              2,751,463,424
12      226s+*            3,000,000,000+*   //"Killed.", slut på minne.

/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/
brute.cc:   O(N + 2^N)
decrypt.cc: O(N + 2^(N/2) + 2^(N/2) * (2^(N/2) + log 2^(N/2)))
