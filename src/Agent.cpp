#include "Agent.h"
#include <vector>
#include "Graph.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#include "Party.h"

class Graph;

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
        mAgentId(agentId),
        mPartyId(partyId),
        mSelectionPolicy(selectionPolicy),
        mCoalition(agentId) {
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const {
    return mAgentId;
}

int Agent::getPartyId() const {
    return mPartyId;
}

void Agent::setCoalition(int agentId) {
    mCoalition = agentId;
}

void Agent::setCoalitionClone(int coalition) {
    mCoalition = coalition;
}

void Agent::step(Simulation &sim) {
    // TODO: implement this method
    int partyId = getPartyId();
    Graph& g = sim.getGraphNonConst();
    vector<int> agentAllNeighbors = g.getNeighbors(partyId);
    vector<int> agentFinalNeighbhors;
    // parties that satisfy conditions
    for (int pNeighbor: agentAllNeighbors) {
        int p = g.getParty(pNeighbor).getId();
        if (sim.getPartyNonConst(p).isWaitingOrCollectingOffers())
            agentFinalNeighbhors.push_back(pNeighbor);
    }
    vector<int> legalNeighbors;
    for (int PartyId: agentFinalNeighbhors) {
        vector<int> offer = sim.getPartyNonConst(PartyId).getOffer();
        bool flag = true;
        if (offer.empty())
            legalNeighbors.push_back(sim.getPartyNonConst(PartyId).getId());
        else {
            for (int a: offer) {
                if (a == mCoalition)
                    flag = false;
            }
            if (flag)
                legalNeighbors.push_back(sim.getPartyNonConst(PartyId).getId()); 
        }       
    }
    int partyToSelect = mSelectionPolicy->select(sim, legalNeighbors, mPartyId);
    if (partyToSelect != -1) //else agent is idle
    {
        Party& p = g.getPartyNonConst(partyToSelect);

        p.addOffer(mCoalition, mAgentId);
        p.setLastOffer(mAgentId);

        if (p.getState() == Waiting) {
            p.setState(CollectingOffers);
            p.setmTimer();
        }
    }
}

SelectionPolicy *Agent::getSPPointer() {
    return mSelectionPolicy;
}


int Agent::getCoalition() {
    return mCoalition;
}


// Copy Constructor
Agent::Agent(const Agent &other) :
        mAgentId(other.mAgentId),
        mPartyId(other.mPartyId),
        mSelectionPolicy(nullptr),
        mCoalition(other.mCoalition) {
           mSelectionPolicy = other.mSelectionPolicy->copy();
}


// Destructor
Agent::~Agent() {
    if (mSelectionPolicy)
        delete mSelectionPolicy;
}

// Copy Assignment Operator
Agent &Agent::operator=(const Agent &other) {
    if (this != &other) {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->copy();
        mCoalition = other.mCoalition;
    }
    return *this;
}

// Move Constructor
Agent::Agent(Agent &&other) :
        mAgentId(other.mAgentId),
        mPartyId(other.mPartyId),
        mSelectionPolicy(other.mSelectionPolicy),
        mCoalition(other.mCoalition) {
    other.mSelectionPolicy = nullptr;
}

// Move Assignment Operator
Agent &Agent::operator=(Agent &&other) {
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    mCoalition = mCoalition;
    return *this;
}