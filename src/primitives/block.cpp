// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Mateable Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

#include <hash.h>
#include <multialgo.h>
#include <tinyformat.h>

void CBlockHeader::SetAlgo(int algo)
{
    nVersion |= GetVersionForAlgo(algo);
}

uint256 CBlockHeader::GetHash() const
{
    return SerializeHash(*this);
}

uint256 CBlockHeader::GetPoWHash() const
{
    const int algo = GetAlgo(nVersion);

    switch (algo) {
        case ALGO_SCRYPT:
            return scrypt_1024_1_1_256(*this);
        case ALGO_YESCRYPT:
            return yescrypt(*this);
        case ALGO_WHIRLPOOL:
            return whirlpool(*this);
        case ALGO_GHOSTRIDER:
            return ghostrider(*this);
        case ALGO_BALLOON:
            return balloon(*this);
        case ALGO_UNKNOWN:
            return ArithToUint256(~arith_uint256(0));
    }
    assert(false);
    return GetHash();
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u, vchBlockSig=%s)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size(),
        HexStr(vchBlockSig));
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
