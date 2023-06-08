#include <QMdiSubWindow>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loggingcategories.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    table = new CaseTable();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    for (size_t i = 0; i < widgets.size(); ++i) {
        delete widgets[i];
    }
    delete table;
    delete ui;
}

//void MainWindow::on_OpenButton_clicked()
//{

//}

//void MainWindow::on_FindCasesButton_clicked()
//{

//}

//void MainWindow::on_SaveButton_clicked()
//{
////    if (text.empty())
////    {
//////        throw "firstly you should choose file with words";
////        return;
////    }
////    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));
////    if (fileName == "")
////    {
////        return;
////    }

//}

SubWindow* MainWindow::findCaseFile(std::string fileName)
{
    for (size_t i = 0; i < widgets.size(); i++) {
        if (widgets[i]->fileNameIs(fileName))
        {
            return widgets[i];
        }
    }
    return nullptr;
}

SubWindow* MainWindow::openSubWindow(QString fileName, QString initText)
{
    SubWindow *widget = nullptr;
    if (fileName != nullptr)
    {
        widget = new SubWindow(fileName, initText, ui->mdiArea);
    }
    else
    {
        widget = new SubWindow(initText, ui->mdiArea);
    }
    widgets.push_back(widget);
    ui->mdiArea->addSubWindow(widget);
    widget->show();
    return widget;
}

SubWindow *MainWindow::getActiveWindow()
{
    if (widgets.size() == 0)
    {
        return nullptr;
    }
    QMdiSubWindow* subWindow = ui->mdiArea->activeSubWindow();
    return dynamic_cast<SubWindow*>(subWindow->widget());
}


void MainWindow::on_openFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));
    if (fileName == "")
    {
        return;
    }
    std::vector<std::string> text = Utils::readTextFromFile(fileName.toStdString());

    openSubWindow(fileName, QString::fromStdString(Utils::fromVectorToString(text)));

    qInfo(logInfo()) << "file " + fileName + " is saved";
}

void MainWindow::on_saveFile_triggered()
{
    SubWindow* activeWindow = getActiveWindow();
    if (activeWindow == nullptr)
    {
        return;
    }

    bool bOk;
    QString str = QInputDialog::getText( 0,
                                         "Input",
                                         "Name:",
                                         QLineEdit::Normal,
                                         "Tarja",
                                         &bOk
                                        );
    if (str == "")
    {
        return;
    }
    str += ".txt";
//    if (!bOk) {
//        // ???? ?????? ?????? Cancel
//    }

    Utils::createAndWriteToFile(str.toStdString(), activeWindow->getLabel()->text().toStdString());
    activeWindow->setName(str);

    qInfo(logInfo()) << "text saved to file " + str;
}

void MainWindow::on_handle_triggered()
{
    bool bOk;
    QString str = QInputDialog::getText( 0,
                                         "Input",
                                         "Name:",
                                         QLineEdit::Normal,
                                         "Tarja",
                                         &bOk
                                        );
//    if (!bOk) {
//        // ???? ?????? ?????? Cancel
//    }
    SubWindow* selectedCaseFile = findCaseFile(str.toStdString());
    if (selectedCaseFile == nullptr)
    {
        return;
    }
    table->fillTable(Utils::fromLabelStringToVector(selectedCaseFile->getLabel()->text().toStdString()));

    SubWindow* activeWindow = getActiveWindow();
    if (!(activeWindow->getType() == "txt"))
    {
        return;
    }
    std::vector<std::string> textFromFile = Utils::fromLabelStringToVector(activeWindow->getLabel()->text().toStdString());

    openSubWindow(nullptr, QString::fromStdString(Utils::fromPairsToString(table->getFileCases(textFromFile))));

    qInfo(logInfo()) << "finded cases for file " + activeWindow->getName();
}
