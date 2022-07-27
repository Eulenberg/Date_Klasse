/* date_main.cpp
   osk-2010, osk-2022
   Ausprobieren der Date Klasse.
 */
#include "date.h"
#include <exception> 
#include <iostream>


void run_test() {

	/*Date dTest1(2100, Date::Dez, -1);
	std::cout << dTest1 << std::endl;*/

	//Erwartung: negativ Resultat: negativ

	//---------------------------------------------------------
	/*Date dTest2(2022, Date::Dez, 10);
	std::
	cout << dTest2 << std::endl;*/

	//Erwartung: positiv Resultat: Positiv

	//---------------------------------------------------------


   /* Date dTest3(2100, Date::Feb, 29);
	std::cout << dTest3 << std::endl;*/

	//Erwartung: negativ Resulat:positv
	//Wurde als Schaltjahr erkannt auf Grund fehlerhater if abfrage in isSchaltjahr()  statt && ,|| benutzt
	//---------------------------------------------------------

   /* Date dTest4(2300, Date::Dez, 29);
	std::cout << dTest4 << std::endl;*/

	//Erwartung: negativ Resultat: negativ
	//---------------------------------------------------------

   /* Date dTest5(2022, Date::Dez, 30);
	std::cout << dTest5 << std::endl;
	dTest5.Date::change_days(12);
	std::cout << dTest5 << std::endl;*/

	//Erwartung: positiv Resultat: Negativ
	// Das Datum wurde nicht inkrementiert da in incDays d++ vergessen wurde
	//---------------------------------------------------------

   /* Date dTest6(2022, Date::Dez, 30);
	std::cout << dTest6 << std::endl;
	dTest6.Date::change_days(300);
	std::cout << dTest6 << std::endl;*/

	//Erwartung: positiv Resultat: Positiv
	//---------------------------------------------------------

	/*Date dTest7(2000, Date::Feb, 28);
	std::cout << dTest7 << std::endl;
	dTest7.Date::change_days(900);
	std::cout << dTest7<< std::endl;*/

	//Erwartung: positiv Resultat: Positiv
	//---------------------------------------------------------

	/*y*/

	//Erwartung: gleich Resultat: kleiner
	//Fehler in der namespace Auflösung der compare_to Methode
	//---------------------------------------------------------

	/*Date dTest8a(2000, Date::Feb, 28);
	Date dTest8b(2000, Date::Feb, 28);
	std::cout << dTest8a << std::endl;
	std::cout << dTest8a.compare_to(dTest8b) << std::endl;*/

	//Erwartung: gleich Resultat: gleich
	//---------------------------------------------------------

	/*Date dTest9a(2001, Date::Feb, 28);
	Date dTest9b(2000, Date::Feb, 28);
	std::cout << dTest9a << std::endl;
	std::cout << dTest9a.compare_to(dTest9b) << std::endl;*/

	//Erwartung: groesser Resultat: groesser
	//---------------------------------------------------------

    /*Date dTest10a(2000, Date::Feb, 28);
	Date dTest10b(2001, Date::Feb, 28);
	std::cout << dTest10a << std::endl;
	std::cout << dTest10a.compare_to(dTest10b) << std::endl;*/

	//Erwartung: kleiner Resultat: kleiner
	//---------------------------------------------------------

	/*Date dTest11(2000, Date::Feb, 28);
	std::cout << dTest11 << std::endl;
	dTest11.change_days(2);
	std::cout << dTest11 << std::endl;*/
	//Erwartung: 1.3.2000 Resultat: 2.3.2000
	//Die Methode decDay musste mit return vorzeitig aufhören damit bei monats wechsel das untenstehende d++ nicht ausgeführt wird
	//---------------------------------------------------------


	/*Date dTest12(2000, Date::Feb, 28);
	std::cout << dTest12 << std::endl;
	dTest12.change_days(-2);
	std::cout << dTest12 << std::endl;*/
	//Erwartung: 26.2.2000 Resultat: 26.2.2000 
	//---------------------------------------------------------

    /*Date dTest13(2000, Date::Feb, 28);
	std::cout << dTest13 << std::endl;
	++dTest13;
	std::cout << dTest13 << std::endl;*/
	//Erwartung: 29.2.2000 Resultat: 29.2.2000
	//---------------------------------------------------------

	/*Date dTest14(2000, Date::Feb, 28);
	std::cout << dTest14 << std::endl;
	++dTest14;
	++dTest14;
	++dTest14;
	std::cout << dTest14 << std::endl;*/
	//Erwartung: 2.3.2000 Resultat: 2.3.2000
	//---------------------------------------------------------

 /*   Date dTest15(2100, Date::Mrz, 1);
	std::cout << dTest15 << std::endl;
	--dTest15;
	std::cout << dTest15 << std::endl;*/
	//Erwartung: 29.2.2100 Resultat: 29.2.2100 
	//---------------------------------------------------------

	/*Date dTest16(2004, Date::Mrz, 1);
	std::cout << dTest16 << std::endl;
	--dTest16;
	--dTest16;
	--dTest16;
	std::cout << dTest16 << std::endl;*/
	//Erwartung: 27.2.2004 Resultat: 27.2.2004
	//---------------------------------------------------------

	/*Date dTest17(2004, Date::Mrz, 1);
	std::cout << dTest17 << std::endl;
	dTest17.change_days(0);
	std::cout << dTest17 << std::endl;*/
	//Erwartung: 1.3.2004 Resultat: 27.2.2004
	//---------------------------------------------------------

	/*Date dTest18(2000, Date::Dez, 31);
	std::cout << dTest18 << std::endl;
	++dTest18;
	std::cout << dTest18 << std::endl;*/

	//Erwartung: 1.1.2001 Resultat: 1.1.2001
	//---------------------------------------------------------

	/*Date dTest19(2000, Date::Jan, 1);
	std::cout << dTest19 << std::endl;
	--dTest19;
	std::cout << dTest19 << std::endl;*/

	//Erwartung: 31.12.1999 Resultat: 31.12.1999
	//---------------------------------------------------------

	/*Date dTest20(2004, Date::Feb, 28 );
	std::cout << dTest20 << std::endl;
	++dTest20;
	std::cout << dTest20 << std::endl;*/

	//Erwartung: 29.2.2004 Resultat: 29.2.2004


Date dTest21a(2000, Date::Mrz, 28);
Date dTest21b(2000, Date::Mrz, 28);
std::cout << dTest21a << std::endl;
std::cout << dTest21a.compare_to(dTest21b) << std::endl;

//Erwartung: -1 Resultat: 1
//Die if abfragen der methode  compare_to() waren nicht ausreichend
//---------------------------------------------------------





}


int main() try
{
	run_test();

	




	return 0;
}


catch (Date::Invalid&)
{
	std::cerr << "Ausnahme: Datum ungueltig";
	return -3;
}
catch (std::exception& e)
{
	std::cerr << "Ausnahme: " << e.what();
	return -2;
}
catch (...)
{
	std::cerr << "Unbekannte Ausnahme";
	return -1;
}


