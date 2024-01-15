#include <iostream>
#include "Simulation.h"
#include "Coalition.h"
#include "SelectionPolicy.h"


Simulation::Simulation(Graph graph, vector<Agent> agents) :
        mGraph(graph),
        mAgents(agents),
        mtheCoalitions(vector<Coalition>()) {
    // You can change the implementation of the constructor, but not the signature!
    for (Agent &agent: agents) {
        int partyToJoin = agent.getPartyId();
        Party &party = graph.getPartyNonConst(partyToJoin);
        party.setState(Joined);
        vector<int> partiesOfCoalition;
        partiesOfCoalition.push_back(partyToJoin);
        int numOfMandates = party.getMandates();
        Coalition c = Coalition(numOfMandates, partiesOfCoalition);
        mtheCoalitions.push_back(c);
    }
}

void Simulation::step() {

    // TODO: implement this methodSimulation
    for (int i = 0; i < mGraph.getNumVertices(); ++i) {
        Party &party = mGraph.getPartyNonConst(i);
        party.step(*this);
    }
    for (unsigned int i = 0; i < mAgents.size(); ++i) {
        Agent agent = mAgents[i];
        agent.step(*this);
    }
}

vector<Coalition> Simulation::getVectorCoalition() {
    return mtheCoalitions;
}

void Simulation::addParty(int coalitionNumber, int partyId) {
    Coalition& c = mtheCoalitions[coalitionNumber];
    int numOfMandatsToAdd = getParty(partyId).getMandates();
    c.addParty(partyId, numOfMandatsToAdd);
}

bool Simulation::shouldTerminate() const {
    for (Coalition c: mtheCoalitions) {
        if (c.getCoaltionMandatesSum() >= 61)
            return true;
    }
    Graph g = getGraph();
    vector<Party> VP = g.getVertices();
    for (Party p: VP) {
        if (p.getState() != Joined)
            return false;
    }
    return true;
}

const Graph &Simulation::getGraph() const {
    return mGraph;
}

Graph &Simulation::getGraphNonConst() {
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const {
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const {
    return mGraph.getParty(partyId);
}

Party Simulation::getPartyNonConst(int partyId) {
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const {
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> coaltionsToSubmit;
    for (Coalition c: mtheCoalitions) {
        vector<int> toPush = c.getVectorOfPartys();
        coaltionsToSubmit.push_back(toPush);
    }
    return coaltionsToSubmit;
    // return vector<vector<int>>();

}
void Simulation :: cloneAgentSimulation(int agentId, int mid)
{
    Agent a = mAgents[agentId];
    SelectionPolicy *sp = a.getSPPointer()->copy();
    int cloneCoalition = a.getCoalition();
    Agent Clone = Agent(mAgents.size(), mid, sp);
    Clone.setCoalitionClone(cloneCoalition);
    mAgents.push_back(Clone);
}
