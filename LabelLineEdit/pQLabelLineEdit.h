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
#ifndef PQLABELLINEEDIT_H
#define PQLABELLINEEDIT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class pQLabelLineEdit : public QWidget
{
	Q_OBJECT
public:
	pQLabelLineEdit(const QString & Label_text, 
					const QString & LineEdit_contents,
					QWidget *parent=0);
public slots:
	void clearLabel();
	void setLabelText(const QString &);
	void setLabelNum(int);
	void setLabelNum(double);
	
	void clearLineEdit();
	void setLineEditText(const QString &);
	void selectAll();
	void undo();
	void redo();
	void paste();
	void cut();
	void copy();

signals:
	void cursorPositionChanged(int,int);
	void editingFinished();
	void returnPressed();
	void selectionChanged();
	void textChanged(const QString &);
	void textEdited(const QString &);
private:
	QLabel *Label;
	QLineEdit *LineEdit;
};

#endif
