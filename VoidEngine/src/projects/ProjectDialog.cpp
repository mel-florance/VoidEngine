#include "ProjectDialog.h"

ProjectDialog::ProjectDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	QPushButton* btn = this->findChild<QPushButton*>("pushButton");
	QObject::connect(btn, &QPushButton::clicked, this, &ProjectDialog::createProject);
}

void ProjectDialog::createProject()
{
	QMessageBox msgBox;
	QLineEdit* input = this->findChild<QLineEdit*>("lineEdit");
	QString projectName = input->text();
	QString projectsFolder = QDir::homePath() + "/VoidEngineProjects";

	if (projectName.size() == 0)
	{
		msgBox.setText("The project name can't be empty !");
		msgBox.exec();
		return;
	}

	QString projectFolder = projectsFolder + "/" + input->text();

	if(!QDir(projectsFolder).exists())
		QDir().mkdir(projectsFolder);

	if (!QDir(projectFolder).exists())
	{
		QDir().mkdir(projectFolder);
		QFile file(projectFolder + "/config.ini");

		if (file.open(QIODevice::ReadWrite))
		{
			QTextStream stream(&file);
			stream << "config" << endl;
		}

		input->setText("");
		this->close();
	}
	else {
		msgBox.setText("A project folder with the same name already exists.");
		msgBox.exec();
	}
}

ProjectDialog::~ProjectDialog()
{

}
