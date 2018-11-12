/********************************************************************************
** Form generated from reading UI file 'VoidEngine.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOIDENGINE_H
#define UI_VOIDENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoidEngineClass
{
public:
    QAction *actionNew_project;
    QAction *actionExit;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelect_all;
    QAction *actionProject_properties;
    QAction *actionOptions;
    QAction *actionDocumentation;
    QAction *actionTechnical_support;
    QAction *actionFind_updates;
    QAction *actionAbout_Void_Engine;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuProject;
    QMenu *menuTools;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VoidEngineClass)
    {
        if (VoidEngineClass->objectName().isEmpty())
            VoidEngineClass->setObjectName(QStringLiteral("VoidEngineClass"));
        VoidEngineClass->resize(1280, 773);
        VoidEngineClass->setBaseSize(QSize(1280, 720));
        actionNew_project = new QAction(VoidEngineClass);
        actionNew_project->setObjectName(QStringLiteral("actionNew_project"));
        actionExit = new QAction(VoidEngineClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen = new QAction(VoidEngineClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(VoidEngineClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(VoidEngineClass);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionImport = new QAction(VoidEngineClass);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionExport = new QAction(VoidEngineClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionCut = new QAction(VoidEngineClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(VoidEngineClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(VoidEngineClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionDelete = new QAction(VoidEngineClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSelect_all = new QAction(VoidEngineClass);
        actionSelect_all->setObjectName(QStringLiteral("actionSelect_all"));
        actionProject_properties = new QAction(VoidEngineClass);
        actionProject_properties->setObjectName(QStringLiteral("actionProject_properties"));
        actionOptions = new QAction(VoidEngineClass);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionDocumentation = new QAction(VoidEngineClass);
        actionDocumentation->setObjectName(QStringLiteral("actionDocumentation"));
        actionTechnical_support = new QAction(VoidEngineClass);
        actionTechnical_support->setObjectName(QStringLiteral("actionTechnical_support"));
        actionFind_updates = new QAction(VoidEngineClass);
        actionFind_updates->setObjectName(QStringLiteral("actionFind_updates"));
        actionAbout_Void_Engine = new QAction(VoidEngineClass);
        actionAbout_Void_Engine->setObjectName(QStringLiteral("actionAbout_Void_Engine"));
        centralWidget = new QWidget(VoidEngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        VoidEngineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VoidEngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        VoidEngineClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(VoidEngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VoidEngineClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_project);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_all);
        menuProject->addAction(actionProject_properties);
        menuTools->addAction(actionOptions);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionTechnical_support);
        menuHelp->addSeparator();
        menuHelp->addAction(actionFind_updates);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Void_Engine);

        retranslateUi(VoidEngineClass);

        QMetaObject::connectSlotsByName(VoidEngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *VoidEngineClass)
    {
        VoidEngineClass->setWindowTitle(QApplication::translate("VoidEngineClass", "VoidEngine", nullptr));
        actionNew_project->setText(QApplication::translate("VoidEngineClass", "New project...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew_project->setShortcut(QApplication::translate("VoidEngineClass", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("VoidEngineClass", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("VoidEngineClass", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("VoidEngineClass", "Open...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("VoidEngineClass", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("VoidEngineClass", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("VoidEngineClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("VoidEngineClass", "Save as...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("VoidEngineClass", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionImport->setText(QApplication::translate("VoidEngineClass", "Import...", nullptr));
        actionExport->setText(QApplication::translate("VoidEngineClass", "Export...", nullptr));
        actionCut->setText(QApplication::translate("VoidEngineClass", "Cut", nullptr));
        actionCopy->setText(QApplication::translate("VoidEngineClass", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("VoidEngineClass", "Paste", nullptr));
        actionDelete->setText(QApplication::translate("VoidEngineClass", "Delete", nullptr));
        actionSelect_all->setText(QApplication::translate("VoidEngineClass", "Select all", nullptr));
        actionProject_properties->setText(QApplication::translate("VoidEngineClass", "Project properties", nullptr));
        actionOptions->setText(QApplication::translate("VoidEngineClass", "Options...", nullptr));
        actionDocumentation->setText(QApplication::translate("VoidEngineClass", "Documentation", nullptr));
        actionTechnical_support->setText(QApplication::translate("VoidEngineClass", "Technical support", nullptr));
        actionFind_updates->setText(QApplication::translate("VoidEngineClass", "Find updates...", nullptr));
        actionAbout_Void_Engine->setText(QApplication::translate("VoidEngineClass", "About Void Engine", nullptr));
        menuFile->setTitle(QApplication::translate("VoidEngineClass", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("VoidEngineClass", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("VoidEngineClass", "View", nullptr));
        menuProject->setTitle(QApplication::translate("VoidEngineClass", "Project", nullptr));
        menuTools->setTitle(QApplication::translate("VoidEngineClass", "Tools", nullptr));
        menuWindow->setTitle(QApplication::translate("VoidEngineClass", "Window", nullptr));
        menuHelp->setTitle(QApplication::translate("VoidEngineClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VoidEngineClass: public Ui_VoidEngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOIDENGINE_H
