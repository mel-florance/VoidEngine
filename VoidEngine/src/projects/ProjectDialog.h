#pragma once

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QWidget>
#include <QDialog>
#include "ui_ProjectDialog.h"

class ProjectDialog : public QDialog
{
	Q_OBJECT

public:
	ProjectDialog(QWidget *parent = Q_NULLPTR);
	~ProjectDialog();

	void createProject();

private:
	Ui::ProjectDialogClass ui;
};
