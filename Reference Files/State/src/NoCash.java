
public class NoCash implements ATMState{

	ATMMachine atmMachine;
	
	public NoCash(ATMMachine newATMMachine){
		atmMachine = newATMMachine;
	}
	
	@Override
	public void insertCard() {
		
		System.out.println("No cash in the machine");
		
	}

	@Override
	public void ejectCard() {
		
		System.out.println("No cash in the machine");
		
	}

	@Override
	public void insertPin(int pinEntered) {
		
		System.out.println("No cash in the machine");
		
	}

	@Override
	public void requestCash(int cashToWithdraw) {
		
		System.out.println("No cash in the machine");
		
	}

}
