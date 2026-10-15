#ifndef TP1_COM_H
#define TP1_COM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TP1_Com;
}
QT_END_NAMESPACE

class TP1_Com : public QMainWindow
{
    Q_OBJECT

public:
    explicit TP1_Com(QWidget *parent = nullptr);
    ~TP1_Com() override;

private slots:


    void on_Connect_clicked();

    void on_Disconnect_clicked();

    void on_Selection_clicked();

    void on_Mise_a_jour_clicked();

    void on_Charger_clicked();

    void on_Payer_clicked();

private:
    Ui::TP1_Com *ui;
};
#endif // TP1_COM_H
