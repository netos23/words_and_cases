#include "subwindow.h"

#include <QGridLayout>

SubWindow::SubWindow(QString fileName, QString initText, QWidget* parent): QWidget (parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    this->setLayout(gridLayout);
    QString name = getFileName(fileName);
    this->setWindowTitle(name);
    this->name = name;
    text = new QLabel(initText, this);
    gridLayout->addWidget(text);
}

SubWindow::SubWindow(QString initText, QWidget *parent): QWidget (parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    this->setLayout(gridLayout);
    text = new QLabel(initText, this);
    gridLayout->addWidget(text);
}

SubWindow::~SubWindow()
{
    delete text;
}

void SubWindow::setLabel(QString text)
{
    delete this->text;
    text = nullptr;
    this->text = new QLabel(text, this);
}

QLabel* SubWindow::getLabel()
{
    return text;
}

QString SubWindow::getName()
{
    return name;
}

void SubWindow::setName(QString name)
{
    this->name = name;
}

std::string SubWindow::getType()
{
    QVector<QString> strings = name.split(QString(".")).toVector();
    return strings[strings.length() - 1].toStdString();
}

std::string SubWindow::readFile(QString fileName)
{
    std::ifstream myFile;
    myFile.open(fileName.toStdString());
    if (!myFile) {
        std::cout << "file is not open" << std::endl;
    }
    std::string str;
    std::string buff = "";
    while(true) {
        if(myFile.eof()) break;
        str = "";
        myFile >> str;
        buff += '\0' + str;
    }
    myFile.close();
    return buff;
}

QString SubWindow::getFileName(QString file)
{
    for (int i = file.size() - 1; i >= 0; i--) {
        if (file[i] == '/') {
            return QString(file.right(file.size() - 1 - i));
        }
    }
}

bool SubWindow::fileNameIs(std::string fileName)
{
    return fileName == name.toStdString();
}


