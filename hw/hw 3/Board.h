#include <string> 
#include <iostream>

class Board {
public: 
    Board(const std::string &p1, const std::string &p2, const std::string &empty); 

    std::string insert(int col , bool status);
    const std::string& strAt(int row, int col) const;
    int numTokensInColumn(int colNum) const; 
    int numTokensInRow(int rowNum) const; 
    int numRows() const;
    int numColumns() const; 
    bool match(int row, int col);
    void clear(); 

private: 
    std::string** m_data; 
    std::string p1str; 
    std::string p2str; 
    std::string emptystr; 
    int nRows;
    int nCols; 

};

std::ostream& operator<< (std::ostream &stream, const Board& b); 
