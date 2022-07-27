/* date.h
   osk-2010
   Grundzuege einer einfache Klasse für Datumsangaben 
 */
#ifndef L5_DATE_H
#define L5_DATE_H

#include <iostream>
#include <string>
using std::ostream;

class Date 
{
  public:
    class Invalid { }; // zeigt Ausnahmen an
    enum Month { Jan=1, Feb, Mrz, Apr, Mai, Jun, Jul, Aug, Sep, Okt, Nov, Dez }; // symbol. Konstanten für die Monate
    Date(); // Standardkonstruktor
    Date( int year, Month month, int day ); // Konstruktor
    // nur lesender Zugriff (const):
    int year() const;
    Month month() const;
    int day() const;
    int compare_to( const Date& ) const; 
    // auch schreibender Zugriff:
    void change_days( const int& );
    std::string month_string() const;


    
  private:
    int    y; // Jahr
    Month  m; // Monat
    int    d; // Tag
    bool   check() const; // private Methode, liefert true bei gueltigem Datum
    void incDay();
    void decDay();
    
};
bool isSchaltjahr(int);
ostream& operator<<( ostream&, const Date& ); // Stream Insertion Operator << ueberladen
Date::Month& operator++( Date::Month& );
Date::Month& operator--(Date::Month&);     // Praefix Dekrement Operator -- fuer Monate ueberladen
Date& operator++(Date&);
Date& operator--(Date&);



#endif // L5_DATE_H
