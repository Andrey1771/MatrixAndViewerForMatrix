#include "matrix.h"
#include <QDebug>

Matrix::Matrix() : IMatrix()
{

}

Matrix::Matrix(int filler, unsigned int n, unsigned int m, const std::vector<std::vector<int>>& rows)
{
    if(rows.size() == 0)
    {
        std::vector<int> row;
        row.insert(row.begin(), m, filler);
        dataMatrix.insert(dataMatrix.begin(), n, row);
    }
    else
    {
        assignRows(rows);
    }
    fillerNum = filler;
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

std::vector<std::vector<int>> Matrix::getRows() const
{
    return dataMatrix;
}

void Matrix::setSize(unsigned int i, unsigned int j)
{
    //TODO
}

void Matrix::assignRows(const std::vector<std::vector<int>>& rows)
{
    dataMatrix.clear();
    size_t newColumnCount = 0;
    for(auto row : rows)
    {
        if(row.size() > newColumnCount)
            newColumnCount = row.size();
    }
    for(std::size_t i = 0; i < rows.size(); ++i)
    {
        if(newColumnCount - rows[i].size() != 0)
        {
            std::vector<int> temp = rows[i];
            fillrow(temp, newColumnCount);
            dataMatrix.push_back(temp);
        }
        else
            dataMatrix.push_back(rows[i]);

    }

}

bool Matrix::addRow(const std::vector<int> &row)
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
            auto temp = row;
            bool ok = fillrow(temp, columnCount());
            dataMatrix.push_back(temp);
            return ok;
        }
    }
    return true;
}

bool Matrix::fillrow(std::vector<int> &row, size_t columnCount)
{
    int size = columnCount - row.size();
    if(size > 0)
    {
        row.insert(row.end(), size, fillerNum);
        return true;
    }
    return false;
}

bool Matrix::setRow(const std::vector<int> &row, unsigned int i)
{
    if(rowCount() <= i)
        return false;

    dataMatrix[i] = row;
    return true;
}

bool Matrix::insertRow(const std::vector<int> &row, unsigned int i)
{
    std::vector<std::vector<int>> temp;
    temp.push_back(row);
    return insertRows(temp, i);//Может стоит отказать от такой реализации, если будем работотать с очень большими значениями, но мне не надо
}

bool Matrix::insertRows(const std::vector<std::vector<int>> &rows, unsigned int i)
{
    if(rowCount() < i)
        return false;

    auto iterDataMatrix = dataMatrix.begin() + int(i);
    for(auto row : rows)
    {
        auto temp = row;
        fillrow(temp, columnCount());
        dataMatrix.insert(iterDataMatrix, row);
    }
    return true;
}


bool Matrix::removeRow(unsigned int i)
{
    return removeRows(i, 1);
}

bool Matrix::removeRows(unsigned int i, unsigned int count)
{
    if(rowCount() < i + count)
        return false;

    auto iterDataMatrix = dataMatrix.begin() + int(i);
    dataMatrix.erase(iterDataMatrix, iterDataMatrix + count);
    return true;
}

bool Matrix::removeColumn(unsigned int j)
{
    return removeColumns(j, 1);
}

bool Matrix::removeColumns(unsigned int j, unsigned int count)
{
    if(columnCount() < j + count)
        return false;

    for(uint i = 0; i < rowCount(); ++i)
    {
        auto iter = dataMatrix[i].begin() + j;
        dataMatrix[i].erase(iter, iter + count);
    }
    return true;
}


bool Matrix::setElement(int value, unsigned int i, unsigned int j)
{
    dataMatrix[i][j] = value;
    return true;
}

bool Matrix::setMatrix(const IMatrix &matrix, unsigned int i, unsigned int j)//Проверить
{
    if(matrix.columnCount() + j > columnCount() || matrix.rowCount() + i > rowCount())
    {
        return false;
    }

    auto tempData = matrix.getRows();
    for(uint numRow = i; numRow < i + matrix.rowCount(); ++numRow)
    {
        for(uint numCol = j; numCol < j + matrix.columnCount(); ++numCol)
        {
            dataMatrix[numRow][numCol] = tempData[numRow - i][numCol - j];
        }
    }
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

int Matrix::getFillerNum() const
{
    return fillerNum;
}

void Matrix::setFillerNum(int value)
{
    fillerNum = value;
}
