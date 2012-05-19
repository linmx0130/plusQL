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

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
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
#include "pQLabelLineEdit.h"

pQLabelLineEdit::pQLabelLineEdit(const QString & Label_text,
								 const QString & LineEdit_contents,
								 QWidget *parent)
		: QWidget(parent)
{
	this->Label=new QLabel(Label_text);
	this->LineEdit=new QLineEdit(LineEdit_contents);
	this->Label->setBuddy(LineEdit);
	QHBoxLayout *mainlayout=new QHBoxLayout;
	mainlayout->addWidget(Label);
	mainlayout->addWidget(LineEdit);

	//connect the signals
	connect(LineEdit,SIGNAL(cursorPositionChanged(int,int)),
			this,SIGNAL(cursorPositionChanged(int,int)));
	connect(LineEdit,SIGNAL(editingFinished()),
			this,SIGNAL(editingFinished()));
	connect(LineEdit,SIGNAL(returnPressed()),
			this,SIGNAL(returnPressed()));
	connect(LineEdit,SIGNAL(selectionChanged()),
			this,SIGNAL(selectionChanged()));
	connect(LineEdit,SIGNAL(textChanged(const QString &)),
			this,SIGNAL(textChanged(const QString &)));
	connect(LineEdit,SIGNAL(textEdited(const QString &)),
			this,SIGNAL(textEdited(const QString &)));
	setLayout(mainlayout);
}

//Here is all the pubic slots, in fact they only call the slots of Label 
//or LineEdit
void pQLabelLineEdit::clearLabel()
{
	this->Label->clear();
}
void pQLabelLineEdit::setLabelText(const QString & s)
{
	this->Label->setText(s);
}
void pQLabelLineEdit::setLabelNum(int num){
	this->Label->setNum(num);
}
void pQLabelLineEdit::setLabelNum(double num){
	this->Label->setNum(num);
}

void pQLabelLineEdit::clearLineEdit()
{
	this->LineEdit->clear();
}

void pQLabelLineEdit::setLineEditText(const QString &s)
{
	this->LineEdit->setText(s);
}

void pQLabelLineEdit::selectAll()
{
	this->LineEdit->selectAll();
}
void pQLabelLineEdit::undo()
{
	this->LineEdit->undo();
}
void pQLabelLineEdit::redo()
{
	this->LineEdit->redo();
}
void pQLabelLineEdit::paste()
{
	this->LineEdit->undo();
}
void pQLabelLineEdit::cut()
{
	this->LineEdit->cut();
}
void pQLabelLineEdit::copy()
{
	this->LineEdit->copy();
}
