
public class HasCard implements ATMState {

	ATMMachine atmMachine;
	
	public HasCard(ATMMachine newATMMachine){
		atmMachine = newATMMachine;
	}
	
	@Override
	public void insertCard() {
	
		System.out.println("You can only insert one card at a time");
		
	}

	@Override
	public void ejectCard() {
		
		System.out.println("Your card is ejected");
		atmMachine.SetATMState(atmMachine.getNoCardState());
		
	}

	@Override
	public void insertPin(int pinEntered) {
		
		if(pinEntered == 1234){
			
			System.out.println("You have entered the right pin");
			atmMachine.correctPinEntered = true;
			atmMachine.SetATMState(atmMachine.getHasPin());
		}else{
			System.out.println("You have entered the wrong pin");
			atmMachine.correctPinEntered = false;
			System.out.println("Card ejected");
			atmMachine.SetATMState(atmMachine.getNoCashState());
		}
		
	}

	@Override
	public void requestCash(int cashToWithdraw) {
		
		System.out.println("You have not entered your pin");
		
	}
	
}
