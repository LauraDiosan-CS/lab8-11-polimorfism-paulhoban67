#ifndef SERVICE_USERS_H
#define SERVICE_USERS_H

#include "Repo_Users.h"
#include "Users.h"
using namespace std;

class Service_Users
{
private:
	Repo_Users repo_users;
public:
	Service_Users();
	Service_Users(Repo_Users& repo_users);
	Service_Users(const Service_Users& s);
	~Service_Users();

	void add_user(string username, string password);
	vector<Users> show_users();
	void update_user(int pos, string username, string password);
	void delete_user(int pos);

	int verify_username(string username);
	int verify_user(string password);
};
#endif // !SERVICE_USERS_H