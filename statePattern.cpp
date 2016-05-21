#include <stdio.h>
#include <iostream>
using namespace std;

/* Enum that represents states */
enum StateEnum {
	Off,
	Stopped,
	Walking,
	Running,
	Error
};

class State {
	public:
		virtual void TurnOn() = 0;
		virtual void TurnOff() = 0;
		virtual void SpeedUp() = 0;
		virtual void SpeedDown() = 0;
};

class OffState : public State {
	public:
		void TurnOn() {cout << "[Off] ----- <TurnOn> -----> [Stopped]" << endl;}
		void TurnOff() {cout << "[Off] ----- <TurnOff> -----> [Off]" << endl;}
		void SpeedUp() {cout << "[Off] ----- <SpeedUp> -----> [Off]" << endl;}
		void SpeedDown() {cout << "[Off] ----- <SpeedDown> -----> [Off]" << endl;}
};

class StoppedState : public State {
	public:
		void TurnOn() {cout << "[Stopped] ----- <TurnOn> -----> [Stopped]" << endl;}
		void TurnOff() {cout << "[Stopped] ----- <TurnOff> -----> [Off]" << endl;}
		void SpeedUp() {cout << "[Stopped] ----- <SpeedUp> -----> [Walking]" << endl;}
		void SpeedDown() {cout << "[Stopped] ----- <SpeedDown> -----> [Error]" << endl;}
};

class WalkingState : public State {
	public:
		void TurnOn() {cout << "[Walking] ----- <TurnOn> -----> [Walking]" << endl;}
		void TurnOff() {cout << "[Walking] ----- <TurnOff> -----> [Off]" << endl;}
		void SpeedUp() {cout << "[Walking] ----- <SpeedUp> -----> [Running]" << endl;}
		void SpeedDown() {cout << "[Walking] ----- <SpeedDown> -----> [Stopped]" << endl;}
};

class RunningState : public State {
	public:
		void TurnOn() {cout << "[Running] ----- <TurnOn> -----> [Running]" << endl;}
		void TurnOff() {cout << "[Running] ----- <TurnOff> -----> [Off]" << endl;}
		void SpeedUp() {cout << "[Running] ----- <SpeedUp> -----> [Error]" << endl;}
		void SpeedDown() {cout << "[Running] ----- <SpeedDown> -----> [Walking]" << endl;}
};

class ErrorState : public State {
	public:
		void TurnOn() {cout << "[Error] ----- <TurnOn> -----> [Error]" << endl;}
		void TurnOff() {cout << "[Error] ----- <TurnOff> -----> [Off]" << endl;}
		void SpeedUp() {cout << "[Error] ----- <SpeedUp> -----> [Error]" << endl;}
		void SpeedDown() {cout << "[Error] ----- <SpeedDown> -----> [Error]" << endl;}
};

class FiniteStateMachine {
	private:
		State *statesVector[5];
		enum StateEnum currentState;
		enum StateEnum nextState[5][4];
	public:
		FiniteStateMachine() {
			currentState = Off;
			statesVector[0] = new OffState;
			statesVector[1] = new StoppedState;
			statesVector[2] = new WalkingState;
			statesVector[3] = new RunningState;
			statesVector[4] = new ErrorState;
			nextState[0][0] = Stopped; nextState[0][1] = Off; nextState[0][2] = Off; nextState[0][3] = Off;
			nextState[1][0] = Stopped; nextState[1][1] = Off; nextState[1][2] = Walking; nextState[1][3] = Error;
			nextState[2][0] = Walking; nextState[2][1] = Off; nextState[2][2] = Running; nextState[2][3] = Stopped;
			nextState[3][0] = Running; nextState[3][1] = Off; nextState[3][2] = Error; nextState[3][3] = Walking;
			nextState[4][0] = Error; nextState[4][1] = Off; nextState[4][2] = Error; nextState[4][3] = Error;
		}
		void TurnOn() {
			statesVector[currentState]->TurnOn();
			currentState = nextState[currentState][0];
		}
		void TurnOff() {
			statesVector[currentState]->TurnOff();
			currentState = nextState[currentState][1];
		}
		void SpeedUp() {
			statesVector[currentState]->SpeedUp();
			currentState = nextState[currentState][2];
		}
		void SpeedDown() {
			statesVector[currentState]->SpeedDown();
			currentState = nextState[currentState][3];
		}
};

int main() {
	int option;
	FiniteStateMachine fsm;

	do {
		cin >> option;
		switch(option) {
			case 0:
				fsm.TurnOn();
				break;
			case 1:
				fsm.TurnOff();
				break;
			case 2:
				fsm.SpeedUp();
				break;
			case 3:
				fsm.SpeedDown();
				break;
			default:
				cout << "The stimulus does not exist!" << endl;
				break;
		}
	} while(option != 9);

	return 0;
}