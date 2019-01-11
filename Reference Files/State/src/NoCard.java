
public class NoCard implements ATMState {

	ATMMachine atmMachine;
	
	public NoCard(ATMMachine newATMMachine){
		atmMachine = newATMMachine;
	}
	
	@Override
	public void insertCard() {
		
		System.out.println("You enter your pin");
		atmMachine.SetATMState(atmMachine.getYesCardState());
		
	}

	@Override
	public void ejectCard() {
		
		System.out.println("You didn't enter a card");
		
	}

	@Override
	public void insertPin(int pinEntered) {
		
		System.out.println("You didn't enter a card");
		
	}

	@Override
	public void requestCash(int cashToWithdraw) {
		
		System.out.println("You didn't enter a card");
		
	}

}
