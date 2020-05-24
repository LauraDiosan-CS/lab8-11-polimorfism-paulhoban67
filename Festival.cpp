#include "Festival.h"

Festival::Festival()
{
	this->number_free = -1;
	this->number_sold = -1;
}

Festival::Festival(string date, string place, int number_free, int number_sold)
{
	this->date = date;
	this->place = place;
	this->number_free = number_free;
	this->number_sold = number_sold;
}

Festival::Festival(const Festival& f)
{
	this->date = f.date;
	this->place = f.place;
	this->number_free = f.number_free;
	this->number_sold = f.number_sold;
}

Festival::~Festival()
{

}

Festival* Festival::clone()
{
	return new Festival(this->date, this->place, this->number_free, this->number_sold);
}

string Festival::get_date()
{
	return this->date;
}

string Festival::get_place()
{
	return this->place;
}

int Festival::get_number_free()
{
	return this->number_free;
}

int Festival::get_number_sold()
{
	return this->number_sold;
}

void Festival::set_date(string new_date)
{
	this->date = new_date;
}

void Festival::set_place(string new_place)
{
	this->place = new_place;
}

void Festival::set_number_free(int new_number_free)
{
	this->number_free = new_number_free;
}

void Festival::set_number_sold(int new_number_sold)
{
	this->number_sold = new_number_sold;
}

Festival& Festival::operator=(const Festival& f)
{
	this->date = f.date;
	this->place = f.place;
	this->number_free = f.number_free;
	this->number_sold = f.number_sold;
	return *this;
}

bool Festival::operator==(const Festival& f)
{
	return this->date == f.date && this->place == f.place && this->number_free == f.number_free && this->number_sold == f.number_sold;
}

bool Festival::operator!=(const Festival& f)
{
	return this->date != f.date && this->place != f.place && this->number_free != f.number_free && this->number_sold != f.number_sold;
}

string Festival::to_string_festival(string delimitator)
{
	return this->date + delimitator + this->place + delimitator + to_string(this->number_free) + delimitator + to_string(this->number_sold);
}