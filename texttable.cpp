#include "texttable.h"
#include <iostream>

TextTable::TextTable(QList<QStringList> &d):table(d),colCount(0)
{
    memset(maxCharCount, 0, sizeof(maxCharCount));
}

void TextTable::drawSplitLine(){

    std::cout << '+';
    for(int i = 0; i < maxSumCount; ++i){
        std::cout << '-';
    }
    std::cout << '+';
    std::cout << std::endl;
}

void TextTable::drawRowContent(int rowNum){
    std::cout << '|';
    for(int i = 0; i < colCount; ++i){
        int count =  maxCharCount[i];
        std::cout <<' ';
        --count;
        std::cout << qPrintable(table[rowNum][i]);
        count -= table[rowNum][i].size();
        for(int j = 0; j < count; ++j)
            std::cout << ' ';
        std::cout << '|';
    }
    std::cout << std::endl;
}

void TextTable::draw(){
    QStringList row;
    int colNum;
    foreach (row, table){
        colNum = 0;
        QString field;
        foreach(field, row){
            if(row[colNum].size() > maxCharCount[colNum])
                maxCharCount[colNum] = row[colNum].size();
            colNum++;
        }
    }
    colCount = colNum;
    maxSumCount = 0;
    for(int i = 0; i < colCount; ++i){
        maxCharCount[i] += 2;
        maxSumCount += maxCharCount[i];
    }
    maxSumCount += colCount - 1;

    drawSplitLine();
    for(int i = 0; i < table.size(); ++i){
        drawRowContent(i);
        drawSplitLine();
    }

}
