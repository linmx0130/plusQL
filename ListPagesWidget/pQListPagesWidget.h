/*
 Copyright (c) 2012 Sweetdumplings <linmx0130@163.com>
 All rights reserved.
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/
#ifndef PQLISTPAGESWIDGET_H
#define PQLISTPAGESWIDGET_H
#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>

class pQListPagesWidget : public QWidget
{
	Q_OBJECT
	private:
		QListWidget *List;
		QStackedWidget *SWidget;
	private slots:
		void __ListClicked(int row);
		void __WidgetSet(int index);
	signals:
		void listClicked(int row);
		void currentWidgetChanged(int index);
	public slots:
		void setCurrentIndex(int index);
		void setCurrentItem(QListWidgetItem *item);
		void setCurrentWidget(QWidget *widget);
		void removeByIndex(int index);
		void removeByItem(QListWidgetItem *item);
		void removeByWidget(QWidget *widget);
	public:
		pQListPagesWidget(QWidget *parent=0);
		int addPage(QListWidgetItem *item, QWidget *widget);
		int addPage(const QString &label, QWidget *widget);
		int insertPage(int index,QListWidgetItem *item, QWidget *widget);
		int insertPage(int index,const QString &label, QWidget *widget);
		void setSizePolicy2(const QSizePolicy &forList, const QSizePolicy &forSWidget);
		int currentIndex() const;
};

#endif
