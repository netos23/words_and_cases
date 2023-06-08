#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QLabel>
#include <QWidget>
#include "casetable.h"


class SubWindow: public QWidget
{
public:
    SubWindow(QString fileName, QString initText, QWidget *parent = nullptr);
    SubWindow(QString initText, QWidget *parent = nullptr);
    ~SubWindow();

public:
    void setLabel(QString text);
    QLabel* getLabel();
    void resetText();
    bool fileNameIs(std::string fileName);
    std::string getType();
    QString getName();
    void setName(QString name);
private:
    std::string readFile(QString fileName);
    QString getFileName(QString file);

private:
    QLabel* text;
    QString name = "";
};

#endif // SUBWINDOW_H
