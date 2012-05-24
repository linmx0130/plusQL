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
#include "pQDoubleListChooser.h"
pQDoubleListChooser::pQDoubleListChooser(QWidget *parent)
	:QWidget(parent)
{
	toLeft=new QPushButton("<-");
	toRight=new QPushButton("->");
	LeftList=new QListWidget;
	RightList=new QListWidget;
	//build the ui
	QHBoxLayout *mainlayout=new QHBoxLayout;
	QVBoxLayout *buttonlayout=new QVBoxLayout;
	
	QSizePolicy listsizepolicy(QSizePolicy::Preferred
					,QSizePolicy::Preferred);
	listsizepolicy.setHorizontalStretch(3);
	LeftList->setSizePolicy(listsizepolicy);
	RightList->setSizePolicy(listsizepolicy);

	buttonlayout->addWidget(toLeft);
	buttonlayout->addWidget(toRight);
	mainlayout->addWidget(LeftList);
	mainlayout->addLayout(buttonlayout);
	mainlayout->addWidget(RightList);
	//connect slots and signals
	connect(toLeft,SIGNAL(clicked()),this,SLOT(toLeftClicked()));
	connect(toRight,SIGNAL(clicked()),this,SLOT(toRightClicked()));
	connect(LeftList,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
			this,SLOT(LeftListDoubleClicked()));
	connect(RightList,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
			this,SLOT(RightListDoubleClicked()));

	setLayout(mainlayout);	
}

/*
 * movetoSide functions
 * These functions will help users to move the items.
 * They show the way to use addItem and removeItemWidget
 */

void pQDoubleListChooser::movetoRight(){
	QList<QListWidgetItem *> need_to_move=LeftList->selectedItems();
	QList<QListWidgetItem *>::iterator i=need_to_move.begin();
	for (;i!=need_to_move.end();++i){
		QListWidgetItem *newitem=new QListWidgetItem(*(*i));
		RightList->addItem(newitem);
	}
	for (i=need_to_move.begin();i!=need_to_move.end();++i){
		LeftList->removeItemWidget((*i));
		delete (*i);
		//Important: the delete sentence is necessary.
		//After "delete", the useless memory will be return to the system
		//and the item on UI will disappear.
	}
}
void pQDoubleListChooser::movetoLeft(){
	QList<QListWidgetItem *> need_to_move=RightList->selectedItems();
	QList<QListWidgetItem *>::const_iterator i=need_to_move.begin();
	for (;i!=need_to_move.end();++i){
		QListWidgetItem *newitem=new QListWidgetItem(*(*i));
		LeftList->addItem(newitem);
	}
	for (i=need_to_move.begin();i!=need_to_move.end();++i){
		RightList->removeItemWidget((*i));
		delete (*i);
	}
}

//Slots
void pQDoubleListChooser::toLeftClicked(){
	this->movetoLeft();
}
void pQDoubleListChooser::toRightClicked(){
	this->movetoRight();
}
void pQDoubleListChooser::LeftListDoubleClicked(){
	this->movetoRight();	
}
void pQDoubleListChooser::RightListDoubleClicked(){
	this->movetoLeft();	
}
