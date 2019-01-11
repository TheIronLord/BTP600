#ifndef FSMACHINE_H
#define FSMACHINE_H

class BaseState;
class StateA;
class StateB;
class StateC;
class StateD;


enum states { A, B, C, D };

class FSMachine {
private:
	BaseState* FsState;
public:
	FSMachine();
	states state();
	void actionOne();
	void actionTwo();
	void actionThree();
	void changeState(BaseState* newState);
};



class BaseState {
protected:
	void changeState(FSMachine* fsMachine, BaseState* newState_) {
		fsMachine->changeState(newState_);
	}
public:
	virtual states getState() = 0;
	virtual void actionOne(FSMachine *fsMachine) = 0;
	virtual void actionTwo(FSMachine *fsMachine) = 0;
	virtual void actionThree(FSMachine *fsMachine) = 0;
};

class StateA : public BaseState {
	states State;
public:
	StateA() {
		State = A;
	}
	static BaseState* getInstance();
	states getState() {
		return State;
	}
	void actionOne(FSMachine * fsMachine);
	void actionTwo(FSMachine * fsMachine);
	void actionThree(FSMachine * fsMachine);
};

class StateB : public BaseState {
	states State;
public:
	StateB() {
		State = B;
	}
	static BaseState* getInstance();
	states getState() {
		return State;
	}

	void actionOne(FSMachine * fsMachine);
	void actionTwo(FSMachine* fsMachine);
	void actionThree(FSMachine* fsMachine);
};

class StateC : public BaseState {
	states State;
public:
	StateC() {
		State = C;
	}
	static BaseState* getInstance();
	states getState() {
		return State;
	}
	void actionOne(FSMachine* fsMachine);
	void actionTwo(FSMachine* fsMachine);
	void actionThree(FSMachine* fsMachine);
};

class StateD : public BaseState {
	states State;
public:
	StateD() {
		State = D;
	}
	static BaseState* getInstance();
	states getState() {
		return State;
	}
	void actionOne(FSMachine* fsMachine);
	void actionTwo(FSMachine* fsMachine);
	void actionThree(FSMachine* fsMachine);
};



/*Definitions*/

//StateA
BaseState* StateA::getInstance() {
	StateA* stateA = new StateA();
	return stateA;
}

void StateA::actionOne(FSMachine * fsMachine) {
	changeState(fsMachine, StateB::getInstance());
}
void StateA::actionTwo(FSMachine * fsMachine) {
	changeState(fsMachine, StateA::getInstance());
}
void StateA::actionThree(FSMachine * fsMachine) {
	changeState(fsMachine, StateD::getInstance());
}


//StateB
BaseState* StateB::getInstance() {
	StateB* stateB = new StateB();
	return stateB;
}
void StateB::actionOne(FSMachine * fsMachine) {
	changeState(fsMachine, StateC::getInstance());
}
void StateB::actionTwo(FSMachine* fsMachine) {
	changeState(fsMachine, StateA::getInstance());
}
void StateB::actionThree(FSMachine* fsMachine) {
	changeState(fsMachine, StateD::getInstance());
}

//StateC
BaseState* StateC::getInstance() {
	StateC* stateC = new StateC();
	return stateC;
}
void StateC::actionOne(FSMachine* fsMachine) {
	changeState(fsMachine, StateB::getInstance());
}
void StateC::actionTwo(FSMachine* fsMachine) {
	changeState(fsMachine, StateA::getInstance());
}
void StateC::actionThree(FSMachine* fsMachine) {
	changeState(fsMachine, StateD::getInstance());
}

//StateD
BaseState* StateD::getInstance() {
	StateD* stateD = new StateD();
	return stateD;
}
void StateD::actionOne(FSMachine* fsMachine) {
	changeState(fsMachine, StateA::getInstance());
}
void StateD::actionTwo(FSMachine* fsMachine) {
	changeState(fsMachine, StateC::getInstance());
}
void StateD::actionThree(FSMachine* fsMachine) {
	changeState(fsMachine, StateD::getInstance());
}

//FSMachine
FSMachine::FSMachine() {
	FsState = StateA::getInstance();
}
states FSMachine::state() {
	return FsState->getState();
}
void FSMachine::actionOne() {
	FsState->actionOne(this);
}
void FSMachine::actionTwo() {
	FsState->actionTwo(this);
}

void FSMachine::actionThree() {
	FsState->actionThree(this);
}
void FSMachine::changeState(BaseState* newState) {
	FsState = newState;
}
#endif