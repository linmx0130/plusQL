/*Only an example. In the public domain.
 */
#include <QApplication>
#include <QtGui>
#include "MainWindow.h"

MainWindow::MainWindow()
{
	this->mainwid=new pQMenuTabWidget;
	this->page1=new QLabel("Page 1 : a lable");
	this->page2=new QLineEdit("plusQL! +Q Library");
	mainwid->addPage("Page1",page1);
	mainwid->addPage("Page2",page2);
	mainwid->setMenuButtonText("Menu");
	menu1=new QAction("Change!",this);
	connect(menu1,SIGNAL(triggered()),this,SLOT(menuAction1()));
	mainwid->menuObject()->addAction(menu1);
	this->box=new QVBoxLayout;
	box->addWidget(mainwid);
	setLayout(box);
}
void MainWindow::menuAction1(){
	this->page1->setText(this->page2->text());
}
int main(int argc,char **argv){
	QApplication app(argc,argv);
	MainWindow *mw=new MainWindow;
	mw->show();
	return app.exec();
}
