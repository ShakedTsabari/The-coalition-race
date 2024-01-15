#include "../include/JoinPolicy.h"

int
MandatesJoinPolicy::join(int lastOffer, vector<Coalition> theCoalitons, vector<int> offers, vector<int> agentToOffer) {
    int max = 0;
    int agentId =-1;
        for (unsigned int i = 0; i < offers.size(); ++i) {
            int coNum = offers[i];
            Coalition c = theCoalitons[coNum];
            if (c.getCoaltionMandatesSum() > max) {
                max = c.getCoaltionMandatesSum();
                agentId = agentToOffer[i];
                } 
        }
    return agentId;
}


MandatesJoinPolicy *MandatesJoinPolicy::copy() {
    return new MandatesJoinPolicy();
}


int
LastOfferJoinPolicy::join(int lastOffer, vector<Coalition> theCoalitons, vector<int> offers, vector<int> agentToOffer) {
    return lastOffer;
};

LastOfferJoinPolicy *LastOfferJoinPolicy::copy() {
    return new LastOfferJoinPolicy();
}
