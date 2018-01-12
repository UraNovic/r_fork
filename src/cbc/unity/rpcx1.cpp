//------------------------------------------------------------------------------
/*
    This file is part of cbcd: https://github.com/cbc/cbcd
    Copyright (c) 2012, 2013 cbc Labs Inc.

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

#include <BeastConfig.h>

// This has to be included early to prevent an obscure MSVC compile error
#include <boost/asio/deadline_timer.hpp>

#include <cbc/protocol/JsonFields.h>
#include <cbc/rpc/RPCHandler.h>
#include <cbc/rpc/handlers/Handlers.h>

#include <cbc/rpc/handlers/AccountCurrenciesHandler.cpp>
#include <cbc/rpc/handlers/AccountInfo.cpp>
#include <cbc/rpc/handlers/AccountLines.cpp>
#include <cbc/rpc/handlers/AccountChannels.cpp>
#include <cbc/rpc/handlers/AccountObjects.cpp>
#include <cbc/rpc/handlers/AccountOffers.cpp>
#include <cbc/rpc/handlers/AccountTx.cpp>
#include <cbc/rpc/handlers/AccountTxOld.cpp>
#include <cbc/rpc/handlers/AccountTxSwitch.cpp>
#include <cbc/rpc/handlers/BlackList.cpp>
#include <cbc/rpc/handlers/BookOffers.cpp>
#include <cbc/rpc/handlers/CanDelete.cpp>
#include <cbc/rpc/handlers/Connect.cpp>
#include <cbc/rpc/handlers/ConsensusInfo.cpp>
#include <cbc/rpc/handlers/Feature1.cpp>
#include <cbc/rpc/handlers/Fee1.cpp>
#include <cbc/rpc/handlers/FetchInfo.cpp>
#include <cbc/rpc/handlers/GatewayBalances.cpp>
#include <cbc/rpc/handlers/GetCounts.cpp>
#include <cbc/rpc/handlers/LedgerHandler.cpp>
#include <cbc/rpc/handlers/LedgerAccept.cpp>
#include <cbc/rpc/handlers/LedgerCleanerHandler.cpp>
#include <cbc/rpc/handlers/LedgerClosed.cpp>
#include <cbc/rpc/handlers/LedgerCurrent.cpp>
#include <cbc/rpc/handlers/LedgerData.cpp>
#include <cbc/rpc/handlers/LedgerEntry.cpp>
#include <cbc/rpc/handlers/LedgerHeader.cpp>
#include <cbc/rpc/handlers/LedgerRequest.cpp>
#include <cbc/rpc/handlers/LogLevel.cpp>
#include <cbc/rpc/handlers/LogRotate.cpp>
#include <cbc/rpc/handlers/NocbcCheck.cpp>
#include <cbc/rpc/handlers/OwnerInfo.cpp>
