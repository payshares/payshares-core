#pragma once

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "TxSetFrame.h"
#include "overlay/PaysharesXDR.h"
#include <string>

namespace payshares
{

/**
 * Helper class that describes a single ledger-to-close -- a set of transactions
 * and auxiliary values -- as decided by the Herder (and ultimately: SCP). This
 * does not include the effects of _performing_ any transactions, merely the
 * values that the network has agreed _to apply_ to the current ledger,
 * atomically, in order to produce the next ledger.
 */
class LedgerCloseData
{
  public:
    LedgerCloseData(uint32_t ledgerSeq, TxSetFramePtr txSet,
                    PaysharesValue const& v);

    uint32_t
    getLedgerSeq() const
    {
        return mLedgerSeq;
    }
    TxSetFramePtr
    getTxSet() const
    {
        return mTxSet;
    }
    PaysharesValue const&
    getValue() const
    {
        return mValue;
    }

  private:
    uint32_t mLedgerSeq;
    TxSetFramePtr mTxSet;
    PaysharesValue mValue;
};

std::string paysharesValueToString(PaysharesValue const& sv);

#define emptyUpgradeSteps (xdr::xvector<UpgradeType, 6>(0))
}
