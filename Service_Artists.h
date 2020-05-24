#ifndef SERVICE_ARTISTS_H
#define SERVICE_ARTISTS_H

#include "Repo_Txt.h"
#include "Repo_Csv.h"
#include "Artists.h"
#include "Festival.h"
using namespace std;

class Service_Artists
{
private: 
	Repo* repo_txt = new Repo_Txt();
	Repo* repo_csv = new Repo_Csv();
public:
	Service_Artists();
	Service_Artists(Repo& repo_txt, Repo& repo_csv);
	Service_Artists(const Service_Artists& s);
	~Service_Artists();

	void add_artists_txt(string name_artist, string date, string place, int number_free, int number_sold);
	vector<Festival*> show_txt();
	void update_artists_txt(int pos, string new_name_artist, string new_date, string new_place, int new_number_free, int new_number_sold);
	void delete_artists_txt(int pos);

	void add_artists_csv(string name_artist, string date, string place, int number_free, int number_sold);
	vector<Festival*> show_csv();
	void update_artists_csv(int pos, string new_name_artist, string new_date, string new_place, int new_number_free, int new_number_sold);
	void delete_artists_csv(int pos);

	Artists* get_artist_txt(int pos);
	Artists* get_artist_csv(int pos);

	void buy(int pos, int number);
	vector<Festival*> show_day(int day);
};
#endif // !SERVICE_ARTISTS_H