#include <iostream>
#include <string>
#include "Test_Films.h"
#include "Test_Artists.h"
#include "Test_Festival.h"
#include "Test_Users.h"
#include "Test_Repo.h"
#include "Test_Service.h"
#include "Repo_csv.h"
#include "Repo_txt.h"
#include "Service_Artists.h"
#include "Service_films.h"
#include "Repo_Users.h"
#include "Service_Users.h"
#include "Exceptions.h"
#include "UI.h"

using namespace std;

int main()
{	
	try
	{
		Test_Artists ta;
		Test_Festival tf;
		Test_Films tfi;
		Test_Users tu;
		Test_Repo tre;
		Test_Service tse;
		ta.test_all();
		tf.test_all();
		tfi.test_all();
		//tre.test_all();
		tse.test_all();
		tu.test_all();

		Repo_Users repo_u("Users.txt");
		Repo* ra;
		Repo* rf;
		string o;
		cout << "TXT / CSV: ";
		cin >> o;
		if (o == "TXT")
			ra = new Repo_Txt("Artists.txt"), rf = new Repo_Txt("Films.txt");
		else
			if (o == "CSV")
				ra = new Repo_Csv("Artists.csv"), rf = new Repo_Csv("Films.csv");
			else
				throw MyException("TYPE FILE INCORECT");
		Service s(repo_u, ra, rf, o);
		UI ui(s);
		ui.run();
	}
	catch (MyException exc)
	{
		cout << "ERROR: " << exc.what() << endl;
		main();
	}
	
}