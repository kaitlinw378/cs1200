#include "Board.h" 

Board::Board(const std::string &p1, const std::string &p2, const std::string &empty)
{

    p1str = p1; 
    p2str = p2; 
    emptystr = empty;
    nRows = 5;
    nCols = 4;
    m_data = new std::string *[nRows]; 
    for (int i = 0; i < nRows; ++i){
        m_data[i] = new std::string[nCols]; 
        for (int j = 0; j < nCols; ++j){
            m_data[i][j] = emptystr; 
         }
    }

}

std::string Board::insert(int col, bool status)
{
    //std::cout <<col << status <<"\n";
    std::string tempstr;
    if (status){
        tempstr = p1str;
    }
    else{
        tempstr = p2str; 
    }
    if (nCols > col){
        //std::cout<<"a"<<std::endl;
        for (int i =0; i < nRows; ++i){
            if (m_data[i][col] == emptystr){ 
                m_data[i][col] = tempstr;
                if (match(i, col)){
                    return m_data[i][col]; 
                }
                else{
                    return emptystr; 
                }
            }
        }
        //std::cout<<"b"<<std::endl;
        std::string** old = m_data; 
        m_data = new std::string*[++nRows]; 
        for (int i = 0; i < nRows -1; ++i){
            m_data[i] = old[i];
        }
        m_data[nRows -1 ] = new std::string[nCols]; 
        for (int i = 0; i < nCols; ++i){
            m_data[nRows -1][i] = emptystr; 
        }
        m_data[nRows-1][col] = tempstr;
        delete [] old;
        if (match(nRows-1, col)){
            return tempstr; 
        }
        else{
            return emptystr; 
        }
    }
    else{ 
        //std::cout<<"c"<<std::endl;
        for (int i = 0; i < nRows; ++i){ 
            std::string* old = m_data[i];
            m_data[i] = new std::string[col+1];
            int j;
            for (j = 0; j <= col; ++j){
                m_data[i][j] = emptystr;
                if (j < nCols)  {
                    //std::cout<<i<<j<<old[j]<<std::endl;
                    m_data[i][j] = old[j];
                }
            } 
            delete [] old;
        }
        m_data[0][col] = tempstr;
        nCols = col + 1;
        //std::cout<<"d"<<std::endl;
        if (match(0, col)){
            return tempstr; 
        }
        else{
            return emptystr; 
        }
    }
   
}

int Board::numTokensInColumn(int colNum) const
{
    return 0;
}

int Board::numTokensInRow(int rowNum) const
{
    return 0;
}

int Board::numRows() const
{
    return nRows;
}

int Board::numColumns() const
{
    return nCols;
}

bool Board::match(int row, int col){
   //std::cout<<"match\n";
    int count = 1; 
    for (int i = col + 1; i < nCols && i < col + 3; ++i){
        if (m_data[row][i] == m_data[row][i-1]){
            ++count; 
        }
        else{
            break;
        }
    }
    //std::cout<<"a"<<std::endl;
    for (int i = col -1; i > 0 && i > col -3; --i){
        if (m_data[row][i] == m_data[row][i+1]){
            ++count;
        }
        else{
            break;
        }
    }
    //std::cout<<"b"<<std::endl;
    if (count >= 4){
        return true;
    }
    //std::cout<<"c"<<std::endl;
    count = 1; 
    for (int i = row + 1; i < nRows && i < row + 3; ++i){
        //std::cout<<i<<std::endl;
        if (m_data[i][col] == m_data[row][col]){
            //std::cout<<"c2"<<std::endl;
            ++count; 
        }
        else{
            //std::cout<<"c3"<<std::endl;
            break;
        }
    }
    //std::cout<<"d"<<std::endl;
    for (int i = row -1; i > 0 && i > row -3; --i){
        if (m_data[i][col] == m_data[i+1][col]){
            ++count;
        }
        else{
            break;
        }
    }
    //std::cout<<"e"<<std::endl;
    return count >= 4; 
}

void Board::clear()
{
    for (int i = 0; i < nRows; ++i){
        delete [] m_data[i]; 
    }
    delete [] m_data; 
    nRows = 5;
    nCols = 4;
    m_data = new std::string *[nRows]; 
    for (int i = 0; i < nRows; ++i){
        m_data[i] = new std::string[nCols]; 
        for (int j = 0; j < nCols; ++j){
            m_data[i][j] = emptystr; 
         }
    }
}

const std::string &Board::strAt(int row, int col) const{
    return m_data[row][col]; 
}

std::ostream& operator<< (std::ostream &stream, const Board& b)

{
    for(int i = b.numRows() -1; i >= 0; --i){
        for(int j = 0; j < b.numColumns(); ++j){
            stream << b.strAt(i, j) << " ";
        }
        stream << "\n";
    }
    return stream;

} 

