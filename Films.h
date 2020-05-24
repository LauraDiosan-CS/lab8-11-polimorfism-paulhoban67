#ifndef FILMS_H
#define FILMS_H

#include <iostream>
#include <string>
#include "Festival.h"
using namespace std;

class Films : public Festival
{
private:
	string name_film;
	string list_actors;
public:
	Films();
	Films(string name_film, string list_actors, string date, string place, int number_free, int number_sold);
	Films(const Films& f);
	~Films();

	Festival* clone();

	string get_name_film();
	string get_list_actors();
	
	void set_name_film(string new_name_film);
	void set_list_actors(string new_list_actors);

	Films& operator=(const Films& f);
	bool operator==(const Films& f);
	bool operator!=(const Films& f);
	string to_string_festival(string delimitator);
};
#endif // !FILMS_H