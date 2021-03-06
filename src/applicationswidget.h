/***************************************************************************
 *   Copyright (C) 2007 by Bernat Ràfales,,,   *
 *   bernat@rafales-mulet.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef APPLICATIONSWINDOW_H
#define APPLICATIONSWINDOW_H

#include <QWidget>
#include "ui_applicationswidget.h"

/**
	@author Bernat Ràfales,,, <bernat@rafales-mulet.com>
*/

//Forward declarators
class ApplicationsManager;
class PSPApplication;

//Applications Controller
class ApplicationsWidget : public QWidget
{
Q_OBJECT
public:
    ApplicationsWidget(QWidget *parent = 0);
    ~ApplicationsWidget();

    void setApplications(ApplicationsManager *applications);
    
    void setPSPApplications(QList<PSPApplication> &list);
    void setComputerApplications(QList<PSPApplication> &list);
    
    void showErrorMessage(QString message);
    bool askAppOverwrite(QString appName);
    
    void setPSPSize(quint64 size);
    
private slots:
    void on_pushButtonAddAppComputer_clicked();
    void on_pushButtonAddAppPSP_clicked();
    void on_pushButtonDelAppComputer_clicked();
    void on_pushButtonDelAppPSP_clicked();
    void on_pushButtonMoveAppToPSP_clicked();
    void on_pushButtonMoveAppToComputer_clicked();

private:
    void emptyListWidget(QListWidget &list);
    bool askDelete();
    
    ApplicationsManager *m_applications;
    Ui::ApplicationsWidget m_uiApplicationsWidget;
};

#endif
