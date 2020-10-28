#ifndef IMATRIX_H
#define IMATRIX_H
#include <vector>


class IMatrix
{
public:
    IMatrix();
    virtual ~IMatrix();

    virtual int elementAt(unsigned int i, unsigned int j) const = 0;
    virtual std::vector<int> getRow(unsigned int i) const = 0;
    virtual void setSize(unsigned int i, unsigned int j) = 0;
    virtual bool addRow(std::vector<int> row) = 0;
    virtual bool setRow(std::vector<int> row, unsigned int i) = 0;
    virtual bool insertRow(std::vector<int> row, unsigned int i) = 0;
    virtual bool removeRow(unsigned int i) = 0;
    virtual bool removeColumn(int j) = 0;
    virtual bool setElement(int value, unsigned int i, unsigned int j) = 0;
    virtual unsigned int countElements() const = 0;
    virtual unsigned int rowCount() const = 0;
    virtual unsigned int columnCount() const = 0;
};

#endif // IMATRIX_H
