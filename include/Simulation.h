#pragma once

#include <string>
#include <vector>
#include "Party.h"
#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation {
public:
    Simulation(Graph, vector<Agent>);

    void step();

    bool shouldTerminate() const;

    const Graph &getGraph() const;

    Graph &getGraphNonConst();

    const vector<Agent> &getAgents() const;

    const Party &getParty(int partyId) const;

    Party getPartyNonConst(int partyId);

    const vector<vector<int>> getPartiesByCoalitions() const;

    vector<Coalition> getVectorCoalition();

    void addParty(int coalitionNumber, int partyId);

    void cloneAgentSimulation(int agentId, int mid);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mtheCoalitions;
};
