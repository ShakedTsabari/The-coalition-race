#pragma once
#include <vector>
using std::vector;
#include "Simulation.h"

class SelectionPolicy
{
public:
    virtual int select(Simulation &sim, vector<int> neighbors, int partyId) = 0;
    virtual SelectionPolicy* copy() = 0;
    // Destructor
    virtual ~SelectionPolicy()=default;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
public:
    virtual int select(Simulation &sim, vector<int> neighbors, int partyId);
    virtual SelectionPolicy* copy() ;
    // Destructor
    virtual ~MandatesSelectionPolicy()=default;


};

class EdgeWeightSelectionPolicy : public SelectionPolicy
{
public:
    virtual int select(Simulation &sim, vector<int> neighbors, int partyId);
    virtual SelectionPolicy* copy() ;
    // Destructor
    virtual ~EdgeWeightSelectionPolicy()=default;
};