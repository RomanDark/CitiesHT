#include "Cities.h"



Cities::Cities(string dir)
{
	this->dir = dir;
	
	fstream cities;
	cities.open(dir + "\\city.csv");

	if (!cities) {
		cout << "�� ������� ������� �����!";
		system("pause");
		exit(-1);
	}
	
	string str;
	getline(cities, str);

	while (!cities.eof()) {

		getline(cities, str);
		if (str.size() > 0) {
	
			string key = str.substr(str.rfind(";\"") + 2);
			key.pop_back();
			int pos = str.find("\";\"") + 3;
			int pos2 = str.find("\";\"", pos);
			string value = str.substr(pos, pos2 - pos);
			this->cities.emplace(key, value);
		}
	}
	cities.close();
	
	fstream countries;
	countries.open(dir + "\\country.csv");
	if (!countries) {
		cout << "�� ������� ������� ����!";
		system("pause");
		exit(-1);
	}
	getline(countries, str);
	while (!countries.eof()) {

		getline(countries, str);
		if (str.size() > 0) {
			string key, value;
			key = str.substr(1, str.find("\";") - 1);
			value = str.substr(str.rfind(";\"") + 2);
			value.pop_back();
			country.emplace(key, value);
		}
	}
	countries.close();
	
	for (auto&i : this->cities) {
		i.second = country[i.second];
		
	}

	enter();
}

void Cities::find(string city)
{
	if (cities.find(city) == cities.end())
		throw exception("����� �� ������!\n");

	cout << "������: " << cities.find(city)->second << endl;
}

void Cities::enter()
{
	string name;
	
	while (1) {
		system("cls");
		cout << "������� �������� ������: ";
		cin >> name;
		try {
			this->find(name);
		}
		catch(exception&e){
			cout << e.what();
			
		}
		system("pause");
	}
}






