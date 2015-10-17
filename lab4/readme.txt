/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt): 3

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
 *
 **********************************************************************/

      N       brute       sortering
 ----------------------------------
    150       42ms        21ms
    200       95ms        41ms
    300       308ms       73ms
    400       741ms       127ms
    800       5796ms      507ms
   1600       46516ms     2104ms
   3200                   8978ms
   6400                   38336ms
  12800                   160690ms


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute:      O(n^4)

Sortering:  O
