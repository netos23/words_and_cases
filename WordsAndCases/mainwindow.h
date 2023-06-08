#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include "subwindow.h"
#include "casetable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SubWindow* openSubWindow(QString fileName, QString initText);
    SubWindow* getActiveWindow();
    void writeTextToFile(std::string fileName, std::string text);
    std::string readeChoosenText(std::string fileName);
    SubWindow* findCaseFile(std::string fileName);

private slots:
//    void on_SaveButton_clicked();

//    void on_OpenButton_clicked();

//    void on_FindCasesButton_clicked();

    void on_openFile_triggered();

    void on_saveFile_triggered();

    void on_handle_triggered();

private:
    Ui::MainWindow *ui;
    CaseTable* table;
    std::vector<SubWindow*> widgets;
    std::string text = "";
};

#endif // MAINWINDOW_H
