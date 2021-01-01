#ifndef MATRIX_H
#define MATRIX_H
#include "imatrix.h"

class Matrix : public IMatrix
{
    std::vector<std::vector<int>> dataMatrix;
    int fillerNum = 0;
public:
    Matrix();
    Matrix(int filler, unsigned int n, unsigned int m, const std::vector<std::vector<int>>& rows = {});
    ~Matrix() override;
    // IMatrix interface
public:
    virtual int elementAt(unsigned int i, unsigned int j) const override;
    virtual std::vector<int> getRow(unsigned int i) const override;
    virtual std::vector<std::vector<int>> getRows() const override;
    virtual void setSize(unsigned int i, unsigned int j) override;
    virtual void assignRows(const std::vector<std::vector<int>>& rows) override;
    virtual bool addRow(const std::vector<int>& row) override;
    virtual bool setRow(const std::vector<int>& row, unsigned int i) override;
    virtual bool insertRow(const std::vector<int>& row, unsigned int i) override;
    virtual bool insertRows(const std::vector<std::vector<int>> &rows, unsigned int i) override;
    virtual bool removeRow(unsigned int i) override;
    virtual bool removeRows(unsigned int i, unsigned int count) override;
    virtual bool removeColumn(unsigned int j) override;
    virtual bool removeColumns(unsigned int j, unsigned int count) override;
    virtual bool setElement(int value, unsigned int i, unsigned int j) override;
    virtual bool setMatrix(const IMatrix &matrix, unsigned int i, unsigned int j) override;
    virtual unsigned int countElements() const override;
    virtual unsigned int rowCount() const override;
    virtual unsigned int columnCount() const override;

    int getFillerNum() const;
    void setFillerNum(int value);

private:
    bool fillrow(std::vector<int> &row, size_t columnCount);
};

#endif // MATRIX_H
