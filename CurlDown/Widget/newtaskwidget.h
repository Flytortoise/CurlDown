#ifndef NEWTASKWIDGET_H
#define NEWTASKWIDGET_H

#include <QDialog>

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>

class NewTaskWidget : public QDialog
{
    Q_OBJECT
public:
    explicit NewTaskWidget(QDialog *parent = nullptr);

signals:
    void CurlDown(QString DownPath, QString FileName, QString SavePath);

public slots:
    void SetSaveName(const QString &filePath);
    void StartDown();

private:
    void CreateInit();
    void CreateLayout();

    enum {
        DOWNPATH,
        FILENAME,
        SAVEPATH,
        FILESIZE,
        FILESIZEDATA,
        END
    };

private:
    QLabel *m_Label[END];
    QLineEdit *m_DownPathLineEdit;
    QLineEdit *m_FileNameLineEdit;
    QLineEdit *m_SavePathLineEdit;
    QPushButton *m_OpenSavePathButton;
    QPushButton *m_OpenBTButton;
    QPushButton *m_DownButton;
    QPushButton *m_CancelButton;
};

#endif // NEWTASKWIDGET_H
