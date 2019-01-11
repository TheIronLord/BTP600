public class TestCalcChain {
	
	public static void main(String[]args){
		
		// Here I define all of the objects in the chain
		
		Chain ChainCalc1 = new AddNumbers();
		Chain ChainCalc2 = new SubtractNumbers();
		Chain ChainCalc3 = new MultNumbers();
		Chain ChainCalc4 = new DivideNumbers();
		
		// Here I tell each object where to forward the
		// data if it can't process the request
		
		ChainCalc1.setNextChain(ChainCalc2);
		ChainCalc2.setNextChain(ChainCalc3);
		ChainCalc3.setNextChain(ChainCalc4);
		
		// Define the data in the Numbers Object
		// and send it to the first Object in the chain
		
		Numbers request = new Numbers(4,2,"div");
		
		ChainCalc1.calculate(request);
		
	}
}
