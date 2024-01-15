#pragma once
#include <vector>
using std::vector;
#include "Coalition.h"
class JoinPolicy
{
public:
    virtual int join(int lastOffer, vector<Coalition> theCoalitons, vector<int> offers, vector<int> agentToOffer)=0;
    virtual JoinPolicy* copy()=0;
    virtual ~JoinPolicy()=default;
};
class MandatesJoinPolicy : public JoinPolicy

{
public:
    virtual int join(int lastOffer, vector<Coalition> theCoalitons, vector<int> offers, vector<int> agentToOffer);
    virtual MandatesJoinPolicy* copy();
    virtual ~MandatesJoinPolicy()=default;
};
class LastOfferJoinPolicy : public JoinPolicy
{
public:
    virtual int join(int lastOffer, vector<Coalition> theCoalitons, vector<int> offers, vector<int> agentToOffer);
    virtual LastOfferJoinPolicy* copy();
    virtual ~LastOfferJoinPolicy()=default;
};