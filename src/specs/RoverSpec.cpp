
#include <igloo/igloo_alt.h>
#include "../Rover.h"

using namespace igloo;

//Describe(in_distorted_mode)
//{
//	It(foo)
//	{
//	  Assert::That(0, Equals(1));
//	}
//};

Describe(aRover) {

	It(hasNoMovement){
		Rover rover(0,0,"N");

		rover.move("");

		Assert::That(Rover(0,0,"N"), Equals(rover));
	}

	It(rotatesLeftFacingNorth) {
		Rover rover(0, 0, "N");

		rover.move("l");

		Assert::That(Rover(0,0,"W"), Equals(rover));
	}

//	Describe(aRover) {
	It(rotatesRightFacingNorth) {
		Rover rover(0, 0, "N");

		rover.move("r");

		Assert::That(Rover(0,0,"E"), Equals(rover));
	}

	It(rotatesLeftFacingSouth){
		Rover rover(0, 0, "S");

		rover.move("l");

		Assert::That(Rover(0,0,"E"), Equals(rover));
	}

	It(rotatesRightFacingSouth){
		Rover rover(0, 0, "S");

		rover.move("r");

		Assert::That(Rover(0,0,"W"), Equals(rover));
	}

	It(rotatesLeftFacingEast){
		Rover rover(0, 0, "E");

		rover.move("l");

		Assert::That(Rover(0,0,"N"), Equals(rover));
	}

	It(rotatesRightFacingEast){
		Rover rover(0, 0, "E");

		rover.move("r");

		Assert::That(Rover(0,0,"S"), Equals(rover));
	}

	It(rotatesLeftFacingWest){
		Rover rover(0, 0, "W");

		rover.move("l");

		Assert::That(Rover(0,0,"S"), Equals(rover));
	}

	It(rotatesRightFacingWest){
		Rover rover(0, 0, "W");

		rover.move("r");

		Assert::That(Rover(0,0,"N"), Equals(rover));
	}

	It(movesForwardFacingNorth){
		Rover rover(0, 0, "N");

		rover.move("f");

		Assert::That(Rover(0,1,"N"), Equals(rover));
	}

	It(movesForwardFacingSouth){
		Rover rover(0, 0, "S");

		rover.move("f");

		Assert::That(Rover(0,-1,"S"), Equals(rover));
	}

	It(movesForwardFacingEast){
		Rover rover(0, 0, "E");

		rover.move("f");

		Assert::That(Rover(1,0,"E"), Equals(rover));
	}

	It(movesForwardFacingWest){
		Rover rover(0, 0, "W");

		rover.move("f");

		Assert::That(Rover(-1,0,"W"), Equals(rover));
	}

	It(movesBackwardFacingNorth){
		Rover rover(0, 0, "N");

		rover.move("b");

		Assert::That(Rover(0,-1,"N"), Equals(rover));
	}

	It(movesBackwardFacingSouth){
		Rover rover(0, 0, "S");

		rover.move("b");

		Assert::That(Rover(0,1,"S"), Equals(rover));
	}

	It(movesBackwardFacingEast){
		Rover rover(0, 0, "E");

		rover.move("b");

		Assert::That(Rover(-1,0,"E"), Equals(rover));
	}

	It(movesBackwardFacingWest){
		Rover rover(0, 0, "W");

		rover.move("b");

		Assert::That(Rover(1,0,"W"), Equals(rover));

	}

	It(hasLotMoves){
		Rover rover(0, 0, "W");

		rover.move("lffrbbllf");

		Assert::That(Rover(3,-2,"E"), Equals(rover));
	}


};
