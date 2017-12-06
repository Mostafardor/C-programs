/**
 * 	Polimorfismo.cxx
 */

#include <iostream>
#include <new>

using std::string;
using std::cout;
using std::endl;

class Animal 
{
private:
	// ...
protected:
	string name;
	bool sex;
	int legs;
	
	static int numOfAnimals;
public:
	Animal(string,int,bool);
	~Animal();
	void setName(string);
	void setSex(bool);
	void setLegs(int);
	// virtual solo va en las 
	// clases padre.
	virtual void toString();
	// me da pereza los getters
	// usare el metodo toString().
	static int getNumOfAnimals() { return numOfAnimals; }
};

class Human : public Animal 
{
private:
	string nameHuman;
	int age;
public:
	Human(string,int,bool,string,int);
	~Human();
	void setnameHm(string);
	void setAge(int);
	void toString(); // polimorfismo
};

class Dog : public Animal 
{
private:
	string race;
	string nameDog;
public:
	Dog(string,int,bool,string,string);
	~Dog();
	void setRace(string);
	void setNameDog(string);
	void toString();
};

/*---------------- metodos de Human -------------*/

int Animal::numOfAnimals = 0;

Animal::Animal(string name,int legs,bool sex)  
{
	this->name = name; 
	this->legs = legs;
	this->sex = sex;
	
	numOfAnimals++;
}

Animal::~Animal() { }

void Animal::toString() {
	cout << " Name Animal  " << name << endl
		<< " Have  " << legs << " legs " << endl
		<< " sex is " ; 
		(sex)? cout << " female " << endl :
			cout << " male " << endl;
}

void Animal::setName(string name){
	this->name = name;
}

void Animal::setSex(bool sex){
	this->sex = sex;
}
void Animal::setLegs(int legs){
	this->legs = legs;
}

/*---------------- metodos de Human -------------*/

Human::Human(string name,int legs,bool sex,string nameH,int age) 
	: Animal(name,legs,sex) 
{ 
	this->nameHuman = nameH;
	this->age = age;
}

Human::~Human() { }

void Human::setnameHm(string nameHm){
	this->nameHuman = nameHm;
}

void Human::setAge(int age){
	this->age = age;
}

void Human::toString(){
	
	Animal::toString(); // esto llama a un metodo virtual
	
	cout << " hi my name is  " << nameHuman << endl
		<< " and I have  " << age << " years old " <<endl; 
} 


/*---------------- metodos de Dog -------------*/

Dog::Dog(string name,int legs,bool sex,string race,string nameD) 
	: Animal(name,legs,sex) 
{
	this->nameDog = nameD;
	this->race = race;
}

Dog::~Dog() { }

void Dog::setRace(string race){
	this->race = race;
}

void Dog::setNameDog(string nameD){
	this->nameDog = nameD;
}

void Dog::toString(){
	
	Animal::toString();
	
	cout << " Name : " << nameDog << endl
		<< " Race : " << race << endl;
}


int main(int argc, char **argv)
{ 
	Animal *myClases[2]; 
	
	myClases[0] = new Human("Human",2,false,"Jakob",19);
	
	myClases[1] = new Dog("Dog",4,true,"Deutscher Schäferhund","Maho");	
	
	myClases[0]->toString();
	
	cout << endl;
	
	myClases[1]->toString();
	
	cout << endl;
	
	int x = myClases[0]->getNumOfAnimals();
	
	cout << " num of animals : " << x << endl;
	
	return 0;	
}

