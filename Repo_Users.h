#ifndef REPO_USERS_H
#define REPO_USERS_H

#include "Users.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Repo_Users
{
protected:
	vector<Users> users;
	string filename;
public:
	Repo_Users();
	Repo_Users(string filename);
	Repo_Users(const Repo_Users& u);
	~Repo_Users();
	Repo_Users& operator=(const Repo_Users& u);


	void set_filename(string new_filename);

	vector<Users>get_all();
	void add(Users users);
	void del(Users users);
	void update(Users old_users, Users new_users);

	int get_size();
	void clear();
	Users get_users(int pos);

	void load_to_file();
	void save_to_file();
};
#endif // !REPO_USERS_H