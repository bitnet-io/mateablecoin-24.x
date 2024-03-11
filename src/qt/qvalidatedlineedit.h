// Copyright (c) 2011-2020 The Mateable Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MATEABLE_QT_QVALIDATEDLINEEDIT_H
#define MATEABLE_QT_QVALIDATEDLINEEDIT_H

#include <QLineEdit>

/** Line edit that can be marked as "invalid" to show input validation feedback. When marked as invalid,
   it will get a red background until it is focused.
 */
class QValidatedLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit QValidatedLineEdit(QWidget *parent);
    void clear();
    void setCheckValidator(const QValidator *v);
    bool isValid();

protected:
    void focusInEvent(QFocusEvent *evt) override;
    void focusOutEvent(QFocusEvent *evt) override;

private:
    bool valid;
    const QValidator *checkValidator;

public Q_SLOTS:
    void setText(const QString&);
    void setValid(bool valid);
    void setEnabled(bool enabled);

Q_SIGNALS:
    void validationDidChange(QValidatedLineEdit *validatedLineEdit);

private Q_SLOTS:
    void markValid();
    void checkValidity();
};

#endif // MATEABLE_QT_QVALIDATEDLINEEDIT_H
