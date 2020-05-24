#include "Service_Artists.h"
#include "Exceptions.h"
#include <string.h>

Service_Artists::Service_Artists()
{

}

Service_Artists::Service_Artists(Repo& repo_txt, Repo& repo_csv)
{
	this->repo_txt = &repo_txt;
	this->repo_csv = &repo_csv;
}

Service_Artists::Service_Artists(const Service_Artists& s)
{
	this->repo_txt = s.repo_txt;
	this->repo_csv = s.repo_csv;
}

Service_Artists::~Service_Artists()
{

}

void Service_Artists::add_artists_txt(string name_artist, string date, string place, int number_free, int number_sold)
{
	if (date[2] != date[5])
		throw MyException("FORMAT DATE: dd/mm/yy");
	else
	{
		Artists* new_ar = new Artists(name_artist, date, place, number_free, number_sold);
		repo_txt->add(new_ar);
	}
}

vector<Festival*> Service_Artists::show_txt()
{
	return this->repo_txt->get_all();
}

void Service_Artists::update_artists_txt(int pos, string new_name_artist, string new_date, string new_place, int new_number_free, int new_number_sold)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* new_artist = new Artists(new_name_artist, new_date, new_place, new_number_free, new_number_sold);
		Artists* old = (Artists*)this->repo_txt->get_all()[pos - 1];
		Artists* old_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
		this->repo_txt->update(old_artist, new_artist);
	}
}

void Service_Artists::delete_artists_txt(int pos)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* artist = (Artists*)this->repo_txt->get_all()[pos - 1];
		this->repo_txt->del(artist);
	}
}

void Service_Artists::add_artists_csv(string name_artist, string date, string place, int number_free, int number_sold)
{
	if (date[2] != date[5])
		throw MyException("FORMAT DATE: dd/mm/yy");
	else
	{
		Artists* new_ar = new Artists(name_artist, date, place, number_free, number_sold);
		repo_csv->add(new_ar);
	}
}

vector<Festival*> Service_Artists::show_csv()
{
	return this->repo_csv->get_all();
}

void Service_Artists::update_artists_csv(int pos, string new_name_artist, string new_date, string new_place, int new_number_free, int new_number_sold)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* new_artist = new Artists(new_name_artist, new_date, new_place, new_number_free, new_number_sold);
		Artists* old = (Artists*)this->repo_txt->get_all()[pos - 1];
		Artists* old_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
		this->repo_csv->update(old_artist, new_artist);
	}
}

void Service_Artists::delete_artists_csv(int pos)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* artist = (Artists*)this->repo_txt->get_all()[pos - 1];
		this->repo_csv->del(artist);
	}
}

Artists* Service_Artists::get_artist_txt(int pos)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* ar = (Artists*)this->repo_txt->get_all()[pos - 1];
		return ar;
	}
}

Artists* Service_Artists::get_artist_csv(int pos)
{
	if (pos == -1 || pos == 0)
		throw MyException("POSITION OUT OF RANGE");
	else
	{
		Artists* ar = (Artists*)this->repo_csv->get_all()[pos - 1];
		return ar;
	}
}

void Service_Artists::buy(int pos, int number)
{
	Artists* old = (Artists*)this->repo_txt->get_all()[pos - 1];
	Artists* old_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free(), old->get_number_sold());
	Artists* new_artist = new Artists(old->get_name_artist(), old->get_date(), old->get_place(), old->get_number_free() - number, old->get_number_sold() + number);
	this->repo_txt->update(old_artist, new_artist);
}

vector<Festival*> Service_Artists::show_day(int day)
{
	vector <Festival*> a = show_txt();
	vector <Festival*> a1;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->get_date().substr(0, 2) == to_string(day))
			a1.push_back(a[i]);
	}
	return a1;
}
