#include <iostream> //Ein-/Ausgaben auf der Konsole machen
#include <conio.h> //einzelne Zeichen einlesen und ausgeben
#include <string> //strings benutzen k�nnen
#include <windows.h> //Die Windows-Beep-Funktion nutzen

using namespace std;

bool Passwortabfrage(string); //Funktion, die Wahrheitswert zur�ckliefert

int main(void) {
    for (int i = 0; i <= 2; i++) { //max. 3 falsche Eingaben
        cout << "Passwort:";
        if (Passwortabfrage("hallo welt")) { /*Passwortabfrage-Funktion aufrufen
                                          und richtiges Passwort festlegen*/
            cout << "\nPasswort akzeptiert!";
            break; //Schleife beenden (weitere Eingaben nicht n�tig)
        }
        else {
            Beep(500, 50);
            Beep(300, 50);
            cout << "\nPasswort falsch!\n";
        }
    }
    cin.sync(); /*Sorgt also daf�r, dass cin.get() auch
                  nach Eingaben funktioniert!*/
    cin.get(); //Konsole offenhalten
}


bool Passwortabfrage(string richtigesPasswort) {

    char einZeichen; //letztes eingegebenes Zeichen
    string ganzesPasswort; //gesamte Eingabe
    einZeichen = getch(); //ein Zeichen einlesen

    while (einZeichen != 0x0D) { /*solange das eingegebene
                                     Zeichen nicht ENTER ist*/
        if (einZeichen != 0x08) {
            ganzesPasswort += einZeichen; /*eingegebenes Zeichen zur
                                          Gesamteingabe erg�nzen*/
            putch('*');

        }
        else if (einZeichen == 0x08 && ganzesPasswort.length() > 0) {
            /*wenn eingegebenes Zeichen
            die R�cktaste ist und vorher
            schon etwas eingegeben wurde*/
            ganzesPasswort.resize(ganzesPasswort.length() - 1); /*letztes Zeichen
                                                                l�schen*/
            putch(0x08); //0x08: sog. Steuerzeichen f�r R�cktaste (Backspace)
            putch(' ');
            putch(0x08);
        }
        einZeichen = getch(); //neues Zeichen einlesen (n�chste Eingabe)
    }

    if (ganzesPasswort == richtigesPasswort) {
        return true; //Passwort und Eingabe sind identisch
    }
    else {
        return false; //Passwort und Eingabe unterscheiden sich
    }
}
