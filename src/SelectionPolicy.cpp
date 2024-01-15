#include <vector>
#include "../include/SelectionPolicy.h"
#include "../include/Graph.h"
#include "../include/Simulation.h"
#include "../include/Party.h"
#include "../include/Agent.h"


int MandatesSelectionPolicy::select(Simulation &sim, vector<int> neighbors, int partyId) {
    int max = 0;
    int partyid = -1;
    const Graph &g = sim.getGraph();
    if (!neighbors.empty()){
        for (int a: neighbors) {
            const Party &p = g.getParty(a);
            int mandat = p.getMandates();
            if (mandat > max) {
                max = mandat;
                partyid = a;
        }
    }
    }
    return partyid;
}

SelectionPolicy *MandatesSelectionPolicy::copy()  {
    return new MandatesSelectionPolicy;
}


int EdgeWeightSelectionPolicy::select(Simulation &sim, vector<int> neighbors, int partyId) {
    int max = 0;
    int pId = -1;
    const Graph &g = sim.getGraph();
    if (!neighbors.empty()){
        for (int p: neighbors) {
            if (g.getEdgeWeight(p, partyId) > max) {
                max = g.getEdgeWeight(p, partyId);
                pId = p;
        }
    }
    }
    return pId;
}

SelectionPolicy *EdgeWeightSelectionPolicy::copy() {
    return new EdgeWeightSelectionPolicy;
}
