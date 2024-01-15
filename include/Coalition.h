#pragma once
#include <vector>

using std::vector;

class Coalition 
{
public:
    Coalition(int mandatesSum, vector<int> parties);
    int getCoaltionMandatesSum();
    vector<int> getVectorOfPartys();
    void addParty(int partyToAdd,int numOfMandates);
private:
    int cmandatesSum;
    vector<int> cparties;
};


