#ifndef ORGANISM_H
#define ORGANISM_H

class Grid;

class Organism {
protected:
    int x, y;
    bool moved;

public:
    Organism(int x, int y); 
    virtual ~Organism(); 

    virtual char symbol() const = 0;
    virtual void move(Grid& grid) = 0;
    bool tryMoveToEmpty(Grid& grid);

    virtual bool tryPredation(Grid& grid);
    virtual bool isPreyFor(const Organism* predator) const;

    void setMoved(bool m);
    bool hasMoved() const;

    int getX() const;
    int getY() const;
    void setPosition(int nx, int ny);

    void deslocar(Grid& grid, int x, int y);

};

#endif