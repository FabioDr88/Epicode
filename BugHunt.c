#include <stdio.h>
//Il programma di permette di compiere delle attività come moltiplicazioni, divisioni e inserimento di stringhe
// Dichiarazione delle funzioni

void menu ();
void moltiplica ();
void dividi ();
void ins_string();
int ctr1, ctr2;


int main () 

{
	char scelta = '\0'; //  Errore: Le parentesi graffe
	menu();
	label: // Aggiunto per ricominciare l'attività
    
	scanf ("%c", &scelta); // Errore : Modificato da %d a c% perchè fa riferimento ad un carattere
  	
	switch (scelta)
	{
		case 'A':
				moltiplica();
				break;
		case 'B':
                dividi();
                break;
		case 'C':
                ins_string();
                break;
		default:	
		printf("Comando errato\n"); //  errore: aggiunta di un comando di controllo per fare in modo che venga selezionata la giusta risposta
		rewind(stdin);	// Aggiunta: questo permetterà al comando di tornane in fase iniziale
		goto label; //Aggiunto per tornare in cima
		break;
		  
	}
			
			

return 0;

}


void menu ()
{
	printf ("Benvenuto, sono un assitente digitale, posso aiutarti a sbrigare alcuni compiti\n");
	printf ("Come posso aiutarti?\n");
	printf ("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\n");

}


void moltiplica ()
{
	do{
	
	int a,b, prodotto; // Errore: in questa maniera le operazioni saranno più efficenti
	printf ("Inserisci i due numeri da moltiplicare:");
	ctr1 = scanf ("%d", &a); // 5° Errore: %f viene sostituito in %d
	ctr2 = scanf ("%d", &b);
	if(ctr1 == 0 || ctr2 == 0) {
		printf ("Solo numeri \n\n");
		rewind(stdin);	
		}
	else{						
		prodotto = a * b;
		printf ("Il prodotto tra %d e %d e': %d", a,b,prodotto);
		rewind(stdin);} // aggiunta: Ci permetterà di tornare allo stadio iniziale
 } while (ctr1 == 0 || ctr2 == 0);
}




void dividi ()
{
 	do{
	 
    float a,b = 0; 
    
    printf ("Inserisci il numeratore:");
    ctr1 = scanf ("%f", &a); // qui abbiamo corretto il fattore %d con il fattore %f
	printf ("Inserisci il denumeratore:");  
	ctr2 = scanf ("%f", &b);//qui anche la correzione di %d in %f
    	if(ctr1 == 0 || ctr2 == 0) {//BLocco per la la digitare correttamente un numero
		printf ("Solo numeri \n\n");
		rewind(stdin);	//ci permetterà di tornare in cima
		}
	else{
	float divisione = a / b;
    printf ("La divisione tra %0.1f e %0.1f e': %0.4f", a,b,divisione);
	rewind(stdin);
	 } }while (ctr1 == 0 || ctr2 == 0);
}


void ins_string () 
{
	char stringa[10];
        printf ("Inserisci la stringa:");
        fgets (stringa,10, stdin);
        printf("Hai inserito la seguenza stringa: %s",stringa); // qui è inserito il blocco dei caratteri
       rewind(stdin);
}
