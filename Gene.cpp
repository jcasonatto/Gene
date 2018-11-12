#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
 
int main (){
int n;
char c;
int risp,i,scelta;
 
do{
    srand(time(NULL));
    cout<<"\tGENEREATORE CHIAVI CASUALI \t "
        <<"\n\t\tMenu:"
        <<"\n 1-chiave alfanumerica con caratteri speciali"
        <<"\n 2-solo nuemeri"
        <<"\n 3-numeri e lettere maiuscole e minuscole"
        <<"\n 4-lettere minuscole"
        <<"\n 5-lettere maiuscole e minuscole (utile per chiavi di cifratura WPA e WEP)"
        <<"\n 0-esci\n_";
    cin>>scelta;
 
    switch (scelta){
 
    case 1:                             //chaive alfanumerica + caratteri speciali
        cout<<"\nlunghezza chiave:\n_";
        cin>>n;
        for (i=0;i<n;i++){
            c=33+rand() % 94;           //il codice ASCII è visto dal C codificato
                                                     //nella sua forma decimale
            cout<<c;                  /* tutti i caratteri che interessano
                                       * questa chiave sono tra il 33 e il 126
                                       * in pratica genero semplicemente dei
                                       * numeri interi che poi verranno
                                       * codificati assegnandoli a una
                                       * variabile di tipo ' char '*/
        }
        do{getchar();}while(!getchar());
        break;
 
    case 2:                             //chiave numerica
        cout<<"\nlunghezza chiave:\n_";
        cin>>n;
        cout<<"\n chiave:\n";
        for (i=0;i<n;i++){
            cout<<rand()%10;
        }
        do{getchar();}while(!getchar());
        break;
 
    case 3:;case 4:;case 5:               //gli altri tre casi raggruppati
        cout<<"\nlunghezza chiave:\n_";      /* in questi 3 casi la funzione rand genererà
                                              * molti più numeri di quelli che verranno utilizzati.*/
       /* Questo è quello che si definisce un programma non ottimizzato. */
        cin>>n;
        cout<<"\n chaive: \n";
        i=0;
        while (i<n){
               c=33+rand() % 93;
 if(scelta==3){                  //chiave alfanumerica
 if ((c>=48 && c<=57)||(c>=65 && c<=90) || (c>=97 && c<=122)){
//con questo 'if' si stampa a video solo se il numero generato è tra quelli che interessano il tipo di chiave
//in ASCII dal 48 al 57 rappresentano i numeri, dal 65 al 90 l'alfabeto maiuscolo e dal 97 al 122 le lettere in minuscolo
                    cout<<c;
                    i++;
                }
            }
            if (scelta==4){                   //solo lettere dell'alfabeto
                if (c>=97 && c<=122){
                    cout<<c;
                    i++;
                }
            }
            if (scelta==5){                   //lettere maiuscole e minuscole
                if ((c>=65 && c<=90) || (c>=97 && c<=122)){
                    cout<<c;
                    i++;
                }
            }
        }
        do{getchar();}while(!getchar());
        break;
    }
}while(scelta!=0);
return 0;
}
