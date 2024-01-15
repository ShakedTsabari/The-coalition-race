#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"
#include "JoinPolicy.h"
#include "SelectionPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
        mJoinPolicy(jp),
        mId(id),
        mName(name),
        mMandates(mandates),
        mState(Waiting),
        mTimer(0),
        LastOffer(-1),
        offers(vector<int>()),
        agentToOffer(vector<int>()) {
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const {
    return mState;
}

void Party::setState(State state) {
    mState = state;
}

int Party::getMandates() const {
    return mMandates;
}

const string &Party::getName() const {
    return mName;
}

void Party::cloneAgent(Simulation &sim, int agentId) {
    vector<Agent> agent = sim.getAgents();
    Agent a = agent.at(agentId);
    int agentCloneId = agent.size();
    int PartyCloneId = mId;
    SelectionPolicy *sp = a.getSPPointer()->copy();
    int cloneCoalition = a.getCoalition();
    Agent Clone = Agent(agentCloneId, PartyCloneId, sp);
    Clone.setCoalitionClone(cloneCoalition);
    agent.push_back(Clone);
}

void Party::step(Simulation &s) {
    // TODO: implement this method
    if (this->getState() == CollectingOffers) {
        ++mTimer;
        if (mTimer == 4) {
            vector<Coalition> theCoalitons = s.getVectorCoalition();
            int agentToJoin = mJoinPolicy->join(LastOffer, theCoalitons, offers, agentToOffer);
            // update relevent Coaltion (sum,add co)
            vector<Agent> agents = s.getAgents();
            Agent agi = agents[agentToJoin];
            s.cloneAgentSimulation(agentToJoin, mId);
            setState(Joined);
            int coNum = agi.getCoalition();
            s.addParty(coNum, mId);
        }
        }
}

vector<int> Party::getOffer() const { return offers; };

bool Party::isWaitingOrCollectingOffers() const {
    return this->mState == State::Waiting || this->mState == State::CollectingOffers;
}

void Party::addOffer(int offer, int agentId) {
    offers.push_back(offer);
    agentToOffer.push_back(agentId);
}

void Party::setmTimer() {
    ++mTimer;
}

void Party::setLastOffer(int partyId) {
    LastOffer = partyId;
}

JoinPolicy *Party::copyJP() const {
    return mJoinPolicy->copy();
}


// Copy Constructor
Party::Party(const Party &other) :
        mJoinPolicy(nullptr),
        mId(other.mId),
        mName(other.mName),
        mMandates(other.mMandates),
        mState(other.mState),
        mTimer(other.mTimer),
        LastOffer(other.LastOffer),
        offers(),
        agentToOffer() {
    for (unsigned int i = 0; i < other.offers.size(); ++i) {
        offers.push_back(other.offers[i]);
    }
    for (unsigned int i = 0; i < other.agentToOffer.size(); ++i) {
        agentToOffer.push_back(other.agentToOffer[i]);
    }
    mJoinPolicy = other.copyJP();
}


//Destructor
Party::~Party() {
    delete mJoinPolicy;
}

//Copy Assignment Operator
Party &Party::operator=(const Party &other) {
    if (this != &other) {
        delete mJoinPolicy;
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        mTimer = other.mTimer;
        LastOffer = other.LastOffer;
        mJoinPolicy = other.copyJP();
    }
    return *this;
}

//Move Constructor
Party::Party(Party &&other) :
        mJoinPolicy(other.mJoinPolicy),
        mId(other.mId),
        mName(std::move(other.mName)),
        mMandates(other.mMandates),
        mState(other.mState),
        mTimer(other.mTimer),
        LastOffer(other.LastOffer),
        offers(other.offers),
        agentToOffer(other.agentToOffer) {
    other.mJoinPolicy = nullptr;
}

//Move Assignment operator
Party &Party::operator=(Party &&other) {
    delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    mTimer = other.mTimer;
    LastOffer = other.LastOffer;
    other.mJoinPolicy = nullptr;
    return *this;
}

int Party::getId() const{
    return mId;
}
