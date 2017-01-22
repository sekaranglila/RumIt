#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    int rowdel() const;
    //Mengembalikan nilai baris yang ingin di hapus dari tabel

private slots:
    void on_buttonBox_accepted();
    //Implementasi ketika tombol Ok ditekan

    void on_buttonBox_rejected();
    //Implementasi ketika tombol Cancel ditekan

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
