#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include "Repo.h"
#include "Repo_Users.h"
#include "Repo_txt.h"
#include "Repo_csv.h"
#include "Festival.h"
#include "Artists.h"
#include "Films.h"
#include "Exceptions.h"
using namespace std;

class Service
{
protected:
	Repo_Users repo_u;
	Repo* repoa;
	Repo* repof;
	string option;
public:
	Service();
	Service(Repo_Users repo_u, Repo* repoa, Repo* repof, string option);
	~Service();

	void add_artist(string name_artist, string date, string place, int number_free, int number_sold);
	void update_artist(int pos, string name_artist, string date, string place, int number_free, int number_sold);
	void delete_artist(int pos);
	vector<Festival*> show_artists();

	void add_film(string name_film, string list_actors, string date, string place, int number_free, int number_sold);
	void update_film(int pos, string name_film, string list_actors, string date, string place, int number_free, int number_sold);
	void delete_film(int pos);
	vector<Festival*> show_films();

	void add_user(string username, string password);
	void update_user(int pos, string username, string password);
	void delete_user(int pos);
	vector<Users> show_users();

	Artists* get_ar(int pos);
	Films* get_fi(int pos);

	int verify_username(string username);
	int verify_password(string password);
	int login(string username, string password);
	void buy_ticket_artist(int pos, int number);
	void buy_ticket_film(int pos, int number);
	vector<Festival*> show_day_artists(int day);
	vector<Festival*> show_day_films(int day);

};

#endif // !SERVICE_H
