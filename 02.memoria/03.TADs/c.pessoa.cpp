#include "c.pessoa.hpp"


Pessoa::Pessoa(double x, double y){
	this->x = x;
	this->y = y;
}

double Pessoa::getX(){
	return this->x;
}
double Pessoa::getY(){
	return this->y;
}

void Pessoa::mover(double dx, double dy){
	this->x += dx;
	this->y += dy;
}