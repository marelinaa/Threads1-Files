
#ifndef SEARCHTHREAD_H
#define SEARCHTHREAD_H

#include <QThread>
#include <QDir>
#include <QRegularExpressionValidator>
#include <QFileInfo>
#include <QFileInfoList>
#include <QStringList>

class SearchThread : public QThread {
    Q_OBJECT
public:
    QString directory;
    QString partialFileName;
    QString extension;
    QStringList results;
    bool recursive;
    int depth;

protected:

    void run() override {
        QDir dir(directory);

        QRegularExpression regex(partialFileName, QRegularExpression::CaseInsensitiveOption);
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        QFileInfoList fileList = dir.entryInfoList();

        if (extension.isEmpty()){
            foreach (const QFileInfo& fileInfo, fileList) {
                if (fileInfo.fileName().contains(regex)) {
                    results.append(fileInfo.absoluteFilePath());
                }
            }
        }
        else {
            foreach (const QFileInfo& fileInfo, fileList) {
                if (fileInfo.fileName().contains(regex) && fileInfo.suffix() == extension) {
                    results.append(fileInfo.absoluteFilePath());
                }
            }
        }

        if (recursive) {
            searchFilesRecursively(dir, regex, depth, extension);
        }

        emit searchFinished(results);
    }

    void searchFilesRecursively(const QDir& dir, const QRegularExpression& regex, int depth, QString extension) {
        if (depth == 0) {
            return;
        }

        QFileInfoList subDirList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

        foreach (const QFileInfo& subDirInfo, subDirList) {
            QDir subDir(subDirInfo.absoluteFilePath());
            subDir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
            QFileInfoList fileList = subDir.entryInfoList();

            if (extension.isEmpty()){
                foreach (const QFileInfo& fileInfo, fileList) {
                    if (fileInfo.fileName().contains(regex)) {
                        results.append(fileInfo.absoluteFilePath());
                    }
                }
            }
            else {
                foreach (const QFileInfo& fileInfo, fileList) {
                    if (fileInfo.fileName().contains(regex) && fileInfo.suffix() == extension) {
                        results.append(fileInfo.absoluteFilePath());
                    }
                }
            }

            if (depth > 0) {
                searchFilesRecursively(subDir, regex, depth - 1, extension);
            }
        }
    }
signals:
    void searchFinished(const QStringList& results);
};

#endif // SEARCHTHREAD_H
