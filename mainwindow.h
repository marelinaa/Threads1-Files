
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "searchthread.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSplitter>
#include <QFileDialog>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QResizeEvent>
#include <QFont>
#include <QFileInfo>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QListWidget>
#include <QStringList>
#include <QDebug>
#include <QPalette>
#include <QObject>

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QHBoxLayout *layoutH;
    QGridLayout *layoutG1;
    QGridLayout *layoutG2;
    QWidget *leftWidget;

    QFont* fontRed;

    QPushButton* but_choose_file1;
    QPushButton* but_choose_file2;
    QPushButton* but_find1;
    QPushButton* but_find2;
    QPushButton* but_choose_dir1;
    QPushButton* but_choose_dir2;

    QCheckBox* BoxRecursive1;
    QCheckBox* BoxRecursive2;

    QLabel* label1;
    QLabel* label2;
    QLabel* label_template1;
    QLabel* label_template2;
    QLabel* label_template_file1;
    QLabel* label_template_file2;
    QLabel* label_recursive_depth1;
    QLabel* label_recursive_depth2;

    QLineEdit* line_name1;
    QLineEdit* line_name2;
    QLineEdit* line_directory1;
    QLineEdit* line_directory2;
    QLineEdit* line_temp_file1;
    QLineEdit* line_temp_file2;

    QListWidget* fileListWidget1;
    QListWidget* fileListWidget2;

    QSpinBox* depth1;
    QSpinBox* depth2;

    QThread* thread;

    bool recursive1;
    bool recursive2;

private slots:
    void on_but_choose_file1_clicked();
    void on_but_choose_file2_clicked();
    void on_but_choose_dir1_clicked();
    void on_but_choose_dir2_clicked();
    void handleSearchFinished1(const QStringList& results);
    void handleSearchFinished2(const QStringList& results);
    void on_but_find1_clicked();
    void on_but_find2_clicked();
    void on_Radio_recursive1_clicked();
    void on_Radio_recursive2_clicked();

signals:
    void searchFinished(const QStringList& results);

};



#endif // MAINWINDOW_H
