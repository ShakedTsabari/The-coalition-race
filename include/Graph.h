#pragma once
#include <vector>
#include "Party.h"

using std::vector;
class Party;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    vector<Party> getVertices();
    const Party &getParty(int partyId) const;
    //added:
    vector<int> getNeighbors(int mId) const;
    static Graph* instance;

    Party &getPartyNonConst(int partyId);
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
