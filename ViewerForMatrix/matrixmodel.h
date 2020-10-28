#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H

#include <QAbstractItemModel>
#include <matrix.h>

class MatrixModel : public QAbstractItemModel
{
    Matrix matrix;
public:
    MatrixModel(const Matrix& matrix, QObject* parent);

    // QAbstractItemModel interface
public:
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual QModelIndex parent(const QModelIndex &child) const override;
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
};

#endif // MATRIXMODEL_H
