#ifndef REPO_CSV_H
#define REPO_CSV_H

#include <iostream>
#include "Repo.h"
using namespace std;

class Repo_Csv : public Repo
{
public:
	Repo_Csv();
	Repo_Csv(string file_name);
	~Repo_Csv();

	void load_to_file();
	void save_to_file();
};
#endif // !REPO_CSV_H