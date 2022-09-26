/*
* @File:    superGeneCongruentiel.h
* @Project: Générateur de nombres pseuso-aléatoires - Mathématiques ESIREM 3A IT
* @Author:  Allan Coutarel, Valentin Cheny, Guillaume Imhoff
*/

#ifndef _SUPGENECONGRU_
#define _SUPGENECONGRU_

#include <iostream>
#include <vector>
#include "geneCongruentiel.h"

class SuperGeneCongruentiel {
    public:
        SuperGeneCongruentiel(GeneCongruentiel geneChoix);
        GeneCongruentiel getGeneChoix() const;
        void addGene(GeneCongruentiel nouveauGene);
        GeneCongruentiel getGene(int n) const;
        int genNb();
        friend std::vector<int> makeSequence(SuperGeneCongruentiel gene, int l);

    private:
        GeneCongruentiel _geneChoix;
        std::vector<GeneCongruentiel> _listGene;
    };

void periodeSGC(SuperGeneCongruentiel gene, int p_max);

#endif
