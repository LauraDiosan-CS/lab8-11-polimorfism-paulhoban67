#ifndef REPO_TXT_H
#define REPO_TXT_H

#include <iostream>
#include "Repo.h"
using namespace std;

class Repo_Txt : public Repo
{
public:
	Repo_Txt();
	Repo_Txt(string file_name);
	~Repo_Txt();

	void load_to_file();
	void save_to_file();
};
#endif // !REPO_TXT_H