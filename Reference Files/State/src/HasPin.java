
public class HasPin implements ATMState {

	ATMMachine atmMachine;
	
	public HasPin(ATMMachine newATMMachine){
		atmMachine = newATMMachine;
	}
	
	@Override
	public void insertCard() {
		
		System.out.println("There is already a card inserted into the machine");
		
	}

	@Override
	public void ejectCard() {
		
		System.out.println("Card ejected");
		atmMachine.SetATMState(atmMachine.getNoCardState());
		
	}

	@Override
	public void insertPin(int pinEntered) {
		
		System.out.println("You already entered your pin");
		
	}

	@Override
	public void requestCash(int cashToWithdraw) {
		
		if(cashToWithdraw > atmMachine.cashInMachine){
			System.out.println("The cash requested is more than that in the machine");
			System.out.println("Card ejected");
			atmMachine.SetATMState(atmMachine.getNoCardState());
		}else{
			System.out.println(cashToWithdraw + " is provided by the machine");
			atmMachine.setCashInMachine(atmMachine.cashInMachine - cashToWithdraw);
			System.out.println("Card ejected");
			atmMachine.SetATMState(atmMachine.getNoCardState());
			
			if(atmMachine.cashInMachine <= 0){
				atmMachine.SetATMState(atmMachine.getNoCashState());
			}
		}
		
	}
	

}
