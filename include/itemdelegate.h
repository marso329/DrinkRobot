#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QStyledItemDelegate>

class ComboBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ComboBoxItemDelegate(QObject* parent=0);
    ~ComboBoxItemDelegate();

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;
    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
};

#endif // ITEMDELEGATE_H
