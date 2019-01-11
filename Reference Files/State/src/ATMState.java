
public interface ATMState {
	
	//Different States Expected
	// HasCard, NoCard, HasPin, NoCash
	
	void insertCard();
	
	void ejectCard();
	
	void insertPin(int pinEntered);
	
	void requestCash(int cashToWithdraw);
}
