#ifndef A5_H
#define A5_H
#include "a5.h"

//Builder Implementation
void Director::setBuilder(Builder& newBuilder) {
	builder = &newBuilder;
}

Room* Director::buildRoom(int numStudents) {
	builder->setStudents(numStudents);
	builder->buildChairs();
	builder->buildTables();
	builder->buildComputers();
	return builder->getRoom();
}

//ALCBuilder Implementation
ALCBuilder::ALCBuilder() {
	room = new Room();
}

void ALCBuilder::setStudents(int _numStudents) {
	numStudents = _numStudents;
}

void ALCBuilder::buildChairs() {
	for (int i = 0; i < numStudents; i++) {
		room->addChair("Low Back Plastic with Wheels", 100);
	}
}

void ALCBuilder::buildTables() {
	int tableCalculation = 0;
	//Check For any students
	if (numStudents > 0) {
		//If numStudents is between 1 and 6 make 2 tables
		//and avoid an O(n) runtime
		if (numStudents >= 1 && numStudents <= 6) {
			room->addTable("half hex tables", 600);
			room->addTable("half hex tables", 600);
		}
		else {
			tableCalculation = numStudents / 3;
			for (int i = 0; i < tableCalculation; i++) {
				room->addTable("half hex tables", 600);
			}
			//Check For odd number of tables
			if (room->numTables() % 2 != 0) {
				room->addTable("half hex tables", 600);
			}
		}
	}
}

void ALCBuilder::buildComputers() {}

Room* ALCBuilder::getRoom() {
	return room;
}

//LabBuilder Implementation
LabBuilder::LabBuilder() {
	room = new Room();
}

void LabBuilder::setStudents(int _numStudents) {
	numStudents = _numStudents;
}

void LabBuilder::buildChairs() {
	room->addChair("instructor stool", 80);
	for (int i = 0; i < numStudents; i++) {
		room->addChair("Student Desk Chair", 130);
	}
}

void LabBuilder::buildTables() {
	int tableId = 0;
	int tableCalculation = 0;

	if (numStudents >= 0) {
		//Calculate how many tables will be needed
		tableCalculation = numStudents / 2;
		for (int i = 0; i < tableCalculation; i++) {
			room->addTable("2 station computer desks", 500);
		}
		//Do checking for odd students & if there is only one student
		if (numStudents % 2 != 0) {
			room->addTable("2 station computer desks", 500);
		}
	}
}

void LabBuilder::buildComputers() {
	int tableId = 0;
	int increase = 0;
	for (int i = 0; i < numStudents; i++) {
		room->addComputer("mac mini", 1000, tableId);
		increase++;
		if(increase == 2){
			tableId++;
			increase = 0;
		}
	}
}

Room* LabBuilder::getRoom() {
	return room;
}

//StepRoomBuilder
StepRoomBuilder::StepRoomBuilder() {
	room = new Room();
}

void StepRoomBuilder::setStudents(int _numStudents) {
	numStudents = _numStudents;
}

void StepRoomBuilder::buildChairs() {
	int remainder = numStudents;
	int tableCalculation = 0;

	room->addChair("instructor stool", 80);
	room->addTable("instructor table", 200);

	if (numStudents > 0) {
		//Add The first 7 chairs with one table
		room->addChair("Regular Chair", 70);

		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);
		room->addChair("padded lecture theater chairs", 150);

		remainder -= 8;
		int count = 0;
		for (int i = 0; i < remainder; i++) {
			room->addChair("padded lecture theater chairs", 150);
		}

		int leftOver = remainder % 8;
		if (leftOver > 0) {
			leftOver = 8 - leftOver;
			for (int i = 0; i < leftOver; i++) {
				room->addChair("padded lecture theater chairs", 150);
			}
		}
	}
}

void StepRoomBuilder::buildTables() {
	int remainder = numStudents;
	int tableCalculation = 0;

	if (numStudents > 0) {
		room->addTable("8 student long tables", 1000);

		remainder -= 8;

		if (remainder >= 0) {
			tableCalculation = remainder / 8;

			//Do a remainder check to see if there are any 
			//unaccounted for students
			int check = remainder % 8;
			if (check > 0) {
				tableCalculation++;
			}

			for (int i = 0; i < tableCalculation; i++) {
				room->addTable("8 student long tables", 1000);
			}
		}
	}
}

void StepRoomBuilder::buildComputers(){}
Room* StepRoomBuilder::getRoom() {
	return room;
}
#endif