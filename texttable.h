#ifndef TEXTTABLE_H
#define TEXTTABLE_H
#include <QList>
#include <QStringList>
class TextTable
{
public:
    TextTable(QList<QStringList> &d);

    void draw();
private:
    QList<QStringList> table;
    int maxCharCount[128]; //max column 128
    int maxSumCount;
    void drawSplitLine();
    void drawRowContent(int rowNum);
    int colCount;
};

#endif // TEXTTABLE_H
