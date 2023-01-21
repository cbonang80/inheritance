#include <iostream>
#include <string>
using namespace std; 
/*
	Sections Introduced in the function main()
		1. Regular Class Example: Dot operator VS Pointer
		2. More Stuff on Using the Dot (.) operator
		3. Inheritance, Polymorphism, and the delete keyword
*/ 	 
    
//===== Regular Class example ==============================================================//
class Wizard
{
// access specifier: remember, there are 3 access specifiers: public, private, and protected
  public: // allows us to access outside 
	  Wizard() {}  //Constructor 
	  Wizard(int hp, int level) { cout << "hp: " << hp << " " << "level: " << level << endl;  }; //Parameterized Constructor 
	  string name;
};
//========================================================================================//

//===== Inheritance and Polymorphism example ================================================//
// @Animal: Animal is the base class. 
class Animal
{
   public:
	   Animal() {}
	   virtual ~Animal() { cout << "Animal destructor called" << endl; }
	   virtual void speak() {cout << "no sound" << endl;}
};
// @Dog: The Dog class is the derived class that inherits everything from the Animal class
//       However, you may notice that the speak() function is distinct from Animal class's 
//       speak function. This is an example of polymorphism. It inherits the speak() 
//       function from Animal, but the body of the function is different. 
//       We use 'virtual' to ensure that Dog's unique speak function is invoked and not the 
//       Animal base class. 
class Dog : public Animal {
public: 
	Dog(): Animal() {}
	virtual ~Dog() { cout << "Dog Destructor called" << endl;  }
	void speak() { cout << "bark" << endl;  }

};
// @Cat: The Cat class is the derived class that inherits everything from the Animal class
//       However, you may notice that the speak() function is distinct from Animal class's 
//       speak function. This is an example of polymorphism. It inherits the speak() 
//       function from Animal, but the body of the function is different. 
//       We use 'virtual' to ensure that Cat's unique speak function is invoked and not the 
//       Animal base class. 
class Cat : public Animal {
public:
	Cat() : Animal() {}
	virtual ~Cat() { cout << "Cat destructor called" << endl;  }
	void speak() { cout << "meow" << endl; }

};												
//========================================================================================//


int main()
{
  //==== Regular Class Example: Dot operator VS Pointer ====// 
	cout << "Regular Class Example: Dot operator VS Pointer" << endl; 
	// Dot operator (.) is used with CLASS OBJECTS 
	Wizard gandalf; // Object of default constructor is allocated on the STACK 
	gandalf.name = "gandalf"; // Assigned member variable, 'name' to gandalf 
	cout << gandalf.name << endl; // Print what is stored in name
	// Pointer is used with 'new' 
	/* What's happening below???
	     1. Wizard * p_wiz: created a pointer to a Wizard class. 

	     2. new Wizard(): Creates a Wizard object. 
		   'new' allocates memory on the heap (Ah, time to put this on the heap) 
		    Remember: anything to do with memory allocation goes on the heap!!! 

	     3. Lets put it together: Wizard* p_wiz = new Wizard(); 
		    A pointer to the Wizard class object holds the address of the wizard object on the heap
	*/
	Wizard* p_wiz = new Wizard(); 
	p_wiz->name = "merlin"; 
	cout << p_wiz->name << endl; // Print name 
	Wizard harry(5, 3); //  parametrized constructor is called 
//==== More Stuff on Using the Dot (.) operator ====//
	/*
		1. There is no polymorphic behavior in this example
		2. The object is being allocated on the stack not the heap.
		   Why? 'new' is not being used, therefore no memory allocation is occurring (So, it doesn't go on the heap).
		3. Once out of scope (when main ends), the destructor is called and the objects are popped off the stack
	*/
#if 0 // Change the 0 to 1 to use the code below 
	cout << "More Stuff on Using the Dot (.) operator" << endl; 
	Dog dog; // Dog object is created 
	dog.speak(); // speak() function is invoked 
	Cat cat; // Cat object created 
	cat.speak();
#endif 
//==== Inheritance, Polymorphism, and the delete keyword ====// 
	/*
	    1. Stack and Heap 
	       Remember, a pointer is simply a variable that holds an address 
		   Although, the animal object lives on the heap, the pointer itself lives on the stack and contains the heap address of animal. 
		2. 'delete' keyword 
		  The delete keyword DOES NOT delete the pointer itself. 
		  Given the example below: 
		     Animal* p_animal = new Animal(); 
	         p_animal->speak(); 
	         delete p_animal;
	      It deletes the object animal that was stored in the heap
		3. Polymorphism and 'virtual' 
		   We can see polymophism is at work when speak() is invoked. When we run the code below, it will print out 'no sound' and 'bark'. 
		   Despite the Dog class inheriting the speak() function from Animal, it has it's own behavior. 
		   - The keyword 'virtual' assists with this. 
		   - Try REMOVING Animal's 'virtual' keyword next to the speak() function in Animal class's definition.
		   - bark and meow WILL NOT be outputted 
	*/
#if 1 // change to 0 when you wish not to run the following code. 
	cout << "Inheritance, Polymorphism, and the delete keyword" << endl; 
	Animal* p_animal = new Animal(); // pointing to an animal object allocated on the heap using new 
	p_animal->speak(); // no sound 
	delete p_animal; // memory is deallocated (freed) after the destructor is called 
	p_animal = new Dog(); 
	p_animal->speak(); // bark 
	delete p_animal; 
	p_animal = new Animal();
	p_animal->speak();// no sound 
	delete p_animal; 
	p_animal = new Cat();
	p_animal->speak(); // meow 
	delete p_animal;
#endif 
	return 0; 
}
