// The Adapter must provide an alternative action for
// the methods that need to be used because
// EnemyAttacker walk implemented

// The adapter contains an object
// of the same type as the adaptee (EnemyRobot)
// All calls to EnemyAttacker methods are sent 
// instead to methods used by EnemyRobot

public class EnemyRobotAdapter implements EnemyAttacker{

	EnemyRobot theRobot;
	
	public EnemyRobotAdapter(EnemyRobot _theRobot){
		theRobot = _theRobot;
	}
	@Override
	public void fireWeapon() {
		
		theRobot.smashWithHands();
		
	}
	@Override
	public void driveForward() {
		
		theRobot.walkForward();
		
	}
	@Override
	public void assignDriver(String driverName) {
		
		theRobot.rectToHuman(driverName);
		
	}
}
