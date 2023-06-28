#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Button1_clicked()
{
   operand = operand * 10 + 1;
   updateLcdOperand();
}


void Widget::on_Button2_clicked()
{
   operand = operand * 10 + 2;
   updateLcdOperand();
}


void Widget::on_Button3_clicked()
{
    operand = operand * 10 + 3;
    updateLcdOperand();
}


void Widget::on_Button4_clicked()
{
    operand = operand * 10 + 4;
    updateLcdOperand();
}


void Widget::on_Button5_clicked()
{
    operand = operand * 10 + 5;
    updateLcdOperand();
}


void Widget::on_Button6_clicked()
{
    operand = operand * 10 + 6;
    updateLcdOperand();
}


void Widget::on_Button7_clicked()
{
    operand = operand * 10 + 7;
    updateLcdOperand();
}


void Widget::on_Button8_clicked()
{
    operand = operand * 10 + 8;
    updateLcdOperand();
}


void Widget::on_Button9_clicked()
{
    operand = operand * 10 + 9;
    updateLcdOperand();
}


void Widget::on_Button0_clicked()
{
    operand = operand * 10;
    updateLcdOperand();
}


void Widget::on_ButtonSign_clicked()
{
    operand *= -1;
    updateLcdOperand();
}

///////////////////////////////////////////////////////////////////////////
void Widget::on_ButtonPlus_clicked()
{
    calculate(1);
    updateLcdOperand();
}


void Widget::on_ButtonMinus_clicked()
{
    calculate(2);
    updateLcdOperand();
}


void Widget::on_ButtonMult_clicked()
{
    calculate(3);
    updateLcdOperand();
}


void Widget::on_ButtonDivide_clicked()
{
    calculate(4);
    updateLcdOperand();
}
///////////////////////////////////////////////////////////////////////////

void Widget::on_ButtonEquals_clicked()
{
    calculate(oper_type);
    oper_type = 5;
    calculate(oper_type);
    updateLcdOperand();
}


void Widget::on_ButtonBackspace_clicked()
{
    operand = (int)operand / 10;
    updateLcdOperand();
}


void Widget::on_ButtonClear_clicked()
{
   operand = 0;
   updateLcdOperand();
}

void Widget::updateLcdOperand()
{

   ui->lcdOperand->display(operand);
}

void Widget::calculate(int new_oper)
{

    switch (oper_type)
    {
    case 1: // plus
        left_operand = left_operand + operand;
        operand = 0;
        break;
    case 2: // minus

        left_operand = left_operand - operand;
        operand=0;
        break;
    case 3: // Mult
        left_operand = left_operand * operand;
        operand=0;
        break;
    case 4: // divide
        left_operand = (operand==0) ? 0 : left_operand / operand;
        operand=0;
        break;
    case 5: // equals
        operand = left_operand;
        left_operand = 0;
        new_oper = 0;
        break;
    default:
        left_operand = operand;
        operand = 0;
        break;
    }

    oper_type = new_oper;
}

