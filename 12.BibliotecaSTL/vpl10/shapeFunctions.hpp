#ifndef SHAPE_FUNCTIONS_HPP
#define SHAPE_FUNCTIONS_HPP

#include "shape.hpp"
#include <vector>
#include <map>
#include <set>
#include <list>

class ShapeFunctions {
public:
    // 1. Imprime todas as formas usando std::for_each
    static void printShapes(const std::vector<Shape*>& shapes);

    // 2. Calcula a área total usando std::accumulate
    static double totalArea(const std::vector<Shape*>& shapes);

    // 3. Retorna um novo vector com formas de área > minArea (std::copy_if)
    static std::vector<Shape*> getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea);

    // 4. Ordena o vector in-place por área crescente (std::sort)
    static void sortShapesByArea(std::vector<Shape*>& shapes);

    // 5. Conta quantas formas de cada nome existem (std::map)
    static std::map<std::string, int> countShapesByName(const std::vector<Shape*>& shapes);

    // 6. Extrai áreas únicas e ordenadas (std::set)
    static std::set<double> uniqueAreas(const std::vector<Shape*>& shapes);

    // 7. Verifica se o ambiente é trafegável, considerando a area total do ambiente
    //     e uma tolerância de segurança. A area livre é calculada como:
    //     area_livre = area_ambiente - soma_das_areas_dos_obstaculos.
    //     O ambiente é trafegável se area_livre > tolerancia.
    //     Imprime uma das seguintes mensagens:
    //     - "Ambiente trafegavel. Area livre: X.XX" (se trafegável)
    //     - "Ambiente nao trafegavel. Area livre insuficiente: X.XX" (caso contrário)
    static void verificarTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia);
};

#endif // SHAPE_FUNCTIONS_HPP