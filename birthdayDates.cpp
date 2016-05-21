#include <list>
#include <iostream>
using namespace std;

typedef struct {
	int day;
	int month;
} Date;

class FriendsGroup {
	private:
		list< pair<const char *, Date> > friendsList;
	public:
		void show(void);
		void addFriend(const char *, Date);
};

void FriendsGroup::show(void) { 
	/* Iterador para friendsList */
	list< pair<const char *, Date> >::iterator it01;
	/* Iterador para temporalList */
	list< pair<Date, list<const char *> > >::iterator it02;

	list< pair<Date, list<const char *> > > temporalList;
	bool matchFound;

	for(it01 = friendsList.begin(); it01 != friendsList.end(); ++it01) {
		matchFound = false;
		for(it02 = temporalList.begin(); it02 != temporalList.end(); ++it02) {
			/* Verificamos si hay coincidencia */
			if((*it01).second.day == (*it02).first.day && (*it01).second.month == (*it02).first.month) {
				/* En el Date de temporalList, inserta el nombre del cumpleañero */
				(*it02).second.push_back((*it01).first);
				matchFound = true;
				break;
			}
		}
		/* Si el Date no estaba en temporalList, la agrego junto con la namesList */
		if(not matchFound) {
			list<const char *> namesList;
			namesList.push_back((*it01).first);
			temporalList.push_back(pair<Date, list<const char *> >((*it01).second, namesList));
		}
	}
	/* Show */
	for(it02 = temporalList.begin(); it02 != temporalList.end(); ++it02) {
		/* Comprueba que la lista asociada al Data tenga más de un cumpleañero */
		if((*it02).second.size() > 1) {
			cout << (*it02).first.day << "/" << (*it02).first.month << ": ";
			for(list<const char *>::iterator it03 = (*it02).second.begin(); it03 != (*it02).second.end(); ++it03) {
				cout << *it03 << " ";
			}
			cout << endl;
		}
	}
}

void FriendsGroup::addFriend(const char *friendsName, Date birthdayDate) {
	friendsList.push_back(pair<const char *, Date>(friendsName, birthdayDate));
}

int main(void) {
	FriendsGroup friendsGroup;
	Date date01 = {28, 4};
	Date date02 = {28, 4};
	Date date03 = {28, 9};

	friendsGroup.addFriend((const char *)"mauri", date01);
	friendsGroup.addFriend((const char *)"lautaro", date02);
	friendsGroup.addFriend((const char *)"cristian", date03);
	friendsGroup.show();

	return 0;
}