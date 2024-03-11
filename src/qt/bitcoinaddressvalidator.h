// Copyright (c) 2011-2020 The Mateable Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MATEABLE_QT_MATEABLEADDRESSVALIDATOR_H
#define MATEABLE_QT_MATEABLEADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MateableAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MateableAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Mateable address widget validator, checks for a valid bitcoin address.
 */
class MateableAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MateableAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // MATEABLE_QT_MATEABLEADDRESSVALIDATOR_H
