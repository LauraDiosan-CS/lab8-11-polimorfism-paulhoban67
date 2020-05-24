#include "Films.h"

Films::Films() : Festival()
{

}

Films::Films(string name_film, string list_actors, string date, string place, int number_free, int number_sold) : Festival(date, place, number_free, number_sold)
{
	this->name_film = name_film;
	this->list_actors = list_actors;
}

Films::Films(const Films& f) : Festival(f)
{
	this->name_film = f.name_film;
	this->list_actors = f.list_actors;
}

Films::~Films()
{

}

Festival* Films::clone()
{
	return new Films(this->name_film, this->list_actors, this->date, this->place, this->number_free, this->number_sold);
}

string Films::get_name_film()
{
	return this->name_film;
}

string Films::get_list_actors()
{
	return this->list_actors;
}

void Films::set_name_film(string new_name_film)
{
	this->name_film = new_name_film;
}

void Films::set_list_actors(string new_list_actors)
{
	this->list_actors = new_list_actors;
}

Films& Films::operator=(const Films& f)
{
	this->name_film = f.name_film;
	this->list_actors = f.list_actors;
	Festival::operator=(f);
	return *this;
}

bool Films::operator==(const Films& f)
{
	return 	this->name_film == f.name_film && this->list_actors == f.list_actors && Festival::operator==(f);

}

bool Films::operator!=(const Films& f)
{
	return 	this->name_film != f.name_film && this->list_actors != f.list_actors && Festival::operator!=(f);
}

string Films::to_string_festival(string delimitator)
{
	return "FI" + delimitator + this->name_film + delimitator + this->list_actors + delimitator + Festival::to_string_festival(delimitator);
}