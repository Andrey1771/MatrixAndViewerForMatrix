#include "matrixmodel.h"

MatrixModel::MatrixModel(const Matrix &matrix, QObject *parent) : QAbstractItemModel(parent)
{
    this->matrix = matrix;
}


QModelIndex MatrixModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
        return QModelIndex();

    if(int(matrix.rowCount()) <= row || column > int(matrix.columnCount()))
        return QModelIndex();

    return createIndex(row,column);
}

QModelIndex MatrixModel::parent(const QModelIndex &/*child*/) const
{
    return {};
}

int MatrixModel::rowCount(const QModelIndex &/*parent*/) const
{
    return int(matrix.rowCount());
}

int MatrixModel::columnCount(const QModelIndex &/*parent*/) const
{
    return int(matrix.columnCount());
}

QVariant MatrixModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(index.row() > int(matrix.rowCount()))
        return QVariant();
    if(index.column() > int(matrix.columnCount())/*filtersMemoryMap.size()*/)
        return QVariant();

    if (role == Qt::TextAlignmentRole )
        return Qt::AlignCenter;
    if(role == Qt::DisplayRole)
    {
        return matrix.elementAt(unsigned(index.row()), unsigned(index.column()));
    }
    return {};
}
