//------------------------------------------------------------------------------
/*
    This file is part of cbcd: https://github.com/cbc/cbcd
    Copyright (c) 2014 cbc Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef cbc_TX_SETSIGNERLIST_H_INCLUDED
#define cbc_TX_SETSIGNERLIST_H_INCLUDED

#include <cbc/app/ledger/Ledger.h>
#include <cbc/app/tx/impl/Transactor.h>
#include <cbc/app/tx/impl/SignerEntries.h>
#include <cbc/protocol/STObject.h>
#include <cbc/protocol/STArray.h>
#include <cbc/protocol/STTx.h>
#include <cbc/protocol/Indexes.h>
#include <cbc/basics/Log.h>
#include <algorithm>
#include <cstdint>
#include <vector>

namespace cbc {

/**
See the README.md for an overview of the SetSignerList transaction that
this class implements.
*/
class SetSignerList : public Transactor
{
private:
    // Values determined during preCompute for use later.
    enum Operation {unknown, set, destroy};
    Operation do_ {unknown};
    std::uint32_t quorum_ {0};
    std::vector<SignerEntries::SignerEntry> signers_;

public:
    SetSignerList (ApplyContext& ctx)
        : Transactor(ctx)
    {
    }

    static
    bool
    affectsSubsequentTransactionAuth(STTx const& tx)
    {
        return true;
    }

    static
    TER
    preflight (PreflightContext const& ctx);

    TER doApply () override;
    void preCompute() override;

private:
    static
    std::tuple<TER, std::uint32_t,
        std::vector<SignerEntries::SignerEntry>,
            Operation>
    determineOperation(STTx const& tx,
        ApplyFlags flags, beast::Journal j);

    static
    TER validateQuorumAndSignerEntries (
        std::uint32_t quorum,
            std::vector<SignerEntries::SignerEntry> const& signers,
                AccountID const& account,
                    beast::Journal j);

    TER replaceSignerList ();
    TER destroySignerList ();

    TER removeSignersFromLedger (Keylet const& accountKeylet,
        Keylet const& ownerDirKeylet, Keylet const& signerListKeylet);
    void writeSignersToSLE (SLE::pointer const& ledgerEntry) const;

    static int ownerCountDelta (std::size_t entryCount);
};

} // cbc

#endif
