#ifndef MATRIX_H
#define MATRIX_H
#include "imatrix.h"

class Matrix : public IMatrix
{
    std::vector<std::vector<int>> dataMatrix;
 public:
     Matrix();
     ~Matrix() override;
     // IMatrix interface
public:
     virtual int elementAt(unsigned int i, unsigned int j) const override;
     virtual std::vector<int> getRow(unsigned int i) const override;
     virtual void setSize(unsigned int i, unsigned int j) override;
     virtual bool addRow(std::vector<int> row) override;
     virtual bool setRow(std::vector<int> row, unsigned int i) override;
     virtual bool insertRow(std::vector<int> row, unsigned int i) override;
     virtual bool removeRow(unsigned int i) override;
     virtual bool removeColumn(int j) override;
     virtual bool setElement(int value, unsigned int i, unsigned int j) override;
     virtual unsigned int countElements() const override;
     virtual unsigned int rowCount() const override;
     virtual unsigned int columnCount() const override;
};

#endif // MATRIX_H
