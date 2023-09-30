#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Поиск файлов");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-я0-9:/ ._\\-]+"), line_name1);
    QRegularExpressionValidator* validator2 = new QRegularExpressionValidator(QRegularExpression("[*A-Za-zА-Яа-я0-9/ _\\-]+(\\.[a-z*]+)*"), line_temp_file1);


    layoutH = new QHBoxLayout();
    layoutG1 = new QGridLayout();
    layoutG2 = new QGridLayout();

    layoutH->addLayout(layoutG1);
    layoutH->addLayout(layoutG2);

    QFont font;
    font.setPointSize(10);

    //layoutG1-----------------------------------------------------
    label1 = new QLabel("Полное/частичное название файла: ");
    but_choose_file1 = new QPushButton("Выберите файл...");
    but_choose_file1->setStyleSheet("background-color: rgb(192,192,192); border: 2px solid black; "
                    "color:rgba(0,0,0,0.6); ");
    but_choose_file1->setFont(font);

    line_name1 = new QLineEdit ("");
    line_name1->setFont(font);
    line_name1->setMaxLength(255);
    line_name1->setValidator(validator);
    line_name1->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    label_template1 = new QLabel("\nШаблон для поиска директорий (по умолчанию C:/)");

    but_choose_dir1 = new QPushButton("Выберите директорию...");
    but_choose_dir1->setStyleSheet("background-color: rgb(192,192,192); border: 2px solid black; "
                                    "color:rgba(0,0,0,0.6); ");
    but_choose_dir1->setFont(font);

    line_directory1 = new QLineEdit ("");
    line_directory1->setValidator(validator);
    line_directory1->setFont(font);
    line_directory1->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    label_template_file1 = new QLabel("\nРасширение");
    line_temp_file1 = new QLineEdit ("");
    line_temp_file1->setValidator(validator2);
    line_temp_file1->setFont(font);
    line_temp_file1->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    BoxRecursive1 = new QCheckBox("Рекурсивный поиск");
    label_recursive_depth1 = new QLabel("Глубина: ");
    depth1 = new QSpinBox();
    depth1->setMinimum(0);
    depth1->setMaximum(100);
    depth1->setValue(0);

    fileListWidget1 = new QListWidget(this);

    QStringList fileNames;

    but_find1 = new QPushButton("Найти");

    layoutG1->addWidget(label1, 0, 0);
    layoutG1->addWidget(line_name1, 1, 0);
    layoutG1->addWidget(but_choose_file1, 1, 1);
    layoutG1->addWidget(label_template1, 2, 0, 1, 3);
    layoutG1->addWidget(line_directory1, 3, 0);
    layoutG1->addWidget(but_choose_dir1, 3, 1);

    layoutG1->addWidget(label_template_file1, 4, 0, 1, 3);
    layoutG1->addWidget(line_temp_file1, 5, 0);

    layoutG1->addWidget(BoxRecursive1, 6, 0);
    layoutG1->addWidget(label_recursive_depth1, 6, 1);
    layoutG1->addWidget(depth1, 6, 2);

    layoutG1->addWidget(fileListWidget1, 7, 0, 1, 3);
    layoutG1->addWidget(but_find1, 8, 0, 1, 3);


    //layoutG2-----------------------------------------------------
    label2 = new QLabel("Полное/частичное название файла: ");
    but_choose_file2 = new QPushButton("Выберите файл...");
    but_choose_file2->setStyleSheet("background-color: rgb(192,192,192); border: 2px solid black; "
                                    "color:rgba(0,0,0,0.6); ");
    but_choose_file2->setFont(font);

    line_name2 = new QLineEdit ("");
    line_name2->setFont(font);
    line_name2->setMaxLength(255);
    line_name2->setValidator(validator);
    line_name2->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    label_template2 = new QLabel("\nШаблон для поиска директорий (по умолчанию C:/)");

    but_choose_dir2 = new QPushButton("Выберите директорию...");
    but_choose_dir2->setStyleSheet("background-color: rgb(192,192,192); border: 2px solid black; "
                                   "color:rgba(0,0,0,0.6); ");
    but_choose_dir2->setFont(font);

    line_directory2 = new QLineEdit ("");
    line_directory2->setValidator(validator);
    line_directory2->setFont(font);
    line_directory2->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    label_template_file2 = new QLabel("\nРасширение");
    line_temp_file2 = new QLineEdit ("");
    line_temp_file2->setValidator(validator2);
    line_temp_file2->setFont(font);
    line_temp_file2->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:disabled { background-color: lightgray; }");

    BoxRecursive2 = new QCheckBox("Рекурсивный поиск");
    label_recursive_depth2 = new QLabel("Глубина: ");
    depth2 = new QSpinBox();
    depth2->setDisabled(true);
    depth2->setMinimum(0);
    depth2->setMaximum(100);
    depth2->setValue(0);

    fileListWidget2 = new QListWidget(this);

    but_find2 = new QPushButton("Найти");

    layoutG2->addWidget(label2, 0, 0);
    layoutG2->addWidget(line_name2, 1, 0);
    layoutG2->addWidget(but_choose_file2, 1, 1);
    layoutG2->addWidget(label_template2, 2, 0, 1, 3);
    layoutG2->addWidget(line_directory2, 3, 0);
    layoutG2->addWidget(but_choose_dir2, 3, 1);

    layoutG2->addWidget(label_template_file2, 4, 0, 1, 3);
    layoutG2->addWidget(line_temp_file2, 5, 0);

    layoutG2->addWidget(BoxRecursive2, 6, 0);
    layoutG2->addWidget(label_recursive_depth2, 6, 1);
    layoutG2->addWidget(depth2, 6, 2);

    layoutG2->addWidget(fileListWidget2, 7, 0, 1, 3);
    layoutG2->addWidget(but_find2, 8, 0, 1, 3);


    //функции------------------------------------------------------
    connect(but_choose_file1, SIGNAL(clicked()), this, SLOT(on_but_choose_file1_clicked()));
    connect(but_choose_file2, SIGNAL(clicked()), this, SLOT(on_but_choose_file2_clicked()));
    connect(but_choose_dir1, SIGNAL(clicked()), this, SLOT(on_but_choose_dir1_clicked()));
    connect(but_choose_dir2, SIGNAL(clicked()), this, SLOT(on_but_choose_dir2_clicked()));

    connect(BoxRecursive1,SIGNAL(clicked()), this, SLOT(on_Radio_recursive1_clicked()));
    connect(BoxRecursive2,SIGNAL(clicked()), this, SLOT(on_Radio_recursive2_clicked()));

    connect(but_find1, SIGNAL(clicked()), this, SLOT(on_but_find1_clicked()));
    connect(but_find2, SIGNAL(clicked()), this, SLOT(on_but_find2_clicked()));

    centralWidget->setLayout(layoutH);
    show();

}

void MainWindow::on_but_choose_file1_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("All Files (*.*)"));
    if(!filePath.isEmpty()){
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        line_name1->setText(fileName);
    }

}

void MainWindow::on_but_choose_file2_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("All Files (*.*)"));
    if(!filePath.isEmpty()){
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        line_name2->setText(fileName);
    }
}

void MainWindow::on_but_choose_dir1_clicked(){
    QString dirPath = QFileDialog::getExistingDirectory(this,tr("Choose directory"), QString(), QFileDialog::ShowDirsOnly);
    if(!dirPath.isEmpty()){
        line_directory1->setText(dirPath);
    }
}

void MainWindow::on_but_choose_dir2_clicked(){
    QString dirPath = QFileDialog::getExistingDirectory(this,tr("Choose directory"), QString(), QFileDialog::ShowDirsOnly);
    if(!dirPath.isEmpty()){
        line_directory2->setText(dirPath);
    }
}

void MainWindow::on_Radio_recursive1_clicked(){
    if (BoxRecursive1->isChecked()){
        recursive1 = true;
        depth1->setDisabled(false);
    }
    else recursive1 = false;

}


void MainWindow::on_Radio_recursive2_clicked(){
    if (BoxRecursive2->isChecked()){
        recursive2 = true;
        depth2->setDisabled(false);
    }
    else recursive2 = false;
}


void MainWindow::on_but_find1_clicked(){
    QString directory;
    if (line_directory1->text().isEmpty())
        directory = "C:/";
    else directory = line_directory1->text();

    SearchThread* searchThread1 = new SearchThread();
    searchThread1->directory = directory;
    searchThread1->partialFileName = line_name1->text();;
    searchThread1->extension = line_temp_file1->text();
    searchThread1->recursive = recursive1;
    searchThread1->depth = depth1->value();
    connect(searchThread1, &SearchThread::searchFinished, this, &MainWindow::handleSearchFinished1);
    connect(searchThread1, &SearchThread::searchFinished, searchThread1, &QObject::deleteLater);
    searchThread1->start();
}

void MainWindow::on_but_find2_clicked(){
    QString directory;
    if (line_directory2->text().isEmpty())
        directory = "C:/";
    else directory = line_directory2->text();

    SearchThread* searchThread2 = new SearchThread();
    searchThread2->directory = directory;
    searchThread2->partialFileName = line_name2->text();
    searchThread2->recursive = recursive2;
    searchThread2->extension = line_temp_file2->text();
    searchThread2->depth = depth2->value();
    connect(searchThread2, &SearchThread::searchFinished, this, &MainWindow::handleSearchFinished2);
    connect(searchThread2, &SearchThread::searchFinished, searchThread2, &QObject::deleteLater);
    searchThread2->start();
}


void MainWindow::handleSearchFinished1(const QStringList& results) {
    fileListWidget1->clear();
    if(results.isEmpty()){
        fileListWidget1->addItem("There are no files with such name");
    }
    else fileListWidget1->addItems(results);
}

void MainWindow::handleSearchFinished2(const QStringList& results) {
    fileListWidget2->clear();
    if(results.isEmpty()){
        fileListWidget2->addItem("There are no files with such name");
    }
    else fileListWidget2->addItems(results);
}


MainWindow::~MainWindow()
{
}
