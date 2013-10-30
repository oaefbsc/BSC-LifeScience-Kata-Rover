/*
 * Rover.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: priera
 */

#include "Rover.h"

#include <string>

#include <iostream>

using namespace std;

Position::Position(int x, int y) : x(x), y(y) {}

bool Position::compare(Position * lhs, Position * rhs){
	return (lhs->x == rhs->x && lhs->y == rhs->y);

}

int Position::getX() {
	return x;
}

int Position::getY() {
	return y;
}

Rover::Rover(int x, int y, const std::string & direction) : direct(NULL), pos(NULL) {

	if (direction == "N"){
		direct = new North();
	} else if (direction == "S"){
		direct = new South();
	} else if (direction == "E"){
		direct = new East();
	} else {
		direct = new West();
	}

	pos = new Position(x,y);
}

Rover::~Rover()
{}

void Rover::cambiaPosicion(char paso){

	bool esAdelante = (paso == 'f') ? true : false ;

	if (esAdelante) {
		pos = direct->moverAdelante(pos);
	} else {
		pos = direct->moverAtras(pos);
	}

}

void Rover::cambiaDireccion(char mira){

	direct = direct->girar(mira);
}

bool Rover::operator==(const Rover& rhs) const{
	return Position::compare(pos, rhs.pos) && Direction::compare(direct, rhs.direct);

}

bool Rover::changePosition(char action){
	return (action == 'f' || action == 'b' );
}

bool Rover::changeDirection(char action){
	return (action == 'l' || action == 'r');
}

void Rover::move(std::string commandSequence)
{
	for (int i=0; i<=commandSequence.length(); i++){
		doAction(commandSequence[i]);
	}
}

void Rover::doAction(char action){
	if (changePosition(action))
		cambiaPosicion(action);
	else if (changeDirection(action))
		cambiaDireccion(action);
}

Direction::~Direction(){}

Direction::Direction(std::string description) : description(description) {}

bool Direction::compare(Direction * lfs, Direction * rhs){
	return lfs->description == rhs->description;
}

string Direction::NORTH = "N";
string Direction::WEST = "W";
string Direction::EAST = "E";
string Direction::SOUTH = "S";

North::North() : Direction(Direction::NORTH) {}

Direction * North::girar (char cambio){

	Direction * dirnorth = NULL;

	if (cambio == 'r')
		dirnorth = new East();
	else
		dirnorth = new West();

	return dirnorth;

}

Position * North::moverAdelante(Position * pos){

	return new Position(pos->getX(), pos->getY() + 1);
}

Position * North::moverAtras(Position * pos){
	return new Position(pos->getX(), pos->getY() - 1);
}

East::East() : Direction(Direction::EAST) {}

Direction * East::girar (char cambio){
	Direction * dirnorth = NULL;

	if (cambio == 'r')
		dirnorth = new South();
	else
		dirnorth = new North();

	return dirnorth;
}

Position * East::moverAdelante(Position * pos){

	return new Position(pos->getX()+1, pos->getY());
}

Position * East::moverAtras(Position * pos){

	return new Position(pos->getX()-1, pos->getY());
}

West::West() : Direction(Direction::WEST) {}

Direction * West::girar (char cambio){
	Direction * dirnorth = NULL;

	if (cambio == 'r')
		dirnorth = new North();
	else
		dirnorth = new South();

	return dirnorth;

}

Position * West::moverAdelante(Position * pos){

	return new Position(pos->getX()-1, pos->getY());
}

Position * West::moverAtras(Position * pos){

	return new Position(pos->getX()+1, pos->getY());
}

South::South() : Direction(Direction::SOUTH) {}

Direction * South::girar (char cambio){

	Direction * dirnorth = NULL;

	if (cambio == 'r')
		dirnorth = new West();
	else
		dirnorth = new East();

	return dirnorth;

}

Position * South::moverAdelante(Position * pos){

	return new Position(pos->getX(), pos->getY() - 1);
}

Position * South::moverAtras(Position * pos){

	return new Position(pos->getX(), pos->getY() + 1);
}
