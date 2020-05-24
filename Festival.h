#ifndef FESTIVAL_H
#define FESTIVAL_H

#include <iostream>
#include <string>
using namespace std;

class Festival
{
protected:
	string date;
	string place;
	int number_free;
	int number_sold;
public:
	Festival();
	Festival(string date, string place, int number_free, int number_sold);
	Festival(const Festival& f);
	~Festival();

	virtual Festival* clone();

	virtual string get_date();
	virtual string get_place();
	virtual int get_number_free();
	virtual int get_number_sold();

	void set_date(string new_date);
	void set_place(string new_place);
	void set_number_free(int new_number_free);
	void set_number_sold(int new_number_sold);

	Festival& operator=(const Festival& f);
	bool operator==(const Festival& f);
	bool operator!=(const Festival& f);
	virtual string to_string_festival(string delimitator);
};
#endif // !FESTIVAL_H