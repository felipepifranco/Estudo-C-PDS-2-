#ifndef CAPYBARA_H
#define CAPYBARA_H

#include "Organism.hpp"

class Capybara : public Organism {
public:
    Capybara(int x, int y);

    char symbol() const override;
    bool isPreyFor(const Organism* predator) const override;

    void move(Grid& grid) override;
};

#endif