#ifndef SERVICE_FILMS_H
#define SERVICE_FILMS_H

#include "Repo_Txt.h"
#include "Repo_Csv.h"
#include "Films.h"
#include "Festival.h"
using namespace std;

class Service_Films
{
private:
	Repo* repo_txt = new Repo_Txt();
	Repo* repo_csv = new Repo_Csv();
public:
	Service_Films();
	Service_Films(Repo& repo_txt, Repo& repo_csv);
	Service_Films(const Service_Films& s);
	~Service_Films();

	void add_film_txt(string name_film, string list_actors, string date, string place, int number_free, int number_sold);
	vector<Festival*> show_txt();
	void update_film_txt(int pos, string new_name_film, string new_list_actors, string new_date, string new_place, int new_number_free, int new_number_sold);
	void delete_film_txt(int pos);

	void add_film_csv(string name_film, string list_actors, string date, string place, int number_free, int number_sold);
	vector<Festival*> show_csv();
	void update_film_csv(int pos, string new_name_film, string new_list_actors, string new_date, string new_place, int new_number_free, int new_number_sold);
	void delete_film_csv(int pos);

	Films get_film_txt(int pos);
	Films get_film_csv(int pos);
};
#endif // !SERVICE_FILMS_H