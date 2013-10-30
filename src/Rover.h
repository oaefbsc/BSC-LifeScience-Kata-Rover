/*
 * Rover.h
 *
 *  Created on: Oct 24, 2013
 *      Author: priera
 */

#ifndef ROVER_H_
#define ROVER_H_

#include <string>

class Position {
public:
	Position(int x, int y);

	int getX();
	int getY();

	static bool compare(Position * lhs, Position * rhs);

private:
	int x, y;
};

class Direction{	//clase abstracta que hereda metodos implementados por los hijos

public:

	static bool compare(Direction * lfs, Direction * rhs);

	virtual Direction * girar (char cambio) = 0;
	virtual Position * moverAdelante(Position * pos) = 0;
	virtual Position * moverAtras(Position * pos) = 0;

	virtual ~Direction();

protected:
	static std::string NORTH;
	static std::string WEST;
	static std::string EAST;
	static std::string SOUTH;

	Direction(std::string description);

private:

	std::string description;
};

class North: public Direction{

public:
	Direction * girar(char cambio);
	Position * moverAdelante(Position * pos);
	Position * moverAtras(Position * pos);

	North();

};

class South: public Direction{

public:
	Direction * girar(char cambio);
	Position * moverAdelante(Position * pos);
	Position * moverAtras(Position * pos);

	South();
};

class East: public Direction{

public:
	Direction * girar (char cambio);
	Position * moverAdelante(Position * pos);
	Position * moverAtras(Position * pos);

	East();
};

class West: public Direction{

public:
	Direction * girar (char cambio);
	Position * moverAdelante(Position * pos);
	Position * moverAtras(Position * pos);

	West();
};




class Rover {
public:
	Rover(int x, int y, const std::string & direction);
	virtual ~Rover();

	void move(std::string commandSequence);

	bool operator==(const Rover& rhs) const;

private:

	Direction * direct;
	Position * pos;

	void cambiaPosicion (char paso);
	void cambiaDireccion (char mira);

	bool changePosition(char action);
	bool changeDirection(char action);

	void doAction(char action);
};

#endif /* ROVER_H_ */
