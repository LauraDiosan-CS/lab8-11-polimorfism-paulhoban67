#include "Service_Users.h"
#include "Exceptions.h"

Service_Users::Service_Users()
{

}

Service_Users::Service_Users(Repo_Users& repo_users)
{
	this->repo_users = repo_users;
}

Service_Users::Service_Users(const Service_Users& s)
{
	this->repo_users = s.repo_users;
}

Service_Users::~Service_Users()
{

}

void Service_Users::add_user(string username, string password)
{
	Users u(username, password);
	this->repo_users.add(u);
}

vector<Users> Service_Users::show_users()
{
	return this->repo_users.get_all();
}

void Service_Users::update_user(int pos, string username, string password)
{
	if (pos == -1 || pos == 0)
	{
		throw MyException("POSITION OUT OF RANGE");
	}
	else
	{
		vector<Users> users = this->repo_users.get_all();
		Users new_user(username, password);
		for (int i = 0; i < users.size(); i++)
		{
			if (i == pos - 1)
			{
				Users old_user(users[i].get_username(), users[i].get_password());
				this->repo_users.update(old_user, new_user);
				return;
			}
		}
	}
}

void Service_Users::delete_user(int pos)
{
	if (pos == -1||pos==0)
	{
		throw MyException("POSITION OUT OF RANGE");
	}
	else
	{
		vector<Users> users = this->repo_users.get_all();
		for (int i = 0; i < users.size(); i++)
		{
			if (i == pos - 1)
			{
				Users user_to_delete(users[i].get_username(), users[i].get_password());
				this->repo_users.del(user_to_delete);
				return;
			}
		}
	}
}

int Service_Users::verify_username(string username)
{
	vector<Users> users = this->repo_users.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_username() == username)
			return 1;
	}
	return 0;
}

int Service_Users::verify_user(string password)
{

	vector<Users> users = this->repo_users.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_password() == password)
			return 1;
	}
	return 0;
}
