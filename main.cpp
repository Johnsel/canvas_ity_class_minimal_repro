#ifndef CANVAS_ITY_IMPLEMENTATION
#define CANVAS_ITY_IMPLEMENTATION
#include "./canvas_ity/src/canvas_ity.hpp"
#endif

#include <time.h>
#include <iostream>
#include <memory>

using namespace std;

// create a new class called Person
class Person
{
// public variables and functions
public:
	// class constructor
	Person();

	std::string name;
	int age;
    
	void setName(std::string);
	void setAge(int);


    // Preferred:
    // canvas_ity::canvas eyemask_canvas;

    // Workaround part 1, initialize in class definition as single pixel
    canvas_ity::canvas eyemask_canvas = canvas_ity::canvas(1,1);

	void draw(int x, int y);
};

Person::Person()
{
}

void Person::setName(std::string userName)
{
	name = userName;
}

void Person::setAge(int userAge)
{
	age = userAge;

}


void Person::draw(int x, int y)
{
    // Preferred, but not posisble it seems:
    // eyemask_canvas = = canvas_ity::canvas(x,y);
    // or
    // this->eyemask_canvas = canvas_ity::canvas(x,y);

    // Workaround part 2 together with class definition workaround
    eyemask_canvas.scale(x,y);

    // some draw calls    
    eyemask_canvas.fill_rectangle(x/3, y/3, x/2, y/2);
}

int main(void)
{
	// create a new person named bob
	Person martin;

	martin.setName("Martin Freeman");
	martin.setAge(42);
    martin.draw(1920,1080);

	// display Martin's age
	std::cout << martin.name << " is " << martin.age << " years old." << "We have his picture but can't display it yet. Soon!" << std::endl;
}