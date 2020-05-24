#ifndef ARTISTS_H
#define ARTISTS_H

#include <iostream>
#include <string>
#include "Festival.h"
using namespace std;

class Artists : public Festival
{
private:
	string name_artist;
public:
	Artists();
	Artists(string name_artist, string date, string place, int number_free, int number_sold);
	Artists(const Artists& a);
	~Artists();

	Festival* clone();

	string get_name_artist();

	void set_name_artist(string new_name_artist);

	Artists& operator=(const Artists& a);
	bool operator==(const Artists& a);
	bool operator!=(const Artists& a);
	string to_string_festival(string delimitator);
};
#endif // !ARTISTS_H