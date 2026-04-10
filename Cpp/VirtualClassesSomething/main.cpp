//
//  main.cpp
//  classes_11
//
//  Created by Grzegorz Szubryt on 01/04/2077.
//                                  ^ ^    ^

#include <iostream>
using namespace std;
class animal{
private:
	string name{}, species{};
public:
	virtual string speak() = 0;
	void print_name(){
		cout << "name: " << name << endl;
	}
	void print_species(){
		cout << "species: " << species << endl;
	}
	void set_name(string name){
		this->name = name;
	}
	void set_species(string species){
		this->species = species;
	}
};
class dog : public animal{
public:
	string speak(){
		return "woof woof";
	}
	dog(string name){
		set_species("dog");
		set_name(name);
	}
};
class cat : public animal{
public:
	string speak(){
		return "meow meow";
	}
	cat(string name){
		set_species("cat");
		set_name(name);
	}
};
int main(int argc, const char * argv[]) {
	vector<animal*> animals;
	animals.push_back(new dog("Burek"));
	animals.push_back(new cat("Mruczek"));
	for (animal *animal: animals) {
		animal->print_name();
		animal->print_species();
		cout << animal->speak() << endl;
		animal->set_name("string");
	}
	return 0;
}
