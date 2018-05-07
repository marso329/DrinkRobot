#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QStyledItemDelegate>
#include<QStandardItemModel>

class ComboBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ComboBoxItemDelegate(QObject* parent=0);
    ComboBoxItemDelegate(std::vector<std::string>,QStandardItemModel* model);
    ~ComboBoxItemDelegate();

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;
    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
private:
    std::vector<std::string> ingredients;
    QStandardItemModel* data_model;


protected:
Q_SIGNALS:
void drinkDataChanged(const QModelIndex &topLeft,
		const QModelIndex &bottomRight);
};

#endif // ITEMDELEGATE_H
