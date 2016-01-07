#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(bool autoAccept = true, QWidget *parent = 0);
    ~LoginDialog();

    inline const QString username() const {return usernameEdit->text();}
    inline const QString password() const {return passwordEdit->text();}

public:
    void show();

signals:
    void login(const QString &username, const QString &password);

private:
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QCheckBox *autoLoginCheck;
    QPushButton *acceptBtn;
    QPushButton *cancelBtn;

    QSettings *settings;

    bool autoAccept = true;
};

#endif // LOGINDIALOG_H
