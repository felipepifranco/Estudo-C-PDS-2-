#include "c.pessoa.hpp"


Pessoa::Pessoa(double x, double y){
	this->x = x;
	this->y = y;
}

double Pessoa::getx(){
	return this->x;
}
double Pessoa::gety(){
	return this->y;
}

void Pessoa::mover(double dx, double dy){
	this->x += dx;
	this->y += dy;
}