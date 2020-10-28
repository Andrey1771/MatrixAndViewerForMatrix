#include "matrix.h"
#include <QDebug>
Matrix::Matrix() : IMatrix()
{

}

Matrix::~Matrix()
{
    qDebug() << "DESTRUCTOR";
}

int Matrix::elementAt(unsigned int i, unsigned int j) const
{
    return dataMatrix.at(i).at(j);
}

std::vector<int> Matrix::getRow(unsigned int i) const
{
    return dataMatrix.at(i);
}

void Matrix::setSize(unsigned int i, unsigned int j)
{
    //TODO
}

bool Matrix::addRow(std::vector<int> row)
{
    if(columnCount() == 0)
    {
        dataMatrix.push_back(row);
    }
    else
    {
        if(columnCount() == row.size())
        {
            dataMatrix.push_back(row);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Matrix::setRow(std::vector<int> row, unsigned int i)
{
    if(rowCount() <= i)
        return false;

    dataMatrix[i] = row;
    return true;
}

bool Matrix::insertRow(std::vector<int> row, unsigned int i)
{
    if(rowCount() < i)
        return false;

    auto iterDataMatrix = dataMatrix.begin() + int(i);
    dataMatrix.insert(iterDataMatrix, row);
    return true;
}

bool Matrix::removeRow(unsigned int i)
{
    if(rowCount() <= i)
        return false;

    auto iterDataMatrix = dataMatrix.begin() + int(i);
    dataMatrix.erase(iterDataMatrix);//Проверить
    return true;
}

bool Matrix::removeColumn(int j)
{
    //TODO
}

bool Matrix::setElement(int value, unsigned int i, unsigned int j)
{
    //TODO
}

unsigned int Matrix::countElements() const
{
    return rowCount() * columnCount();
}

unsigned int Matrix::rowCount() const
{
    return dataMatrix.size();
}

unsigned int Matrix::columnCount() const
{
    if(dataMatrix.size() > 0)
    {
        return dataMatrix.at(0).size();
    }
    else
    {
        return 0;
    }
}

