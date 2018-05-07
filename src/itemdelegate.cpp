#include "itemdelegate.h"
#include <QComboBox>
#include <iostream>

ComboBoxItemDelegate::ComboBoxItemDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
	data_model=0;
}

ComboBoxItemDelegate::ComboBoxItemDelegate(std::vector<std::string> ingredients,
		QStandardItemModel* model): QStyledItemDelegate(0),ingredients(ingredients),data_model(model)
	{

}

ComboBoxItemDelegate::~ComboBoxItemDelegate()
{
}


QWidget* ComboBoxItemDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	(void)option;
	(void)index;
    // Create the combobox and populate it
    QComboBox* cb = new QComboBox(parent);
    for(auto it=ingredients.begin();it!=ingredients.end();it++){
    	cb->addItem(QString::fromStdString(*it));
    }
    return cb;
}


void ComboBoxItemDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    if (QComboBox* cb = qobject_cast<QComboBox*>(editor)) {
       // get the index of the text in the combobox that matches the current value of the itenm
       QString currentText = index.data(Qt::EditRole).toString();
       int cbIndex = cb->findText(currentText);
       // if it is valid, adjust the combobox
       if (cbIndex >= 0){
           cb->setCurrentIndex(cbIndex);
       }
       //data_model->setItem(index.row(), index.column(), new QStandardItem(currentText));


    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}


void ComboBoxItemDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    if (QComboBox* cb = qobject_cast<QComboBox*>(editor)){
        // save the current text of the combo box as the current value of the item
       if( model->setData(index, cb->currentText(), Qt::EditRole)){
    	   std::cout<<"row "<<index.row()<<"col "<<index.column()<<std::endl;
       }
    }
    else{
    	std::cout<<"data changed 22"<<std::endl;
        QStyledItemDelegate::setModelData(editor, model, index);
    }
    }
