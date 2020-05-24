#include "Service.h"

Service::Service()
{

}

Service::Service(Repo_Users repo_u, Repo* repoa, Repo* repof, string option)
{
	this->repo_u = repo_u;
	this->repoa = repoa;
	this->repof = repof;
	this->option = option;
}

Service::~Service()
{

}

void Service::add_artist(string name_artist, string date, string place, int number_free, int number_sold)
{
	Artists* a = new Artists(name_artist, date, place, number_free, number_sold);
	this->repoa->add(a);
	delete a;
}

void Service::update_artist(int pos, string name_artist, string date, string place, int number_free, int number_sold)
{
	Artists* na = new Artists(name_artist, date, place, number_free, number_sold);
	Artists* o = (Artists*)this->repoa->get_all()[pos - 1];
	Artists* oa = new Artists(o->get_name_artist(), o->get_date(), o->get_place(), o->get_number_free(), o->get_number_sold());
	this->repoa->update(oa, na);
	delete oa;
	delete o;
	delete na;
}

void Service::delete_artist(int pos)
{
	Artists* a = (Artists*)this->repoa->get_all()[pos - 1];
	this->repoa->del(a);
}

vector<Festival*> Service::show_artists()
{
	return this->repoa->get_all();
}

void Service::add_film(string name_film, string list_actors, string date, string place, int number_free, int number_sold)
{
	Films* f = new Films(name_film, list_actors, date, place, number_free, number_sold);
	this->repof->add(f);
	delete f;
}

void Service::update_film(int pos, string name_film, string list_actors, string date, string place, int number_free, int number_sold)
{
	Films* nf = new Films(name_film, list_actors, date, place, number_free, number_sold);
	Films* o = (Films*)this->repof->get_all()[pos - 1];
	Films* of = new Films(o->get_name_film(), o->get_list_actors(), o->get_date(), o->get_place(), o->get_number_free(), o->get_number_sold());
	this->repof->update(of, nf);
	delete of;
	delete o;
	delete nf;
}

void Service::delete_film(int pos)
{
	Films* f = (Films*)this->repof->get_all()[pos - 1];
	this->repof->del(f);
}

vector<Festival*> Service::show_films()
{
	return repof->get_all();
}

void Service::add_user(string username, string password)
{
	Users u(username, password);
	this->repo_u.add(u);
}

void Service::update_user(int pos, string username, string password)
{
	if (pos == -1 || pos == 0)
	{
		throw MyException("POSITION OUT OF RANGE");
	}
	else
	{
		vector<Users> users = this->repo_u.get_all();
		Users new_user(username, password);
		for (int i = 0; i < users.size(); i++)
		{
			if (i == pos - 1)
			{
				Users old_user(users[i].get_username(), users[i].get_password());
				this->repo_u.update(old_user, new_user);
				return;
			}
		}
	}
}

void Service::delete_user(int pos)
{
	if (pos == -1 || pos == 0)
	{
		throw MyException("POSITION OUT OF RANGE");
	}
	else
	{
		vector<Users> users = this->repo_u.get_all();
		for (int i = 0; i < users.size(); i++)
		{
			if (i == pos - 1)
			{
				Users user_to_delete(users[i].get_username(), users[i].get_password());
				this->repo_u.del(user_to_delete);
				return;
			}
		}
	}
}

vector<Users> Service::show_users()
{
	return this->repo_u.get_all();
}

Artists* Service::get_ar(int pos)
{
	Artists* ar = (Artists*)this->repoa->get_all()[pos - 1];
	return ar;
}

Films* Service::get_fi(int pos)
{
	Films* fi = (Films*)this->repof->get_all()[pos - 1];
	return fi;
}

int Service::verify_username(string username)
{
	vector<Users> users = this->repo_u.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_username() == username)
			return 1;
	}
	throw MyException("INEXISTENT USERNAME");
}

int Service::verify_password(string password)
{
	vector<Users> users = this->repo_u.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_password() == password)
			return 1;
	}
	throw MyException("INEXISTENT PASSWORD");
}

int Service::login(string username, string password)
{
	if (this->verify_username(username) == 0)
		throw MyException("INEXISTENT USERNAME");
	if (this->verify_password(password) == 0)
		throw MyException("INEXISTENT PASSWORD");
	vector<Users> users = this->repo_u.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_username() == username && users[i].get_password() == password)
			return 1;
	}
	throw MyException("INEXISTENT USER");
}

void Service::buy_ticket_artist(int pos, int number)
{
	Artists* old = (Artists*)this->repoa->get_all()[pos - 1];
	Artists* old_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
	Artists* new_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free() - number, old->get_number_sold() + number);
	this->repoa->update(old_artist, new_artist);
}

void Service::buy_ticket_film(int pos, int number)
{
	Films* old = (Films*)this->repof->get_all()[pos - 1];
	Films* old_film = new Films(old->get_name_film(), old->get_list_actors(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
	Films* new_film = new Films(old->get_name_film(), old->get_list_actors(), old->get_date(), old->get_place(), old->get_number_free() - number, old->get_number_sold() + number);
	this->repof->update(old_film, new_film);
}

vector<Festival*> Service::show_day_artists(int day)
{
	vector <Festival*> a = show_artists();
	vector <Festival*> a1;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->get_date().substr(0, 2) == to_string(day))
			a1.push_back(a[i]);
	}
	return a1;
}

vector<Festival*> Service::show_day_films(int day)
{
	vector <Festival*> a = show_films();
	vector <Festival*> a1;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->get_date().substr(0, 2) == to_string(day))
			a1.push_back(a[i]);
	}
	return a1;
}