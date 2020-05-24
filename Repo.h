#ifndef REPO_H
#define REPO_H

#include "Festival.h"
#include <iostream>
#include <vector>
using namespace std;

class Repo
{
protected:
	vector<Festival*>festivals;
	string file_name;
public:
	Repo();
	Repo(string file_name);
	~Repo();

	void set_file_name(string new_file_name);

	vector<Festival*>get_all();
	void add(Festival* festival);
	void del(Festival* festival);
	void update(Festival* old_festival, Festival* new_festival);

	int get_size();
	Festival* get_festival(int pos);

	virtual void load_to_file() = 0;
	virtual void save_to_file() = 0;
};
#endif // !REPO_H