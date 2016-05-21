#include <iostream>
#include "gmock/gmock.h"
using namespace std;

class BaseClass {
	public:
		/* Pure virtual functions providing interface framework */
		virtual ~BaseClass() {}
		virtual void hello() = 0;
		virtual void goodBye() = 0;
		virtual void howAreYou() = 0;
		virtual void fineAndYou() = 0;
		virtual void seeYouLater() = 0;
};

class Class01 : public BaseClass {
	public:
		void hello() {cout << "Hello!\n";}
		void goodBye() {cout << "Goodbye!\n";}
		void howAreYou() {cout << "How are you?\n";}
		void fineAndYou() {cout << "Fine and you?\n";}
		void seeYouLater() {cout << "See you later!\n";}
};

class Class02 : public BaseClass {
	public:
		void hello() {cout << "Hello!\n";}
		void goodBye() {cout << "Goodbye!\n";}
		void howAreYou() {cout << "How are you?\n";}
		void fineAndYou() {cout << "Fine and you?\n";}
		void seeYouLater() {cout << "See you later!\n";}
};

int main(void) {
	Class01 object01;
	Class02 object02;

	object01.hello();
	object02.goodBye();

	return 0;
}