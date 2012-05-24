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

#include <QtGui>
#include "pQListPagesWidget.h"
//private slots
void pQListPagesWidget::__ListClicked(int row){
	SWidget->setCurrentIndex(row);
	emit this->listClicked(row);
}
void pQListPagesWidget::__WidgetSet(int index){
	List->setCurrentRow(index);
	emit this->currentWidgetChanged(index);
}
//public function
pQListPagesWidget::pQListPagesWidget(QWidget *parent)
	:QWidget(parent)
{
	QHBoxLayout *mainlayout=new QHBoxLayout;
	this->List=new QListWidget;
	this->SWidget=new QStackedWidget;
	mainlayout->addWidget(List);
	mainlayout->addWidget(SWidget);
	
	QSizePolicy size_policy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	size_policy.setHorizontalStretch(1);
	size_policy.setVerticalStretch(1);
	List->setSizePolicy(size_policy);
	size_policy.setHorizontalStretch(3);
	SWidget->setSizePolicy(size_policy);

	connect(List,SIGNAL(currentRowChanged(int)),this,SLOT(__ListClicked(int)));
	connect(SWidget,SIGNAL(currentChanged(int)),this,SLOT(__WidgetSet(int)));
	setLayout(mainlayout);
}

int pQListPagesWidget::addPage(const QString &label, QWidget *widget){
	List->addItem(label);
	return SWidget->addWidget(widget);
}

int pQListPagesWidget::addPage(QListWidgetItem *item, QWidget *widget){
	List->addItem(item);
	return SWidget->addWidget(widget);
}

int pQListPagesWidget::insertPage(int index,QListWidgetItem *item, QWidget *widget){
	List->insertItem(index,item);
	return SWidget->insertWidget(index,widget);
}

int pQListPagesWidget::insertPage(int index,const QString &label, QWidget *widget){
	List->insertItem(index,label);
	return SWidget->insertWidget(index,widget);
}
int pQListPagesWidget::currentIndex() const{
	return SWidget->currentIndex();
};
//setSizePolicy2 - It recieve 2 QSizePolicy for developer to design the UI more easy.
//the first QSizePolicy is for the QListWidget and the second one is for the QStackedWidget
void pQListPagesWidget::setSizePolicy2(const QSizePolicy &forList, const QSizePolicy &forSWidget){
	List->setSizePolicy(forList);
	SWidget->setSizePolicy(forSWidget);
}

//public slots:
void pQListPagesWidget::setCurrentIndex(int index){
	List->setCurrentRow(index);
}
void pQListPagesWidget::setCurrentItem(QListWidgetItem *item){
	List->setCurrentItem(item);
}
void pQListPagesWidget::setCurrentWidget(QWidget *widget){
	SWidget->setCurrentWidget(widget);
}
void pQListPagesWidget::removeByIndex(int index){
	int tmp=currentIndex();
	setCurrentIndex(index);
	QListWidgetItem *item=List->currentItem();
	QWidget *widget=SWidget->currentWidget();
	setCurrentIndex(tmp);
	List->removeItemWidget(item);
	SWidget->removeWidget(widget);
	delete item;
	delete widget;
}

void pQListPagesWidget::removeByItem(QListWidgetItem *item){
	int tmp=currentIndex();
	setCurrentItem(item);
	QWidget *widget=SWidget->currentWidget();
	setCurrentIndex(tmp);
	List->removeItemWidget(item);
	SWidget->removeWidget(widget);
	delete item;
	delete widget;
}

void pQListPagesWidget::removeByWidget(QWidget *widget){
	int tmp=currentIndex();
	setCurrentWidget(widget);
	QListWidgetItem *item=List->currentItem();
	setCurrentIndex(tmp);
	List->removeItemWidget(item);
	SWidget->removeWidget(widget);
	delete item;
	delete widget;
}


