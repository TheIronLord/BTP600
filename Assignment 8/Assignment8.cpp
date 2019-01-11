#include <iostream>
#include <string>
using namespace std;
class Memento{
    private:
            string state;
    public:
            Memento(string _state = ""){
                state = _state;
            }
            string getState(){
                return state;
            }
};

class CareTaker{
    Memento Articles[5];
    int currentIndex;
    public:
        CareTaker(){
        	currentIndex = 0;
        }
        void addMemento(Memento m){
            Articles[currentIndex] = m;
            ++currentIndex;
        }
        Memento getMemento(int index){
            if(index > -1){
            	currentIndex--;
                return Articles[index];
            }
        }
};

class Data{
	string state;
public:
	void setState(string _state){
        state = _state;
    }
    string getState(){
        return state;
    }
    Memento saveStateToMemento(){
    	Memento m(state);
        return m;
    }
    void getStateFromMemento(Memento m){
        state = m.getState();
    }
    void print(){
        cout << state << endl;
    }
};

int main(void){
	Data D;
	int choice;
	string inputString;
	string inputNumber;
    int currentIndex = -1;
    CareTaker careTaker;
	do{
		cout << "*********************************" << endl;
		cout << "what would you like to do: " << endl;
		cout << "1) Modify string" << endl;
		cout << "2) Modify number" << endl;
		cout << "3) undo"	<< endl;
		cout << "4) exit"  << endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout << "enter a new string" << endl;
				cin >> inputString;
				D.setState(inputString);
                careTaker.addMemento(D.saveStateToMemento());
                currentIndex++;
				cin.clear();
				cin.ignore(1000,'\n');
				break;
			case 2:
				cout << "enter a new number" << endl;
				cin >> inputNumber;
				if(cin){
					D.setState(inputNumber);
                    careTaker.addMemento(D.saveStateToMemento());
                    currentIndex++;
				}
				else{
					cin.clear();
					cin.ignore(1000,'\n');
				}
				break;
			case 3:
				if(currentIndex > -1){ 
					D.getStateFromMemento(careTaker.getMemento(currentIndex--));
				}
				break;

		}
		cout << "the object: " << endl;
		D.print();
	}while(choice != 4);
}