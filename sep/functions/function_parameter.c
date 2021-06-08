#include <stdio.h>

void say(char *msg);
void call_f(void (*f)(char*)); // funktion die pointer erhaelt um funktion aufzurufen

int main() {
    void (*out)(char*); // erzeuge funktionspointer "out" auf eine funktion:
                        // mit rueckgabewert: void
                        // mit parameter: char*

    out = &say; // hole adresse der funktion say()
    out = say;  // alternative version

    char msg[] = "Hello World";

    (*out)(msg); // aufrufen der funktion hinter pointer
    out(msg);    // alternative version
    call_f(out); // gebe referenz als parameter mit

    typedef void (*say_p)(char*);   // erzeuge typedef say_p fuer pointer auf funktion
                                    // mit rueckgabewert: void
                                    // mit parameter: char*

    say_p say_f = &say; // erzeuge pointer fuer typdefinition say_p
    say_f(msg);
}

void say(char *msg) {
    printf("%s\n", msg);
}

void call_f(void (*f)(char*)) {
    f("called from call_f");
}