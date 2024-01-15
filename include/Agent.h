#pragma once
#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    SelectionPolicy* getSPPointer();
    int getCoalition();
    void setCoalitionClone(int coalition);
    void setCoalition(int agentId);

    //rule of 3
    Agent (const Agent& other);
    Agent& operator=(const Agent& other);
    ~Agent();
    //rule of 5
    Agent (Agent&& other);
    Agent& operator=(Agent&& other);
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalition;
};
