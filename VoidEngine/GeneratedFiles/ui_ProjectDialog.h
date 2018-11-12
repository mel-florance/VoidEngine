/********************************************************************************
** Form generated from reading UI file 'ProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTDIALOG_H
#define UI_PROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectDialogClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *ProjectDialogClass)
    {
        if (ProjectDialogClass->objectName().isEmpty())
            ProjectDialogClass->setObjectName(QStringLiteral("ProjectDialogClass"));
        ProjectDialogClass->resize(399, 90);
        formLayoutWidget = new QWidget(ProjectDialogClass);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 401, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(10, 10, 10, 10);
        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEdit);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, pushButton);


        retranslateUi(ProjectDialogClass);

        QMetaObject::connectSlotsByName(ProjectDialogClass);
    } // setupUi

    void retranslateUi(QWidget *ProjectDialogClass)
    {
        ProjectDialogClass->setWindowTitle(QApplication::translate("ProjectDialogClass", "New Project", nullptr));
        label->setText(QApplication::translate("ProjectDialogClass", "Name", nullptr));
        pushButton->setText(QApplication::translate("ProjectDialogClass", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectDialogClass: public Ui_ProjectDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTDIALOG_H
