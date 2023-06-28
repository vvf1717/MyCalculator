#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked();
    void on_Button4_clicked();
    void on_Button5_clicked();
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();
    void on_Button0_clicked();
    void on_ButtonSign_clicked();
    void on_ButtonPlus_clicked();
    void on_ButtonMinus_clicked();
    void on_ButtonMult_clicked();
    void on_ButtonDivide_clicked();
    void on_ButtonEquals_clicked();
    void on_ButtonBackspace_clicked();
    void on_ButtonClear_clicked();

    void updateLcdOperand();
    void calculate(int new_oper);


private:
    double operand = 0;
    double left_operand = 0;
    int oper_type = 0;

    bool dot;
    Ui::Widget *ui;
};
#endif // WIDGET_H
