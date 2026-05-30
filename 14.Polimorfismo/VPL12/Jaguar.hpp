#ifndef JAGUAR_H
#define JAGUAR_H

#include "Organism.hpp"

class Jaguar : public Organism {
public:
    Jaguar(int x, int y);

    char symbol() const override;
    bool tryPredation(Grid& grid) override;
    void move(Grid& grid) override;
};

#endif