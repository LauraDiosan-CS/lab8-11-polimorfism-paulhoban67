#include "Service_films.h"

Service_Films::Service_Films()
{

}

Service_Films::Service_Films(Repo& repo_txt, Repo& repo_csv)
{
	this->repo_txt = &repo_txt;
	this->repo_csv = &repo_csv;
}

Service_Films::Service_Films(const Service_Films& s)
{
	this->repo_txt = s.repo_txt;
	this->repo_csv = s.repo_csv;
}

Service_Films::~Service_Films()
{

}

void Service_Films::add_film_txt(string name_film, string list_actors, string date, string place, int number_free, int number_sold)
{
	Films* new_fi = new Films(name_film,list_actors, date, place, number_free, number_sold);
	repo_txt->add(new_fi);
}

vector<Festival*> Service_Films::show_txt()
{
	return this->repo_txt->get_all();
}

void Service_Films::update_film_txt(int pos, string new_name_film, string new_list_actors, string new_date, string new_place, int new_number_free, int new_number_sold)
{
	Films* new_film = new Films(new_name_film, new_list_actors, new_date, new_place, new_number_free, new_number_sold);
	Films* old = (Films*)this->repo_txt->get_all()[pos - 1];
	Films* old_film = new Films(old->get_name_film(), old->get_list_actors(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
	this->repo_txt->update(old_film, new_film);
}

void Service_Films::delete_film_txt(int pos)
{
	Films* film = (Films*)this->repo_txt->get_all()[pos - 1];
	this->repo_txt->del(film);
}

void Service_Films::add_film_csv(string name_film, string list_actors, string date, string place, int number_free, int number_sold)
{
	Films* new_fi = new Films(name_film, list_actors, date, place, number_free, number_sold);
	repo_csv->add(new_fi);
}

vector<Festival*> Service_Films::show_csv()
{
	return this->repo_csv->get_all();
}

void Service_Films::update_film_csv(int pos, string new_name_film, string new_list_actors, string new_date, string new_place, int new_number_free, int new_number_sold)
{
	Films* new_film = new Films(new_name_film, new_list_actors, new_date, new_place, new_number_free, new_number_sold);
	Films* old = (Films*)this->repo_txt->get_all()[pos - 1];
	Films* old_film = new Films(old->get_name_film(), old->get_list_actors(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
	this->repo_csv->update(old_film, new_film);
}

void Service_Films::delete_film_csv(int pos)
{
	Films* film = (Films*)this->repo_txt->get_all()[pos - 1];
	this->repo_csv->del(film);
}

Films Service_Films::get_film_txt(int pos)
{
	return Films();
}

Films Service_Films::get_film_csv(int pos)
{
	return Films();
}
