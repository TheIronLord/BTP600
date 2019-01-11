#include "room.h"
class Builder {
public:
	virtual void setStudents(int _numStudents) = 0;
	virtual void buildTables() = 0;
	virtual void buildChairs() = 0;
	virtual void buildComputers() = 0;
	virtual Room* getRoom() = 0;
};

class Director {
	Builder* builder;
public:
	void setBuilder(Builder& newBuilder);
	Room* buildRoom(int numStudents);
};

class ALCBuilder : public Builder{
	Room* room;
	int numStudents;
public:
	ALCBuilder();
	void setStudents(int _numStudents);
	void buildTables();
	void buildChairs();
	void buildComputers();
	Room* getRoom();
};

class LabBuilder : public Builder{
	Room* room;
	int numStudents;
public:
	LabBuilder();
	void setStudents(int _numStudents);
	void buildTables();
	void buildChairs();
	void buildComputers();
	Room* getRoom();
};

class StepRoomBuilder : public Builder{
	Room* room;
	int numStudents;
public:
	StepRoomBuilder();
	void setStudents(int _numStudents);
	void buildTables();
	void buildChairs();
	void buildComputers();
	Room* getRoom();
};
