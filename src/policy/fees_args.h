// Copyright (c) 2022 The Mateable Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MATEABLE_POLICY_FEES_ARGS_H
#define MATEABLE_POLICY_FEES_ARGS_H

#include <fs.h>

class ArgsManager;

/** @return The fee estimates data file path. */
fs::path FeeestPath(const ArgsManager& argsman);

#endif // MATEABLE_POLICY_FEES_ARGS_H
