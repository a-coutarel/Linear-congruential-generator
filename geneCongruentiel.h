/*
* @File:    geneCongruentiel.h
* @Project: Générateur de nombres pseuso-aléatoires - Mathématiques ESIREM 3A IT
* @Author:  Allan Coutarel, Valentin Cheny, Guillaume Imhoff
*/

#ifndef _GENECONGRU_
#define _GENECONGRU_

#include <iostream>
#include <vector>

class GeneCongruentiel {

public:
    GeneCongruentiel(int seed, int a, int c, int m);
    int getA() const;
    int getC() const;
    int getM() const;
    int getSeed() const;
    int genNb();
    friend std::vector<int> makeSequence(GeneCongruentiel gene, int l);

private:
    int _seed;
    int _X;
    int _a;
    int _c;
    int _m;
};

std::vector<int> getStats(GeneCongruentiel gene);

#endif