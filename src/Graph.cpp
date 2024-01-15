#include "Graph.h"
#include <utility>

Graph *Graph::instance = nullptr;

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(std::move(vertices)),
                                                                  mEdges(std::move(edges)) {
    // You can change the implementation of the constructor, but not the signature!
    Graph::instance = this;
}

int Graph::getMandates(int partyId) const {
    return mVertices[partyId].getMandates();

}

vector<Party> Graph::getVertices() {
    return mVertices;
}

int Graph::getEdgeWeight(int v1, int v2) const {
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const {
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const {
    return mVertices[partyId];
}

Party &Graph::getPartyNonConst(int partyId) {
    return mVertices.at(partyId);
}


vector<int> Graph::getNeighbors(int mId) const {
    vector<int> neighbors;
    vector<int> hisEdges = this->mEdges[mId];
    for (unsigned int i = 0; i < hisEdges.size(); ++i) {
        if (hisEdges[i] >= 1)
            neighbors.push_back((int) i);
    }
    return neighbors;
}


