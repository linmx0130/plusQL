/*
 * Only an example. In the public domain.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pQMenuTabWidget.h"
#include <QMenu>
#include <QLabel>
#include <QLineEdit>

class MainWindow:public QWidget
{
	Q_OBJECT
	private:
		pQMenuTabWidget *mainwid;
		QLabel *page1;
		QLineEdit *page2;
		QVBoxLayout *box;
		QAction *menu1;
	private slots:
		void menuAction1();
	public:
		MainWindow();
};

#endif
