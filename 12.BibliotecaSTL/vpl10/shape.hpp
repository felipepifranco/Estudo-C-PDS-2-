#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>

/**
 * Classe original abstrata que representa uma forma geométrica.
 * Define a interface comum para todas as formas derivadas.
 */
class Shape {
public:
    virtual ~Shape() = default;

    /**
     * Retorna o nome da forma (ex: "Circulo", "Retangulo", "Triangulo").
     */
    virtual std::string name() const = 0;

    /**
     * Calcula a area da forma.
     */
    virtual double area() const = 0;

    /**
     * Operador de saída já implementado (friend).
     * Uma função friend é uma função de fora da classe, mas que pode acessar membros privados
     */
    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        os << s.name() << " com area " << s.area();
        return os;
    }
};

#endif // SHAPE_HPP