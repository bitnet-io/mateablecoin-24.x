// Copyright (c) 2022 The Mateable Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MATEABLE_NODE_MEMPOOL_PERSIST_ARGS_H
#define MATEABLE_NODE_MEMPOOL_PERSIST_ARGS_H

#include <fs.h>

class ArgsManager;

namespace node {

/**
 * Default for -persistmempool, indicating whether the node should attempt to
 * automatically load the mempool on start and save to disk on shutdown
 */
static constexpr bool DEFAULT_PERSIST_MEMPOOL{true};

bool ShouldPersistMempool(const ArgsManager& argsman);
fs::path MempoolPath(const ArgsManager& argsman);

} // namespace node

#endif // MATEABLE_NODE_MEMPOOL_PERSIST_ARGS_H
