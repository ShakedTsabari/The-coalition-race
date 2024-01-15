#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class JoinPolicy;
class Simulation;
enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<int> getOffer() const;
    void addOffer(int offer, int agentId);
    void setmTimer();
    void setLastOffer(int partyId);
    void cloneAgent(Simulation &sim, int agentId);
    JoinPolicy* copyJP() const;

    //added
    bool isWaitingOrCollectingOffers() const;

    //rule of 3
    Party (const Party& other);
    Party& operator=(const Party& other);
    ~Party();
    //rule of 5
    Party (Party&& other);
    Party& operator=(Party&& other);

    int getId() const;

private:
    JoinPolicy *mJoinPolicy;
    int mId;
    string mName;
    int mMandates;
    State mState;
    int mTimer;
    int LastOffer;
    vector<int> offers;
    vector<int> agentToOffer;

};
