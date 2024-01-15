#include "Coalition.h"
#include "Simulation.h"

Coalition::Coalition(int mandatesSum, vector<int> parties) : 
cmandatesSum(mandatesSum), 
cparties(parties)
{}

int Coalition :: getCoaltionMandatesSum()
{
    return cmandatesSum;
}
vector<int> Coalition :: getVectorOfPartys()
{
    return cparties;
}

void Coalition :: addParty(int partyToAdd, int numOfMandates)
{
    cparties.push_back(partyToAdd);
    cmandatesSum = cmandatesSum + numOfMandates;
}

